#include "CDel.h"

CDel::CDel(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "del", {"VARIABLE"},
                   "delete matrix in a given variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CDel::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CDel>(calculator, memory);
}

void CDel::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Memory.deleteMatrix(argv[0]);
}