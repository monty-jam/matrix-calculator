#include "CSave.h"
#include <fstream>

CSave::CSave(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "save", {"VARIABLE", "PATH-W"},
                   "save matrix in the file in given path"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CSave::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CSave>(calculator, memory);
}

void CSave::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Memory.getMatrix(argv[0])->save(argv[1]);
}