#include "CCut.h"

CCut::CCut(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "cut", {"RESULT", "VARIABLE", "SIZE", "SIZE", "COORDINATE", "COORDINATE"},
                   "cut matrix of desired dimensions from given matrix, starting from the given coordinates"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CCut::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CCut>(calculator, memory);
}

void CCut::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> mtxVar = m_Memory.getMatrix(argv[1]);
    unsigned width = std::stoi(argv[2]);
    unsigned height = std::stoi(argv[3]);
    unsigned ax = std::stoi(argv[4]);
    unsigned ay = std::stoi(argv[5]);

    if ((mtxVar->getWidth() < width + ax) || (mtxVar->getHeight() < height + ay))
        throw std::out_of_range("Incorrect input values, getting out of matrix range.");

    std::vector<std::vector<double>> mtx(height);
    unsigned zeroes = 0;

    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x) {
            mtx[y].push_back(mtxVar->at(x + ax, y + ay));
            if (mtxVar->at(x + ax, y + ay) == 0) zeroes++;
        }

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}