#include <iostream>
#include <deque>
#include "CHelp.h"

CHelp::CHelp(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CHelp::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CHelp>(calculator, memory);
}

void CHelp::validate(const std::deque<std::string> &argv) const {
    if (!argv.empty())
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CHelp::execute(const std::deque<std::string> &argv) {
    std::cout << m_Memory.getCommandInfo() << std::endl;
}

void CHelp::undo() {}

void CHelp::printInfo() {
    m_Memory.addCommandInfo("help",
                          "print information about all available commands");
}
