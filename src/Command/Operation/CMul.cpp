#include "CMul.h"

CMul::CMul(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "*", {"RESULT", "VARIABLE", "VARIABLE"},
                   "multiply two matrices and save result to the variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CMul::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CMul>(calculator, memory);
}

void CMul::execute(const std::deque<std::string> &argv) {
    m_Memory.addMatrix(argv[0], *m_Memory.getMatrix(argv[1]) * *m_Memory.getMatrix(argv[2]));
}