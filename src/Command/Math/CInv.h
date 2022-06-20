#ifndef SEMWORK_CINV_H
#define SEMWORK_CINV_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the inverse of a square matrix.
 */
class CInv : public CCommand {
public:
    /**
     * @brief Constructs Inverse Command and links it with CCalculator and CMemory instances.
     *
     * First argument - name of a result variable, where the inverse will be written.
     * Second argument - name of a variable with matrix to get inverse from.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CInv(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CInv instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CInv instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Finds the inverse of given matrix.
     *
     * Firstly checks whether the given matrix is square.
     *
     * Calls the CDet command to calculate given matrix determinant (Calls with non-empty Return Vector, so that
     * CDet won't print the result to the output stream). Inverse can't be calculated if matrix determinant equals to
     * zero.
     *
     * Matrix inverse equals to the matrix adjugate, divided by the determinant, so CAdj command will be called.
     *
     * @param argv Argument Vector with a result variable and variable of matrix to get inverse from.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CINV_H
