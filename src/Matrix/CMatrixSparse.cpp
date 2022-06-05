#include "CMatrixSparse.h"

CMatrixSparse::CMatrixSparse(unsigned int width, unsigned int height, unsigned int zeroes,
                             const std::vector<std::vector<double>>& matrix) : CMatrix(width, height, zeroes) {
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            if (matrix[y][x] != 0)
                m_Values.emplace(std::make_pair(x, y), matrix[y][x]);
}

double CMatrixSparse::at(unsigned int x, unsigned int y) const {
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
        throw std::out_of_range("Coordinate is out of matrix range.");

    if (m_Values.find(std::make_pair(x, y)) != m_Values.end())
        return m_Values.at(std::make_pair(x, y));
    else
        return 0;
}

