#include <iostream>
#include "CDet.h"
#include "CGem.h"
#include "../Basic/CDel.h"

CDet::CDet(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "det", {"VARIABLE"},
                   "return the determinant of a given matrix"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CDet::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CDet>(calculator, memory);
}

void CDet::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    unsigned width = m_Memory.getMatrix(argv[0])->getWidth();
    unsigned height = m_Memory.getMatrix(argv[0])->getHeight();

    if (width != height)
        throw std::invalid_argument("Matrix is not square.");

    std::vector<std::string> gemRetv;
    CGem::create(m_Calculator, m_Memory)->call({"~det", argv[0]}, gemRetv);

    double determinant = std::stod(gemRetv[0]); // sign of determinant
    std::shared_ptr<CMatrix> mtx = m_Memory.getMatrix("~det");

    for (unsigned x = 0; x < width; ++x)
        determinant *= mtx->at(x, x);

    if (retv.empty()) // other commands call CDet with a non-empty retv vector,
        // so that it won't print the value, only
        std::cout << "Determinant: " << determinant << std::endl;
    retv.push_back(std::to_string(determinant));

    CDel::create(m_Calculator, m_Memory)->call({"~det"}, gemRetv);
}