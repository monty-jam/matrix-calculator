#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "CMatrix.h"
#include "CMatrixDense.h"
#include "CMatrixSparse.h"

CMatrix::CMatrix(unsigned width, unsigned height, unsigned zeroes) : m_Width(width), m_Height(height),
                                                                                m_Zeroes(zeroes) {}

CMatrix::~CMatrix() = default;

std::shared_ptr<CMatrix> CMatrix::create(unsigned width, unsigned height, unsigned zeroes,
                                        const std::vector<std::vector<double>>& mtx) {
    if (zeroes > width * height / 2)
        return std::make_shared<CMatrixSparse>(width, height, zeroes, mtx);
    else
        return std::make_shared<CMatrixDense>(width, height, zeroes, mtx);
}

unsigned CMatrix::getWidth() const {
    return m_Width;
}

unsigned CMatrix::getHeight() const {
    return m_Height;
}

unsigned CMatrix::getZeroes() const {
    return m_Zeroes;
}

void CMatrix::print(std::ostream &os) const {
    for (unsigned y = 0; y < m_Height; ++y) {
        for (unsigned x = 0; x < m_Width; ++x) {
            os << std::setw(7) << at(x, y) << " ";
        }
        os << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const CMatrix &mtx) {
    mtx.print(os);
    return os;
}
