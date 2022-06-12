#include "CCommand.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <cmath>

CCommand::CCommand(CMemory &memory, std::string name, std::vector<std::string> argFormat, std::string helpInfo) :
                    m_Memory(memory), m_Name(std::move(name)),
                    m_ArgFormat(std::move(argFormat)), m_HelpInfo(std::move(helpInfo)) {
    m_IsWrite = (!m_ArgFormat.empty() && m_ArgFormat[0] == "RESULT")
            || m_Name == "del";
}

CCommand::~CCommand() = default;

void CCommand::call(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    validate(argv);
    backup(argv);
    execute(argv, retv);
}

bool CCommand::isWrite() const {
    return m_IsWrite;
}

void CCommand::undo() {
    if (!m_IsWrite)
        return;

    if (!m_BackupMatrix)
        m_Memory.deleteMatrix(m_BackupName);
    else
        m_Memory.addMatrix(m_BackupName, m_BackupMatrix);
}

std::string CCommand::randomName() const {
    return std::string();
}

void CCommand::validate(const std::deque<std::string> &argv) const {
    unsigned size = m_ArgFormat.size();
    if (argv.size() != size)
        throw std::invalid_argument("Invalid amount of arguments.");

    for (unsigned i = 0; i < size; ++i) {
        if (m_ArgFormat[i] == "COMMAND") {
            if (!m_Memory.doesCommandNameExist(argv[i]))
                throw std::invalid_argument("Command does not exist.");

        } else if (m_ArgFormat[i] == "RESULT") {
            if (m_Memory.doesCommandNameExist(argv[i]))
                throw std::invalid_argument("Variable can't be named as an existing command.");

        } else if (m_ArgFormat[i] == "VARIABLE") {
            if (!m_Memory.doesMatrixExist(argv[i]))
                throw std::invalid_argument("Variable is not found.");

        } else if (m_ArgFormat[i] == "SIZE") {
            double val = std::stod(argv[i]);
            if (floor(val) != ceil(val))
                throw std::invalid_argument("Size value is not int.");
            if (val <= 0)
                throw std::invalid_argument("Size value is less than or equals to 0.");

        } else if (m_ArgFormat[i] == "COORDINATE") {
            double val = std::stod(argv[i]);
            if (floor(val) != ceil(val))
                throw std::invalid_argument("Coordinate value is not int.");
            if (val < 0)
                throw std::invalid_argument("Coordinate value is less than 0.");

        } else if (m_ArgFormat[i] == "PATH-W") {
            std::ofstream file;
            file.open(argv[i]);
            if (!file.is_open())
                throw std::invalid_argument("Don't have permission to create/open given file path.");
            else
                file.close();

        } else if (m_ArgFormat[i] == "PATH-R") {
            std::ifstream file;
            file.open(argv[i]);
            if (!file.is_open())
                throw std::invalid_argument("Don't have permission to read from given file path.");
            else
                file.close();

        } else {
            throw std::invalid_argument("Used command contains an incorrect argument format data.");
        }

    }
}

void CCommand::backup(const std::deque<std::string> &argv) {
    if (!m_IsWrite)
        return;

    m_BackupName = argv[0];
    if (m_Memory.doesMatrixExist(m_BackupName))
        m_BackupMatrix = m_Memory.getMatrix(m_BackupName);
}

void CCommand::print(std::ostream &os) const {
    os << "\t" << m_Name << " ";
    for (const auto& arg : m_ArgFormat)
        os << "[" << arg << "] ";
    os << std::endl;
    os << "\t\t" << m_HelpInfo << std::endl;
}

std::ostream &operator<<(std::ostream &os, const CCommand &cmd) {
    cmd.print(os);
    return os;
}

