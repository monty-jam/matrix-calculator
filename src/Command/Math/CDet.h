#ifndef SEMWORK_CDET_H
#define SEMWORK_CDET_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the determinant of a square matrix.
 */
class CDet : public CCommand {
public:
    /**
     * @brief Constructs Determinant Command and links it with CCalculator and CMemory instances.
     *
     * First argument - name of a variable with matrix to get determinant from.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CDet(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CDet instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CDet instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Calculates the determinant of a given matrix, prints the result to the output stream (if Return Vector
     * was empty), and pushes the result to the Return Vector.
     *
     * Firstly checks whether the given matrix is square.
     *
     * Transforms given matrix to the row echelon form by calling GEM command, and saving the result to the
     * temporary variable ~det. GEM command will return the amount of times when the rows were swapped, and that will
     * determine the sign of determinant. Determinant equals to the multiplication of its sign and all diagonal values
     * in row echelon form.
     *
     * @note All temporary variables should be deleted, or called Write commands be undone.
     *
     * @param argv Argument Vector with a variable of square matrix to calculate determinant from.
     * @param retv Return Vector, result will be printed to output stream if empty. Determinant of matrix will be added.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CDET_H
