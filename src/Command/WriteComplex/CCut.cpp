#include "CCut.h"

CCut::CCut(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CCut::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CCut>(calculator, memory);
}

void CCut::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 6)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto commandNames = m_Memory.getCommandNames();
    if (commandNames.find(argv[0]) != commandNames.end())
        throw std::invalid_argument("Variable can't be named as an existing command.");

    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[1]) == matrices.end())
        throw std::invalid_argument("Variable is not found.");

    int w = std::stoi(argv[2]);
    int h = std::stoi(argv[3]);
    int x = std::stoi(argv[4]);
    int y = std::stoi(argv[5]);

    if (w <= 0 || h <= 0 || x < 0 || y < 0)
        throw std::invalid_argument("Incorrect matrix dimensions/coordinates.");
}

void CCut::execute(const std::deque<std::string> &argv) {
    int w = std::stoi(argv[2]);
    int h = std::stoi(argv[3]);
    int x = std::stoi(argv[4]);
    int y = std::stoi(argv[5]);

    // Create result
    auto matrices = m_Memory.getMatrices();
    std::shared_ptr<CMatrix> result = matrices.at(argv[1])->cut(w, h, x, y);

    // Backup
    m_BackupName = argv[0];
    if (matrices.find(argv[0]) != matrices.end())
        m_BackupMatrix = matrices.at(argv[0]);

    // Save result
    m_Memory.addMatrix(argv[0], result);
}

void CCut::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CCut::printInfo() {
    m_Memory.addCommandInfo("cut [RESULT] [VARIABLE] [WIDTH] [HEIGHT] [X] [Y]",
                            "cut matrix of desired dimensions from given matrix, starting from the given coordinates");
}