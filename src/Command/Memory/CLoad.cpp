#include "CLoad.h"
#include "../../Matrix/CMatrixSparse.h"
#include <fstream>
#include <climits>
#include <iostream>

CLoad::CLoad(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "load", {"RESULT", "PATH-R"},
                   "read and load matrix from given path"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CLoad::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CLoad>(calculator, memory);
}

void CLoad::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::ifstream fileRead;
    fileRead.open(argv[1]);

    std::string type;
    unsigned width = 0;
    unsigned height = 0;
    unsigned zeroes = 0;

    fileRead >> type >> width >> height;

    if ((type != "sparse" && type != "dense") || width == 0 || height == 0 || fileRead.fail() || fileRead.eof()) {
        fileRead.close();
        throw std::invalid_argument("Reading error: Incorrect header.");
    }

    std::vector<std::vector<double>> mtx(height);

    if (type == "sparse") {
        unsigned amount = 0;

        fileRead >> amount;

        if (fileRead.fail() || fileRead.eof()) {
            fileRead.close();
            throw std::invalid_argument("Reading error: Can't read amount of values in sparse matrix.");
        }
        zeroes = width * height - amount;

        // Fill mtx with zeroes.
        for (unsigned y = 0; y < height; ++y)
            for (unsigned x = 0; x < width; ++x) {
                mtx[y].push_back(0);
            }

        unsigned x, y;
        double val;
        for (unsigned i = 0; i < amount; ++i) {
            if (fileRead.eof()) {
                fileRead.close();
                throw std::invalid_argument("Reading error: Reach EOF earlier than expected.");
            }

            fileRead >> x >> y >> val;

            if (x >= width || y >= height || fileRead.fail()) {
                fileRead.close();
                throw std::invalid_argument("Reading error: Can't coordinates.");
            }

            mtx[y][x] = val;
        }

        if (!fileRead.eof()) {
            fileRead.close();
            throw std::invalid_argument("Reading error: Didn't reach EOF when was expected.");
        }

        if (zeroes <= width * height / 2)
            std::cout << "Warning: Given sparse matrix file contains dense matrix, file rewriting is recommended."
                      << std::endl;

    } else { // type == "dense"
        double val;

        for (unsigned y = 0; y < height; ++y)
            for (unsigned x = 0; x < width; ++x) {
                if (fileRead.eof()) {
                    fileRead.close();
                    throw std::invalid_argument("Reading error: Reach EOF earlier than expected.");
                }

                fileRead >> val;

                if (fileRead.fail()) {
                    fileRead.close();
                    throw std::invalid_argument("Reading error: Can't read matrix value.");
                }

                if (CCalculator::doubleEquals(val, 0))
                    zeroes++;
                mtx[y].push_back(val);
            }

        if (!fileRead.eof()) {
            fileRead.close();
            throw std::invalid_argument("Reading error: Didn't reach EOF when was expected.");
        }

        if (zeroes > width * height / 2)
            std::cout << "Warning: Given dense matrix file contains sparse matrix, file rewriting is recommended."
                      << std::endl;
    }

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
    fileRead.close();
}