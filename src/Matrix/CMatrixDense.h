#ifndef SEMESTRAL_CMATRIXDENSE_H
#define SEMESTRAL_CMATRIXDENSE_H


#include <vector>
#include <memory>
#include "CMatrix.h"

/**
 * @brief Dense Matrix class.
 *
 * Amount of zero values in this matrix is less than or equals to the half of all values, so it can be effectively
 * memory-wise represented as a double vector of matrix values, where inner vectors are columns in one row
 * from left to right, outer vectors are rows downwards.
 */
class CMatrixDense : public CMatrix {
public:
    /**
     * @brief Constructs new dense matrix.
     *
     * @param width Width of matrix.
     * @param height Height of matrix.
     * @param zeroes Amount of zero values in matrix.
     * @param mtx Double vector of matrix values (inner vectors are columns in one row from left to right, outer vectors
     * are rows downwards).
     */
    CMatrixDense(unsigned width, unsigned height, unsigned zeroes, std::vector<std::vector<double>> mtx);

    /**
     * @brief Saves dense matrix data to the file with given path.
     *
     * Resulting file will contain header with matrix type (dense) values of width and height. Then there will be
     * stored all the "width * height" values of dense matrix, every row by a new line.
     *
     * @param filePath Path, where dense matrix data will be saved (guaranteed to be valid by CCommand validation).
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
     * @brief Transposes dense matrix.
     *
     * Creates a new instance of CMatrixDense, and fills its rows with original columns, which results in transposed
     * matrix.
     *
     * @return Shared pointer of new CMatrixDense instance, transposed from original.
     */
    std::shared_ptr<CMatrix> transpose() const override;

private:
    /**
     * @brief Double vector of dense matrix values (inner vectors are columns in one row from left to right, outer vectors
     * are rows downwards).
     */
    std::vector<std::vector<double>> m_Values;
};


#endif //SEMESTRAL_CMATRIXDENSE_H
