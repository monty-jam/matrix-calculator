#include "CAdj.h"
#include "CDet.h"
#include "../Operation/CTrans.h"
#include <cmath>

CAdj::CAdj(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "adj", {"RESULT", "VARIABLE"},
                   "calculate the adjugate of a given matrix"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CAdj::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CAdj>(calculator, memory);
}

void CAdj::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> mtxVar1 = m_Memory.getMatrix(argv[1]);

    unsigned width = mtxVar1->getWidth();
    unsigned height = mtxVar1->getHeight();
    unsigned zeroes = 0;

    if (width != height)
        throw std::invalid_argument("Matrix is not square.");

    std::vector<std::string> detRetv;
    detRetv.emplace_back("dummy"); // added because CDet won't print results if the retv is not empty

    std::vector<std::vector<double>> mtx(width);
    double val;

    for (unsigned y = 0; y < width; ++y)
        for (unsigned x = 0; x < width; ++x) {
            m_Memory.addMatrix(argv[0], getCofactor(mtxVar1, x, y));
            CDet::create(m_Calculator, m_Memory)->call({argv[0]}, detRetv);

            val = std::pow(-1, x + y) * std::stod(detRetv.back()); // sign of sector * determinant of current cofactor

            if (CCalculator::doubleEquals(val, 0))
                zeroes++;

            mtx[y].push_back(val);
        }

    m_Memory.addMatrix(argv[0], CMatrix::create(width, width, zeroes, mtx));
    CTrans::create(m_Calculator, m_Memory)->call({argv[0], argv[0]}, detRetv);
}

std::shared_ptr <CMatrix> CAdj::getCofactor(const std::shared_ptr<CMatrix>& mtxVar, unsigned int rx, unsigned int ry) {
    unsigned width = mtxVar->getWidth();
    unsigned zeroes = 0;
    std::vector<std::vector<double>> mtx(width - 1);
    unsigned my = 0;

    for (unsigned y = 0; y < width; ++y)
        if (y != ry) {
            for (unsigned x = 0; x < width; ++x)
                if (x != rx) {
                    mtx[my].push_back(mtxVar->at(x, y));
                    if (CCalculator::doubleEquals(mtxVar->at(x, y), 0))
                        zeroes++;
                }

            my++;
        }

    return CMatrix::create(width - 1, width - 1, zeroes, mtx);
}
