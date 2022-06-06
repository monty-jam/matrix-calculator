#include "CMatrixSparse.h"

CMatrixSparse::CMatrixSparse(unsigned int width, unsigned int height, unsigned int zeroes,
                             const std::vector<std::vector<double>>& matrix) : CMatrix(width, height, zeroes) {
    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x)
            if (matrix[y][x] != 0)
                m_Values.emplace(std::make_pair(x, y), matrix[y][x]);
}

CMatrixSparse::CMatrixSparse(unsigned width, unsigned height, unsigned zeroes,
                             std::map<std::pair<unsigned, unsigned>, double>& matrix) : CMatrix(width, height, zeroes),
                             m_Values(matrix) {}

double CMatrixSparse::at(unsigned int x, unsigned int y) const {
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height)
        throw std::out_of_range("Coordinate is out of matrix range.");

    if (m_Values.find(std::make_pair(x, y)) != m_Values.end())
        return m_Values.at(std::make_pair(x, y));
    else
        return 0;
}

std::shared_ptr<CMatrix> CMatrixSparse::transpose() const {
    std::map<std::pair<unsigned, unsigned>, double> result;

    for (auto value : m_Values)
        result.emplace(std::make_pair(value.first.second, value.first.first), value.second);


    return std::make_shared<CMatrixSparse>(m_Height, m_Width, m_Zeroes, result);
}

