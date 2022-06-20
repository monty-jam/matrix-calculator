#ifndef SEMWORK_CADJ_H
#define SEMWORK_CADJ_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the adjugate of a square matrix.
 */
class CAdj : public CCommand {
public:
    /**
     * @brief Constructs Adjugate Command and links it with CCalculator and CMemory objects.
     *
     * First argument - name of a result variable, where the adjugate will be written.
     * Second argument - name of a variable with matrix to get adjugate from.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CAdj(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CAdj object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CAdj object.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Finds the adjugate of a given matrix.
     *
     * Firstly checks whether the given matrix is square.
     *
     * Fills the new double vector of values with the determinants
     * of each matrix cofactor. Sign of each determinant value depends on a position in adjugate matrix, signs
     * change in a checkerboard pattern, starting with a plus sign in the left upper corner. Then resulted matrix
     * is transposed, the result of transpose is adjugate of a given matrix.
     *
     * All determinants of cofactors are collected in one Return Vector, and at the start Return Vector is filled
     * with dummy value, because CDet won't print the calculated result to the output stream, if Return Vector with
     * its call is not empty.
     *
     * @param argv Argument Vector with a result variable and variable of matrix to get adjugate from.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument if matrix is not square.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator &m_Calculator;

    /**
     * @brief Gets a cofactor from a given matrix by removing chosen row and column, and merging values that are left.
     *
     * @param mtxVar CMatrix shared pointer to get cofactor from.
     * @param x Column to be removed.
     * @param y Row to be removed.
     * @return CMatrix shared pointer of an mtxVar cofactor.
     */
    std::shared_ptr<CMatrix> getCofactor(const std::shared_ptr<CMatrix> &mtxVar, unsigned int x, unsigned int y);
};


#endif //SEMWORK_CADJ_H
