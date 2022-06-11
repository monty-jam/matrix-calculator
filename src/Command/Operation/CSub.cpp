#include "CSub.h"

CSub::CSub(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "-", {"RESULT", "VARIABLE", "VARIABLE"},
                   "subtract two matrices and save result to the variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CSub::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CSub>(calculator, memory);
}

void CSub::execute(const std::deque<std::string> &argv) {
    m_Memory.addMatrix(argv[0], *m_Memory.getMatrix(argv[1]) - *m_Memory.getMatrix(argv[2]));
}