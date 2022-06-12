#include <iostream>
#include "CPrint.h"

CPrint::CPrint(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "print", {"VARIABLE"},
                   "print matrix stored in given variable"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CPrint::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CPrint>(calculator, memory);
}

void CPrint::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::cout << *m_Memory.getMatrix(argv[0]);
}
