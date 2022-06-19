#include <cmath>
#include "CSub.h"

CSub::CSub(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "-", {"RESULT", "VARIABLE", "VARIABLE"},
                   "subtract two matrices and save to the result variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CSub::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CSub>(calculator, memory);
}

void CSub::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> lhs = m_Memory.getMatrix(argv[1]);
    std::shared_ptr<CMatrix> rhs = m_Memory.getMatrix(argv[2]);

    if (lhs->getWidth() != rhs->getWidth() || lhs->getHeight() != rhs->getHeight())
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    unsigned width = lhs->getWidth();
    unsigned height = lhs->getHeight();

    std::vector<std::vector<double>> mtx(height);
    unsigned zeroes = 0;
    double val;

    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x) {
            val = lhs->at(x, y) - rhs->at(x, y);

            if (CCalculator::doubleEquals(val, 0))
                zeroes++;

            mtx[y].push_back(val);
        }

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}