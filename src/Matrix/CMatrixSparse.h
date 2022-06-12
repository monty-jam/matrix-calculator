#ifndef SEMESTRAL_CMATRIXSPARSE_H
#define SEMESTRAL_CMATRIXSPARSE_H


#include <utility>
#include <map>
#include "CMatrix.h"

class CMatrixSparse : public CMatrix {
public:
    CMatrixSparse(unsigned width, unsigned height, unsigned zeroes, const std::vector<std::vector<double>>& mtx);

    CMatrixSparse(unsigned width, unsigned height, unsigned zeroes,
                  std::map<std::pair<unsigned, unsigned>, double> &mtx);

    void save(std::ofstream& fileOut) const override;

    double at(unsigned int x, unsigned int y) const override;

    std::shared_ptr<CMatrix> transpose() const override;

private:
    std::map<std::pair<unsigned, unsigned>, double> m_Values;
};


#endif //SEMESTRAL_CMATRIXSPARSE_H
