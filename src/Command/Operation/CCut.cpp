#include "CCut.h"

CCut::CCut(CCalculator& calculator, CMemory& memory)
        : CCommand(memory,
                   "cut", {"RESULT", "VARIABLE", "SIZE", "SIZE", "COORDINATE", "COORDINATE"},
                   "cut matrix of desired dimensions from given matrix, starting from the given coordinates"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CCut::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CCut>(calculator, memory);
}

void CCut::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    unsigned w = std::stoi(argv[2]);
    unsigned h = std::stoi(argv[3]);
    unsigned x = std::stoi(argv[4]);
    unsigned y = std::stoi(argv[5]);

    m_Memory.addMatrix(argv[0], m_Memory.getMatrix(argv[1])->cut(w, h, x, y));
}