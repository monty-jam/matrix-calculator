#include <iostream>
#include "CExit.h"

CExit::CExit(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CExit::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CExit>(calculator, memory);
}

void CExit::validate(const std::deque<std::string> &argv) const {
    if (!argv.empty())
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CExit::execute(const std::deque<std::string> &argv) {
    m_Calculator.exit();
}

void CExit::undo() {}

void CExit::printInfo() {
    m_Memory.addCommandInfo("exit",
                          "close the program");
}