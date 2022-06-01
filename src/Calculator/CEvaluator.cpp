#include "CEvaluator.h"

#include <utility>

void CEvaluator::Insert(const std::string &name, std::shared_ptr<CMatrix> mtx) {
    m_Matrices[name] = std::move(mtx);
}

void CEvaluator::Delete(const std::string &name) {
    m_Matrices.erase(name);
}

void CEvaluator::Add(const std::string &name, const std::string &lhs, const std::string &rhs) {
    Insert(name, *m_Matrices.at(lhs) +  *m_Matrices.at(rhs));
}

void CEvaluator::Subtract(const std::string &name, const std::string &lhs, const std::string &rhs) {
    Insert(name, *m_Matrices.at(lhs) -  *m_Matrices.at(rhs));
}

void CEvaluator::Multiply(const std::string &name, const std::string &lhs, const std::string &rhs) {
    Insert(name, *m_Matrices.at(lhs) *  *m_Matrices.at(rhs));
}
