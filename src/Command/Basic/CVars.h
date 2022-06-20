#ifndef SEMWORK_CVARS_H
#define SEMWORK_CVARS_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to show all stored variables with matrices.
 */
class CVars : public CCommand {
public:
    /**
     * @brief Constructs Vars Command and links it with CCalculator and CMemory objects.
     *
     * Vars Command doesn't contain any arguments.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CVars(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CVars object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CVars object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Prints all stored variables with matrices in CMemory object to the output stream.
     *
     * @param argv Argument Vector, must be empty.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CVARS_H
