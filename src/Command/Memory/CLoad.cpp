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
    std::ifstream fileIn;
    fileIn.open(argv[1]);

    std::string type;
    unsigned width = 0;
    unsigned height = 0;

    fileIn >> type >> width >> height;

    if (fileIn.fail() || fileIn.eof() || (type != "sparse" && type != "dense") || width == 0 || height == 0) {
        fileIn.close();
        throw std::invalid_argument("Reading file data error.");
    }

    if (type == "sparse") {
        unsigned amount = 0;

        fileIn >> amount;

        if (fileIn.fail() || fileIn.eof()) {
            fileIn.close();
            throw std::invalid_argument("Reading file data error.");
        }

        std::vector<std::vector<double>> mtx(height);
        for (unsigned y = 0; y < height; ++y)
            for (unsigned x = 0; x < width; ++x) {
                mtx[y].push_back(0);
            }

        unsigned x, y;
        double val;
        for (int i = 0; i < amount; ++i) {
            fileIn >> x >> y >> val;

            if (x >= width || y >= height || fileIn.fail() || fileIn.eof()) {
                fileIn.close();
                throw std::invalid_argument("Reading file data error.");
            }

            mtx[y][x] = val;
        }

        std::string end;
        fileIn >> end;

        if (fileIn.fail() || end != "end") {
            fileIn.close();
            throw std::invalid_argument("Reading file data error.");
        }

        m_Memory.addMatrix(argv[0], CMatrix::create(width, height, width * height - amount, mtx));

    } else { // type == "dense"
        double val;
        unsigned zeroes = 0;
        std::vector<std::vector<double>> mtx(height);

        for (unsigned y = 0; y < height; ++y)
            for (unsigned x = 0; x < width; ++x) {
                fileIn >> val;

                if (fileIn.fail() || fileIn.eof()) {
                    fileIn.close();
                    throw std::invalid_argument("Reading file data error.");
                }

                if (val == 0)
                    zeroes++;
                mtx[y].push_back(val);
            }

        std::string end;
        fileIn >> end;

        if (fileIn.fail() || end != "end") {
            fileIn.close();
            throw std::invalid_argument("Reading file data error.");
        }

        m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));

    }
    fileIn.close();
}