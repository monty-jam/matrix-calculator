#include <iostream>
#include <iomanip>
#include <cmath>
#include "CMatrix.h"
#include "CMatrixDense.h"
#include "CMatrixSparse.h"

CMatrix::CMatrix(unsigned width, unsigned height, unsigned zeroes) : m_Width(width), m_Height(height),
                                                                                m_Zeroes(zeroes) {}

CMatrix::~CMatrix() = default;

std::shared_ptr<CMatrix> CMatrix::decider(unsigned width, unsigned height, unsigned zeroes,
                                        const std::vector<std::vector<double>>& mtx) {
    if (zeroes > width * height / 2)
        return std::make_shared<CMatrixSparse>(width, height, zeroes, mtx);
    else
        return std::make_shared<CMatrixDense>(width, height, zeroes, mtx);
}

std::shared_ptr<CMatrix> CMatrix::operator+(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Width || m_Height != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<std::vector<double>> mtx(m_Height);
    int zeroes = 0;
    double val;

    for (unsigned y = 0; y < m_Height; ++y)
        for (unsigned x = 0; x < m_Width; ++x) {
            val = at(x, y) + rhs.at(x, y);

            if (fabs(val) < 0.0001) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }

    return decider(m_Width, m_Height, zeroes, mtx);
}
//
//std::shared_ptr<CMatrix> CMatrix::operator-(const CMatrix &rhs) const {
//    if (m_Width != rhs.m_Width || m_Height != rhs.m_Height)
//        throw std::invalid_argument("Incorrect matrices' dimensions.");
//
//    std::vector<double> res;
//    for (unsigned int i = 0; i < m_Height; ++i)
//        for (unsigned int j = 0; i < m_Width; ++j) {
//            double value = at(j, i) - rhs.at(j, i);
//            res.push_back(value);
//        }
//
//
//    return create(res);
//}
//
//std::shared_ptr<CMatrix> CMatrix::operator*(const CMatrix &rhs) const {
//    if (m_Width != rhs.m_Height)
//        throw std::invalid_argument("Incorrect matrices' dimensions.");
//
//    std::vector<double> res;
//    for (unsigned int i = 0; i < m_Height; ++i)
//        for (unsigned int j = 0; i < m_Width; ++j) {
//            double value = 0;
//            for (unsigned int k = 0; k < rhs.m_Width; ++k)
//                value += at(i, k) * rhs.at(k, j);
//            res.push_back(value);
//        }
//    return create(res);
//}

void CMatrix::print(std::ostream &os) const {
    for (int y = 0; y < m_Height; ++y) {
        for (int x = 0; x < m_Width; ++x) {
            os << std::setw(5) << at(x, y) << " ";
        }
        os << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const CMatrix &mtx) {
    mtx.print(os);
    return os;
}