#ifndef SEMWORK_CDEL_H
#define SEMWORK_CDEL_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to delete matrix by variable name.
 */
class CDel : public CCommand {
public:
    /**
     * @brief Constructs Delete Command and links it with CCalculator and CMemory objects.
     *
     * First argument - name of a variable, where is stored the matrix to delete.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CDel(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CDel object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CDel object.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Deletes variable and shared pointer of CMatrix in it.
     *
     * @param argv Argument Vector with a name of variable to delete.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CDEL_H
