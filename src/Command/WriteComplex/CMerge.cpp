#include "CMerge.h"

CMerge::CMerge(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CMerge::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CMerge>(calculator, memory);
}

void CMerge::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 3)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto commandNames = m_Memory.getCommandNames();
    if (commandNames.find(argv[0]) != commandNames.end())
        throw std::invalid_argument("Variable can't be named as an existing command.");

    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[1]) == matrices.end()
        || matrices.find(argv[2]) == matrices.end())
        throw std::invalid_argument("Variable is not found.");
}

void CMerge::execute(const std::deque<std::string> &argv) {
    // Create result
    auto matrices = m_Memory.getMatrices();
    std::shared_ptr<CMatrix> result = matrices.at(argv[1])->merge(*matrices.at(argv[2]));

    // Backup
    m_BackupName = argv[0];
    if (matrices.find(argv[0]) != matrices.end())
        m_BackupMatrix = matrices.at(argv[0]);

    // Save result
    m_Memory.addMatrix(argv[0], result);
}

void CMerge::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CMerge::printInfo() {
    m_Memory.addCommandInfo("merge [RESULT] [VARIABLE] [VARIABLE]",
                            "merge two matrices in one.");
}