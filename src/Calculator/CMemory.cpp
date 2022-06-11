#include "CMemory.h"

#include <utility>

CMemory::CMemory() = default;

std::set<std::string> CMemory::getCommandNames() const {
    return m_CommandNames;
}

bool CMemory::doesCommandNameExist(const std::string &name) const {
    if (m_CommandNames.find(name) != m_CommandNames.end())
        return true;
    else
        return false;
}

std::vector<std::string> CMemory::getMatrixNames() const {
    std::vector<std::string> result;
    for (const auto& matrix : m_Matrices)
        result.push_back(matrix.first);
    return result;
}

bool CMemory::doesMatrixExist(const std::string &name) const {
    if (m_Matrices.find(name) != m_Matrices.end())
        return true;
    else
        return false;
}

std::shared_ptr<CMatrix> CMemory::getMatrix(const std::string &name) const {
    return m_Matrices.at(name);
}

void CMemory::addCommandName(const std::string &name) {
    m_CommandNames.insert(name);
}

void CMemory::addMatrix(const std::string &name, std::shared_ptr<CMatrix> mtx) {
    m_Matrices[name] = std::move(mtx);
}

void CMemory::deleteMatrix(const std::string &name) {
    m_Matrices.erase(name);
}
