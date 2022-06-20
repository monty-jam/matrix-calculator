#ifndef SEMWORK_CUNDO_H
#define SEMWORK_CUNDO_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to undo the last command and return memory to the previous state.
 */
class CUndo : public CCommand {
public:
    /**
     * @brief Constructs Undo Command and links it with CCalculator and CMemory instances.
     *
     * Undo Command doesn't contain any arguments.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CUndo(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CUndo instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CUndo instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Undoes the last command and returns memory to the previous state.
     *
     * Calls CCalculator's undo() method, that then works with the Command Buffer, clears the last command from the
     * history and uses its backup to return memory to the state before last command execution.
     *
     * @param argv Argument Vector, must be empty.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CUNDO_H
