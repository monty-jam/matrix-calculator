#include <cmath>
#include "CMul.h"

CMul::CMul(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "*", {"RESULT", "VARIABLE", "VARIABLE"},
                   "multiply two matrices and save result to the variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CMul::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CMul>(calculator, memory);
}

void CMul::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> lhs = m_Memory.getMatrix(argv[1]);
    std::shared_ptr<CMatrix> rhs = m_Memory.getMatrix(argv[2]);

    if (lhs->getWidth() != rhs->getHeight())
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    unsigned width = rhs->getWidth();
    unsigned height = lhs->getHeight();

    std::vector<std::vector<double>> mtx(height);
    unsigned zeroes = 0;

    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x) {
            double val = 0;

            for (unsigned k = 0; k < lhs->getWidth(); ++k)
                val += lhs->at(k, y) * rhs->at(x, k);

            if (fabs(val) < 0.0001) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}