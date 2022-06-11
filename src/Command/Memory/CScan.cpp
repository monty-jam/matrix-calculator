#include <iostream>
#include <cmath>
#include <limits>
#include "CScan.h"
#include "../../Matrix/CMatrixSparse.h"
#include "../../Matrix/CMatrixDense.h"

CScan::CScan(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "scan", {"RESULT", "SIZE", "SIZE"},
                   "scan the matrix of given dimensions from the input stream"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CScan::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CScan>(calculator, memory);
}

void CScan::execute(const std::deque<std::string> &argv) {
    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);

    std::vector<std::vector<double>> mtx(height);
    int zeroes = 0;
    double val;

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            std::cin >> val;

            if (std::cin.eof()) {
                m_Calculator.exit();
                throw std::invalid_argument("Received EOF.");
            }

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Invalid data type of the value.");
            }

            if (fabs(val) < 0.0001) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}