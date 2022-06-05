#include "CMemory.h"

#include <utility>

CMemory::CMemory() = default;

std::set<std::string> CMemory::getCommandNames() const {
    return m_CommandNames;
}

std::string CMemory::getCommandInfo() const {
    return m_CommandInfo;
}

const std::map<std::string, std::shared_ptr<CMatrix>> &CMemory::getMatrices() const {
    return m_Matrices;
}

void CMemory::addCommandName(const std::string &name) {
    m_CommandNames.insert(name);
}

void CMemory::addCommandInfo(const std::string& format, const std::string& helpInfo) {
    m_CommandInfo.append("\t" + format + "\n\t\t" + helpInfo + "\n");
}

void CMemory::addMatrix(const std::string &name, std::shared_ptr<CMatrix> mtx) {
    m_Matrices[name] = std::move(mtx);
}

void CMemory::deleteMatrix(const std::string &name) {
    m_Matrices.erase(name);
}
