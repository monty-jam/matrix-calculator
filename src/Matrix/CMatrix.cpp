#include "CMatrix.h"

std::shared_ptr<CMatrix> CMatrix::operator+(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Width || m_Height != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<double> res;
    for (unsigned int i = 0; i < m_Height; ++i)
        for (unsigned int j = 0; i < m_Width; ++j) {
            double value = at(j, i) + rhs.at(j, i);
            res.push_back(value);
        }


    return create(res);
}

std::shared_ptr<CMatrix> CMatrix::operator-(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Width || m_Height != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<double> res;
    for (unsigned int i = 0; i < m_Height; ++i)
        for (unsigned int j = 0; i < m_Width; ++j) {
            double value = at(j, i) - rhs.at(j, i);
            res.push_back(value);
        }


    return create(res);
}

std::shared_ptr<CMatrix> CMatrix::operator*(const CMatrix &rhs) const {
    if (m_Width != rhs.m_Height)
        throw std::invalid_argument("Incorrect matrices' dimensions.");

    std::vector<double> res;
    for (unsigned int i = 0; i < m_Height; ++i)
        for (unsigned int j = 0; i < m_Width; ++j) {
            double value = 0;
            for (unsigned int k = 0; k < rhs.m_Width; ++k)
                value += at(i, k) * rhs.at(k, j);
            res.push_back(value);
        }
    return create(res);
}
