#ifndef SEMESTRAL_CMATRIXDENSE_H
#define SEMESTRAL_CMATRIXDENSE_H


#include <vector>
#include <memory>
#include "CMatrix.h"

class CMatrixDense : public CMatrix {
public:
    CMatrixDense(unsigned int width, unsigned int height) : CMatrix(width, height) {} ;
    double at(unsigned int x, unsigned int y) const override;
    virtual std::shared_ptr<CMatrix> create(std::vector<double> values) const override;

    std::shared_ptr<CMatrix> Transpose() const override;
    std::shared_ptr<CMatrix> Merge(const CMatrix &rhs) const override;

    void print(std::ostream &os) override;

private:
    std::vector<std::vector<double>> m_Values;
};


#endif //SEMESTRAL_CMATRIXDENSE_H
