#include <iostream>
#include "CHelpCmd.h"

CHelpCmd::CHelpCmd(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "help-cmd", {"COMMAND"},
                   "print information about given command"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CHelpCmd::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CHelpCmd>(calculator, memory);
}

void CHelpCmd::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::cout << *m_Calculator.getCommand(argv[0])(m_Calculator, m_Memory) << std::endl;
}