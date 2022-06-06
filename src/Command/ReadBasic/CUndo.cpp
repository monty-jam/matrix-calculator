#include <iostream>
#include "CUndo.h"

CUndo::CUndo(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CUndo::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CUndo>(calculator, memory);
}

void CUndo::validate(const std::deque<std::string> &argv) const {
    if (!argv.empty())
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CUndo::execute(const std::deque<std::string> &argv) {
    m_Calculator.undo();
}

void CUndo::undo() {}

void CUndo::printInfo() {
    m_Memory.addCommandInfo("help",
                            "print information about all available commands");
}