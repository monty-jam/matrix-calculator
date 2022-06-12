#include <iostream>
#include "CUndo.h"

CUndo::CUndo(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "undo", {},
                   "return program's memory to the previous state"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CUndo::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CUndo>(calculator, memory);
}

void CUndo::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Calculator.undo();
}