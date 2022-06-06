#include <iostream>
#include "CPrint.h"

CPrint::CPrint(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CPrint::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CPrint>(calculator, memory);
}

void CPrint::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 1)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[0]) == matrices.end())
        throw std::invalid_argument("Variable is not found.");
}

void CPrint::execute(const std::deque<std::string> &argv) {
    auto matrices = m_Memory.getMatrices();
    std::cout << *matrices.at(argv[0]);
}

void CPrint::undo() {}

void CPrint::printInfo() {
    m_Memory.addCommandInfo("print [VARIABLE]",
                            "print matrix stored in given variable.");
}
