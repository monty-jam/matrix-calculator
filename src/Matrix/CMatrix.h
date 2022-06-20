#ifndef SEMESTRAL_CMATRIX_H
#define SEMESTRAL_CMATRIX_H


#include <memory>
#include <vector>

/**
 * @brief Matrix parent class.
 *
 * Each matrix is defined by its width, height and number of zeroes. Zeroes are stored to determine whether matrix
 * should be stored as dense (zeroes are less than or equals to half of all values), or sparse
 * (zeroes are more than a half of all values).
 */
class CMatrix {
public:
    /**
     * @brief Constructs matrix of given dimensions and amount of zero values.
     *
     * @param width Width of matrix.
     * @param height Height of matrix.
     * @param zeroes Amount of zero values in matrix.
     */
    CMatrix(unsigned width, unsigned height, unsigned zeroes);

    virtual ~CMatrix();

    /**
     * @brief Creates an object of a CMatrix child (CMatrixDense or CMatrixSparse).
     *
     * Choice of an inherited child class (CMatrixDense or CMatrixSparse) depends on amount of zero values to all
     * values. Method is static, so it is used inside commands' implementations.
     *
     * @param width Width of matrix.
     * @param height Height of matrix.
     * @param zeroes Amount of zero values in matrix.
     * @param mtx Double vector of matrix values (inner vectors are columns in one row from left to right, outer vectors
     * are rows downwards).
     * @return Shared pointer on a created object of CMatrix child.
     */
    static std::shared_ptr<CMatrix> create(unsigned width, unsigned height, unsigned zeroes,
                                           const std::vector<std::vector<double>> &mtx);

    /**
     * @brief Prints matrix values to the output stream.
     *
     * @note Values more than 7 digits will be shortened to keep formatting.
     *
     * @param os Output stream to which matrix values will be printed.
     */
    void print(std::ostream &os) const;

    /**
     * @brief Operator to print matrix to output stream.
     *
     * Uses print(std::ostream &os) in its implementation..
     *
     * @param os Output stream to which matrix values will be printed.
     * @param mtx Matrix that will be printed.
     * @return Reference on the same output stream, with printed matrix.
     */
    friend std::ostream &operator<<(std::ostream &os, const CMatrix &mtx);

    /**
     * @brief Saves matrix data to the file with given path.
     *
     * Implemented by inherited classes because of different memory representation.
     *
     * @param filePath Path, where matrix data will be saved (guaranteed to be valid by CCommand validation).
     */
    virtual void save(std::string filePath) const = 0;

    /**
     * @brief Returns the matrix value in given coordinates.
     *
     * Implemented by inherited classes because of different memory representation.
     *
     * @note There shouldn't be any whitespaces after the last saved value, else loading will fail.
     * @param x Column number (from left to right).
     * @param y Row number (downwards).
     * @return Matrix value in given coordinates.
     */
    virtual double at(unsigned x, unsigned y) const = 0;

    /**
     * @brief Gets matrix width.
     *
     * @return Matrix width.
     */
    unsigned getWidth() const;

    /**
     * @brief Gets matrix height.
     *
     * @return Matrix height.
     */
    unsigned getHeight() const;

    /**
     * @brief Gets matrix amount of zero values.
     *
     * @return Matrix amount of zero values.
     */
    unsigned getZeroes() const;

    /**
     * @brief Transposes matrix.
     *
     * Implemented by inherited classes because of different memory representation.
     *
     * @return Shared pointer on a new object of transposed matrix.
     */
    virtual std::shared_ptr<CMatrix> transpose() const = 0;

protected:
    /**
     * @brief Width of matrix.
     */
    unsigned m_Width;
    /**
     * @brief Height of matrix.
     */
    unsigned m_Height;
    /**
     * @brief Amount of zero values in matrix.
     */
    unsigned m_Zeroes;
};


#endif //SEMESTRAL_CMATRIX_H
