#include <iostream>
#include "CExit.h"

CExit::CExit(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "exit", {},
                   "close the program"),
             m_Calculator(calculator) {}

std::shared_ptr<CCommand> CExit::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CExit>(calculator, memory);
}

void CExit::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Calculator.exit();
}