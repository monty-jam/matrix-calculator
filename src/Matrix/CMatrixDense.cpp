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

std::shared_ptr<CMatrix> CMatrixDense::transpose() const {
    std::vector<std::vector<double>> mtx(m_Width);

    for (unsigned  x = 0; x < m_Width; ++x)
        for (unsigned y = 0; y < m_Height; ++y) {
            mtx[x].push_back(at(x,y));
        }

    return std::make_shared<CMatrixDense>(m_Height, m_Width, m_Zeroes, mtx);
}

