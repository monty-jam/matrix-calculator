#include <iostream>
#include "CVars.h"

CVars::CVars(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CVars::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CVars>(calculator, memory);
}

void CVars::validate(const std::deque<std::string> &argv) const {
    if (!argv.empty())
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CVars::execute(const std::deque<std::string> &argv) {
    auto matrices = m_Memory.getMatrices();

    if (matrices.empty()) {
        std::cout << "No variables to show." << std::endl;
        return;
    }

    for (const auto& var : m_Memory.getMatrices()) {
        std::cout << var.first << "  ";
    }
    std::cout << std::endl;
}

void CVars::undo() {}

void CVars::printInfo() {
    m_Memory.addCommandInfo("vars",
                          "print all stored variables");
}