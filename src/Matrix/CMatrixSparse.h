#ifndef SEMESTRAL_CMATRIXSPARSE_H
#define SEMESTRAL_CMATRIXSPARSE_H


#include <utility>
#include <map>
#include "CMatrix.h"

/**
 * @brief Sparse Matrix class.
 *
 * Amount of zero values in this matrix is more than the half of all values, so it can be effectively
 * memory-wise represented as a map, where the key is a pair of coordinates (column from left to right, row downwards),
 * value of map is a matrix value store in these coordinates.
 */
class CMatrixSparse : public CMatrix {
public:
    /**
     * @brief Constructs new sparse matrix by double vector of values.
     *
     * @param width Width of matrix.
     * @param height Height of matrix.
     * @param zeroes Amount of zero values in matrix.
     * @param mtx Double vector of matrix values (inner vectors are columns in one row from left to right, outer vectors
     * are rows downwards).
     */
    CMatrixSparse(unsigned width, unsigned height, unsigned zeroes, const std::vector<std::vector<double>>& mtx);

    /**
     * @brief Constructs new sparse matrix by map of values.
     *
     * @param width Width of matrix.
     * @param height Height of matrix.
     * @param zeroes Amount of zero values in matrix.
     * @param mtx
     */
    CMatrixSparse(unsigned width, unsigned height, unsigned zeroes,
                  std::map<std::pair<unsigned, unsigned>, double> &mtx);

    /**
     * @brief Saves sparse matrix data to the file with given path.
     *
     * Resulting file will contain header with matrix type (sparse) and values of width, height, and amount of values.
     * Then there will be stored each value on a new line in a format "column", "row" and "value".
     *
     * @param filePath Path, where sparse matrix data will be saved (guaranteed to be valid by CCommand validation).
     */
    void save(std::string filePath) const override;

    /**
     * @brief Returns the dense matrix value in given coordinates.
     *
     * @param x Column number (from left to right).
     * @param y Row number (downwards).
     * @throw std::out_of_range If given coordinates are out of matrix range.
     * @return Value in given coordinates.
     */
    double at(unsigned x, unsigned y) const override;

    /**
     * @brief Transposes sparse matrix.
     *
     * Creates a new instance of CMatrixSparse, and swaps rows and columns of each value of original matrix, what
     * results in transposed matrix.
     *
     * @return CMatrix shared pointer to new CMatrixSparse instance, transposed from original.
     */
    std::shared_ptr<CMatrix> transpose() const override;

private:
    /**
     * @brief Map of sparse matrix values, the key is a pair of coordinates  (column from left to right, row downwards),
     * value of map is a matrix value store in these coordinates.
     */
    std::map<std::pair<unsigned, unsigned>, double> m_Values;
};


#endif //SEMESTRAL_CMATRIXSPARSE_H
