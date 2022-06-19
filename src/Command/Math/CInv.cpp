#include "CInv.h"
#include "CDet.h"
#include "../Operation/CTrans.h"
#include "CAdj.h"
#include <cmath>
#include <iostream>

CInv::CInv(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "inv", {"RESULT", "VARIABLE"},
                   "calculate the inverse of a given matrix"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CInv::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CInv>(calculator, memory);
}

void CInv::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> mtxVar1 = m_Memory.getMatrix(argv[1]);

    unsigned width = mtxVar1->getWidth();
    unsigned height = mtxVar1->getHeight();
    unsigned zeroes = mtxVar1->getZeroes();

    if (width != height)
        throw std::invalid_argument("Matrix is not square.");

    std::vector<std::string> detRetv;
    detRetv.emplace_back("dummy"); // added because CDet won't print results if the retv is not empty

    CDet::create(m_Calculator, m_Memory)->call({argv[1]}, detRetv);
    double determinant = std::stod(detRetv.back());

    if (CCalculator::doubleEquals(determinant, 0))
        throw std::invalid_argument("Determinant equals to zero.");

    CAdj::create(m_Calculator, m_Memory)->call({argv[0], argv[1]}, detRetv);


    std::vector<std::vector<double>> mtx(width);
    for (unsigned y = 0; y < width; ++y)
        for (unsigned x = 0; x < width; ++x)
            mtx[y].push_back(m_Memory.getMatrix(argv[0])->at(x,y) / determinant);

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}