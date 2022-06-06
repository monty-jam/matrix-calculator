#include "CTrans.h"

CTrans::CTrans(CCalculator& calculator, CMemory& memory)
        : m_Calculator(calculator), m_Memory(memory) {}

std::shared_ptr<CCommand> CTrans::create(CCalculator& calculator, CMemory& memory) {
    return std::make_shared<CTrans>(calculator, memory);
}

void CTrans::validate(const std::deque<std::string> &argv) const {
    if (argv.size() != 2)
        throw std::invalid_argument("Invalid amount of arguments.");

    auto commandNames = m_Memory.getCommandNames();
    if (commandNames.find(argv[0]) != commandNames.end())
        throw std::invalid_argument("Variable can't be named as an existing command.");

    auto matrices = m_Memory.getMatrices();
    if (matrices.find(argv[1]) == matrices.end())
        throw std::invalid_argument("Variable is not found.");
}

void CTrans::execute(const std::deque<std::string> &argv) {
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

void CTrans::undo() {
    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

void CTrans::printInfo() {
    m_Memory.addCommandInfo("T [RESULT] [VARIABLE]",
                            "transpose given matrix and save result to the variable.");
}