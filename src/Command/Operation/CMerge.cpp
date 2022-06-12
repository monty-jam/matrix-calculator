#include "CMerge.h"

CMerge::CMerge(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "merge", {"RESULT", "VARIABLE", "VARIABLE"},
                   "merge two matrices in one horizontally"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CMerge::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CMerge>(calculator, memory);
}

void CMerge::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    m_Memory.addMatrix(argv[0], m_Memory.getMatrix(argv[1])->merge(*m_Memory.getMatrix(argv[2])));
}