#ifndef SEMESTRAL_CMATRIXSPARSE_H
#define SEMESTRAL_CMATRIXSPARSE_H


#include <utility>
#include <map>
#include "CMatrix.h"

class CMatrixSparse : public CMatrix {
public:
    CMatrixSparse(unsigned width, unsigned height, unsigned zeroes, const std::vector<std::vector<double>>& mtx);
//    double at(unsigned int x, unsigned int y) const override;
//    std::shared_ptr<CMatrix> create(std::vector<double> values) const override;
//
//    std::shared_ptr<CMatrix> Transpose() const override;
//    std::shared_ptr<CMatrix> Merge(const CMatrix &rhs) const override;
//
//    void print(std::ostream &os) override;

private:
    std::map<std::pair<unsigned, unsigned>, double> m_Values;
};


#endif //SEMESTRAL_CMATRIXSPARSE_H
