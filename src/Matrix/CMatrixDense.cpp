#include "CMatrixDense.h"

#include <utility>

CMatrixDense::CMatrixDense(unsigned int width, unsigned int height, unsigned int zeroes,
                           std::vector<std::vector<double>> mtx) : CMatrix(width, height, zeroes),
                                                                   m_Values(std::move(mtx)) {}
