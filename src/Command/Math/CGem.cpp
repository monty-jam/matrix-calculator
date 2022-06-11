#include "CGem.h"

CGem::CGem(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "gem", {"RESULT", "VARIABLE"},
                   "perform Gaussian elimination on a given variable and save to the result"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CGem::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CGem>(calculator, memory);
}

void CGem::execute(const std::deque<std::string> &argv) {

}