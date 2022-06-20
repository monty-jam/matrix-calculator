#ifndef SEMWORK_CMUL_H
#define SEMWORK_CMUL_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the product of two matrices.
 */
class CMul : public CCommand {
public:
    /**
     * @brief Constructs Multiply Command and links it with CCalculator and CMemory objects.
     *
     * First argument - Name of a result variable, where the product will be written.
     * Second argument - Variable name of first matrix.
     * Third argument - Variable name of second matrix.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CMul(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CMul object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CMul object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Calculates the product of two given matrices and saves the result to the variable.
     *
     * Firstly checks whether first matrix width equals to the second matrix height. Then new double vector of values
     * (with the height of first and the width of second matrix dimensions) will be filled with the values of each first
     * matrix row multiplied by each second matrix column. CMatrix shared pointer of this newly created matrix
     * will be saved in CMemory by the result variable name.
     *
     * @param argv Argument Vector with a result variable and two variables of matrices to multiply.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument If the first matrix width not equals to the second matrix height.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CMUL_H
