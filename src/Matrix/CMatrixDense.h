#ifndef SEMESTRAL_CMATRIXDENSE_H
#define SEMESTRAL_CMATRIXDENSE_H


#include <vector>
#include <memory>
#include "CMatrix.h"

class CMatrixDense : public CMatrix {
public:
    CMatrixDense(unsigned width, unsigned height, unsigned zeroes, std::vector<std::vector<double>> mtx);

    void save(std::ofstream& fileOut) const override;

    double at(unsigned int x, unsigned int y) const override;

    std::shared_ptr<CMatrix> transpose() const override;

private:
    std::vector<std::vector<double>> m_Values;
};


#endif //SEMESTRAL_CMATRIXDENSE_H
