#include "CTrans.h"

CTrans::CTrans(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "T", {"RESULT", "VARIABLE"},
                   "transpose given matrix and save result to the variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CTrans::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CTrans>(calculator, memory);
}

void CTrans::execute(const std::deque<std::string> &argv) {
    m_Memory.addMatrix(argv[0], m_Memory.getMatrix(argv[1])->transpose());
}