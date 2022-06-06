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

std::shared_ptr<CMatrix> CMatrix::operator-(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Width || m_Height != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<std::vector<double>> mtx(m_Height);
    int zeroes = 0;
    double val;

    for (unsigned y = 0; y < m_Height; ++y)
        for (unsigned x = 0; x < m_Width; ++x) {
            val = at(x, y) - rhs.at(x, y);

            if (fabs(val) < 0.0001) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }

    return decider(m_Width, m_Height, zeroes, mtx);
}

std::shared_ptr<CMatrix> CMatrix::operator*(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<std::vector<double>> mtx(m_Height);
    int zeroes = 0;

    for (unsigned y = 0; y < m_Height; ++y)
        for (unsigned x = 0; x < rhs.m_Width; ++x) {
            double val = 0;

            for (unsigned k = 0; k < m_Width; ++k)
                val += at(k, y) * rhs.at(x, k);

            if (fabs(val) < 0.0001) val = 0;
            if (val == 0) zeroes++;

            mtx[y].push_back(val);
        }

    return decider(rhs.m_Width, m_Height, zeroes, mtx);
}

std::shared_ptr<CMatrix> CMatrix::merge(const CMatrix &rhs) const {
    if (m_Height != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<std::vector<double>> mtx(m_Height);
    int zeroes = 0;

    for (unsigned y = 0; y < m_Height; ++y) {
        for (unsigned x = 0; x < m_Width; ++x) {
            mtx[y].push_back(at(x, y));
            if (at(x,y) == 0) zeroes++;
        }
        for (unsigned x = 0; x < rhs.m_Width; ++x) {
            mtx[y].push_back(rhs.at(x, y));
            if (rhs.at(x, y) == 0) zeroes++;
        }
    }

    return decider(m_Width + rhs.m_Width, m_Height, zeroes, mtx);
}

std::shared_ptr<CMatrix> CMatrix::cut(unsigned w, unsigned h, unsigned ax, unsigned ay) const {
    if ((m_Width < w + ax) || (m_Height < h + ay))
        throw std::out_of_range("Incorrect input values, getting out of matrix range.");

    std::vector<std::vector<double>> mtx(h);
    int zeroes = 0;

    for (unsigned y = 0; y < h; ++y)
        for (unsigned x = 0; x < w; ++x) {
            mtx[y].push_back(at(x + ax, y + ay));
            if (at(x + ax, y + ay) == 0) zeroes++;
        }

    return decider(w, h, zeroes, mtx);
}

void CMatrix::print(std::ostream &os) const {
    for (unsigned y = 0; y < m_Height; ++y) {
        for (unsigned x = 0; x < m_Width; ++x) {
            os << std::setw(5) << at(x, y) << " ";
        }
        os << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const CMatrix &mtx) {
    mtx.print(os);
    return os;
}
