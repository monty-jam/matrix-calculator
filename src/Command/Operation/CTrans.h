#ifndef SEMWORK_CTRANS_H
#define SEMWORK_CTRANS_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to transpose a matrix.
 */
class CTrans : public CCommand {
public:
    /**
     * @brief Constructs Transpose Command and links it with CCalculator and CMemory instances.
     *
     * First argument - name of a result variable, where the transposed matrix will be written.
     * Second argument - variable name of matrix to be transposed.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CTrans(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CTrans instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CTrans instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Transposes given matrix and saves the result to a variable.
     *
     * Implemented by inherited classes of CMatrix because of different memory representation. CMatrix shared pointer
     * of newly created matrix will be saved in CMemory by the result variable name.
     *
     * @param argv Argument Vector with a result variable and the variable which matrix to transpose.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CTRANS_H
