#include <iostream>
#include <cmath>
#include <limits>
#include "CScan.h"
#include "../../Matrix/CMatrixSparse.h"
#include "../../Matrix/CMatrixDense.h"

CScan::CScan(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CScan::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CScan>(calculator, memory);
}

void CScan::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 3)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto commandNames = m_Memory.getCommandNames();
    if (commandNames.find(argv[0]) != commandNames.end())
        throw std::invalid_argument("Variable can't be named as an existing command.");

    int width = std::stoi(argv[1]);
    int height = std::stoi(argv[2]);

    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Incorrect matrix dimensions.");
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

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::invalid_argument("Invalid data type of the value.");
            }

            if (fabs(val) < 0.01) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create result
    std::shared_ptr<CMatrix> result;
    if (zeroes > width * height / 2)
        result = std::make_shared<CMatrixSparse>(width, height, zeroes, mtx);
    else
        result = std::make_shared<CMatrixDense>(width, height, zeroes, mtx);

    // Backup
    m_BackupName = argv[0];
    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[0]) != matrices.end())
        m_BackupMatrix = matrices.at(argv[0]);

    // Save result
    m_Memory.addMatrix(argv[0], result);
}

void CScan::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CScan::printInfo() {
    m_Memory.addCommandInfo("scan [RESULT] [WIDTH] [HEIGHT]",
                            "scan the matrix of given dimensions from the input stream.");
}