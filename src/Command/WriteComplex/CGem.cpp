#include "CGem.h"

CGem::CGem(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CGem::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CGem>(calculator, memory);
}

void CGem::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 2)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto commandNames = m_Memory.getCommandNames();
    if (commandNames.find(argv[0]) != commandNames.end())
        throw std::invalid_argument("Variable can't be named as an existing command.");

    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[1]) == matrices.end())
        throw std::invalid_argument("Variable is not found.");
}

void CGem::execute(const std::deque<std::string> &argv) {
    // Create result
    auto matrices = m_Memory.getMatrices();
    std::shared_ptr<CMatrix> result = matrices.at(argv[1])->transpose();

    // Backup
    m_BackupName = argv[0];
    if (matrices.find(argv[0]) != matrices.end())
        m_BackupMatrix = matrices.at(argv[0]);

    // Save result
    m_Memory.addMatrix(argv[0], result);
}

void CGem::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CGem::printInfo() {
    m_Memory.addCommandInfo("gem [RESULT] [VARIABLE]",
                            "perform Gaussian elimination on a given variable and save to the result.");
}