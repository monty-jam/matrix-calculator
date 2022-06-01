#ifndef SEMESTRAL_CEVALUATOR_H
#define SEMESTRAL_CEVALUATOR_H


#include <map>
#include <memory>
#include "../Matrix/CMatrix.h"

class CEvaluator {
public:
    CEvaluator() {}
    void Insert(const std::string &name, std::shared_ptr<CMatrix> mtx);
    void Delete(const std::string &name);
    void Print(const std::string &name) const;

    void Add(const std::string &name, const std::string &lhs, const std::string &rhs);
    void Subtract(const std::string &name, const std::string &lhs, const std::string &rhs);
    void Multiply(const std::string &name, const std::string &lhs, const std::string &rhs);
    void Transpose(const std::string &name);
    void Merge(const std::string &name, const std::string &lhs, const std::string &rhs);
    void Cut(const std::string &name, unsigned int w, unsigned int h, unsigned int x, unsigned int y);
    void Inverse(const std::string &name);
    void Determinant(const std::string &name);
    void Rank(const std::string &name);
    void GEM(const std::string &name);
    void GEMDetailed (const std::string &name);

    void saveToFile(const std::string &name, const std::string &path) const;
    void readFromFile(const std::string &name, const std::string &path);

private:
    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;
};


#endif //SEMESTRAL_CEVALUATOR_H
