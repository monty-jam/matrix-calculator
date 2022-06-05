#include "CMatrixDense.h"

#include <utility>

CMatrixDense::CMatrixDense(unsigned int width, unsigned int height, unsigned int zeroes,
                           std::vector<std::vector<double>> mtx) : CMatrix(width, height, zeroes),
                                                                   m_Values(std::move(mtx)) {}

double CMatrixDense::at(unsigned int x, unsigned int y) const {
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
        throw std::out_of_range("Coordinate is out of matrix range.");

    return m_Values[y][x];
}

