#include <iostream>
#include "CRank.h"
#include "CGem.h"
#include "../Basic/CDel.h"

CRank::CRank(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "rank", {"VARIABLE"},
                   "return the rank of a given matrix"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CRank::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CRank>(calculator, memory);
}

void CRank::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::vector<std::string> gemRetv;
    CGem::create(m_Calculator, m_Memory)->call({"~rank", argv[0]}, gemRetv);

    std::cout << "Rank: " << gemRetv[1] << std::endl; // rank

    CDel::create(m_Calculator, m_Memory)->call({"~rank"}, gemRetv);
}