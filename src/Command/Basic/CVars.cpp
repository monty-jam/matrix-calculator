#include <iostream>
#include "CVars.h"

CVars::CVars(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "vars", {},
                   "print all stored variables"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CVars::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CVars>(calculator, memory);
}

void CVars::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::vector<std::string> variables = m_Memory.getMatrixNames();

    if (variables.empty()) {
        std::cout << "No variables to show." << std::endl;
        return;
    }

    for (const auto& var : variables) {
        std::cout << var << "  ";
    }
    std::cout << std::endl;
}