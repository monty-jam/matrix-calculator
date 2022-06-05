#include "CMemory.h"

CMemory::CMemory() = default;

std::string CMemory::getCommandInfo() const {
    return m_CommandInfo;
}

void CMemory::addCommandName(const std::string &name) {
    m_CommandNames.insert(name);
}

void CMemory::addCommandInfo(const std::string& format, const std::string& helpInfo) {
    m_CommandInfo.append("\t" + format + "\n\t\t" + helpInfo + "\n");
}

const std::map<std::string, std::shared_ptr<CMatrix>> &CMemory::getMatrices() const {
    return m_Matrices;
}
