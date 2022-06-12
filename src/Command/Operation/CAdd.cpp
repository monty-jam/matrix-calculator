#include "CAdd.h"

CAdd::CAdd(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "+", {"RESULT", "VARIABLE", "VARIABLE"},
                   "add two matrices and save result to the variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CAdd::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CAdd>(calculator, memory);
}

void CAdd::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Memory.addMatrix(argv[0], *m_Memory.getMatrix(argv[1]) + *m_Memory.getMatrix(argv[2]));
}

