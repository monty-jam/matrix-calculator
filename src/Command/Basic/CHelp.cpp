#include <iostream>
#include <deque>
#include "CHelp.h"

CHelp::CHelp(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "help", {},
                   "print information about all available commands"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CHelp::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CHelp>(calculator, memory);
}

void CHelp::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    for (const auto& command : m_Memory.getCommandNames())
        std::cout << *m_Calculator.getCommand(command)(m_Calculator, m_Memory) << std::endl;
}
