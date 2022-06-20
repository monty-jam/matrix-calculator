#ifndef SEMWORK_CSUB_H
#define SEMWORK_CSUB_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the difference of two matrices.
 */
class CSub : public CCommand {
public:
    /**
     * @brief Constructs Subtract Command and links it with CCalculator and CMemory objects.
     *
     * First argument - Name of a result variable, where the difference will be written.
     * Second argument - Variable name of first matrix.
     * Third argument - Variable name of second matrix.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CSub(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CSub object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CSub object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Calculates the difference of two given matrices and saves the result to the variable.
     *
     * Firstly checks whether both matrices have the same dimensions. Then new double vector of values (with the same
     * dimensions as the original matrices) will be filled with the values of first matrix subtracted by second matrix
     * values, in each position. CMatrix shared pointer of this newly created matrix will be saved in CMemory by the
     * result variable name.
     *
     * @param argv Argument Vector with a result variable and two variables of matrices to subtract.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument If matrices dimensions are not equals to each other.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CSUB_H
