#ifndef SEMWORK_CADD_H
#define SEMWORK_CADD_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the sum of two matrices.
 */
class CAdd : public CCommand {
public:
    /**
     * @brief Constructs Add Command and links it with CCalculator and CMemory instances.
     *
     * First argument - Name of a result variable, where the sum will be written.
     * Second argument - Variable name of first matrix.
     * Third argument - Variable name of second matrix.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CAdd(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CAdd instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CAdd instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Calculates the sum of two given matrices and saves the result to the variable.
     *
     * Firstly checks whether both matrices have the same dimensions. Then new double vector of values (with the same
     * dimensions as the original matrices) will be filled with the sums of first and second matrices' values in each
     * position. CMatrix shared pointer of this newly created matrix will be saved in CMemory by the result variable name.
     *
     * @param argv Argument Vector with a result variable and two variables of matrices to add.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument If matrices dimensions are not equals to each other.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CADD_H
