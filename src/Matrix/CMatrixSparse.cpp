#include "CMatrixSparse.h"

CMatrixSparse::CMatrixSparse(unsigned int width, unsigned int height, unsigned int zeroes,
                             const std::vector<std::vector<double>>& matrix) : CMatrix(width, height, zeroes) {
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            if (matrix[y][x] != 0)
                m_Values.emplace(std::make_pair(x, y), matrix[y][x]);
}
