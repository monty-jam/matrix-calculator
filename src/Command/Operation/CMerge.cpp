#include "CMerge.h"

CMerge::CMerge(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "merge", {"RESULT", "VARIABLE", "VARIABLE"},
                   "merge two matrices in one horizontally"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CMerge::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CMerge>(calculator, memory);
}

void CMerge::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> lhs = m_Memory.getMatrix(argv[1]);
    std::shared_ptr<CMatrix> rhs = m_Memory.getMatrix(argv[2]);

    if (lhs->getHeight() != rhs->getHeight())
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    unsigned height = lhs->getHeight();

    std::vector<std::vector<double>> mtx(height);
    unsigned zeroes = 0;

    for (unsigned y = 0; y < height; ++y) {
        for (unsigned x = 0; x < lhs->getWidth(); ++x) {
            mtx[y].push_back(lhs->at(x, y));
            if (CCalculator::doubleEquals(lhs->at(x,y), 0)) zeroes++;
        }
        for (unsigned x = 0; x < rhs->getWidth(); ++x) {
            mtx[y].push_back(rhs->at(x, y));
            if (CCalculator::doubleEquals(rhs->at(x,y), 0)) zeroes++;
        }
    }

    m_Memory.addMatrix(argv[0], CMatrix::create(lhs->getWidth() + rhs->getWidth(), height, zeroes, mtx));
}