#include "CAdd.h"

CAdd::CAdd(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CAdd::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CAdd>(calculator, memory);
}

void CAdd::validate(const std::deque<std::string> &argv) const {
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

void CAdd::execute(const std::deque<std::string> &argv) {
    // Create result
    auto matrices = m_Memory.getMatrices();
    std::shared_ptr<CMatrix> result = *matrices.at(argv[1]) + *matrices.at(argv[2]);

    // Backup
    m_BackupName = argv[0];
    if (matrices.find(argv[0]) != matrices.end())
        m_BackupMatrix = matrices.at(argv[0]);

    // Save result
    m_Memory.addMatrix(argv[0], result);
}

void CAdd::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CAdd::printInfo() {
    m_Memory.addCommandInfo("+ [RESULT] [VARIABLE] [VARIABLE]",
                            "add two matrices and save result to the variable.");
}

