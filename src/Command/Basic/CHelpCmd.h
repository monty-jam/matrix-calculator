#ifndef SEMWORK_CHELPCMD_H
#define SEMWORK_CHELPCMD_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to show details of concrete command.
 */
class CHelpCmd : public CCommand {
public:
    /**
     * @brief Constructs Help-Cmd Command and links it with CCalculator and CMemory instances.
     *
     * First argument - name of a command, which needs to be written.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CHelpCmd(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CHelpCmd instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CHelpCmd instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Prints details of given command to the output stream.
     *
     * Creates command from CCalculator's m_Commands by calling function pointer and prints it to the output stream
     * with the implemented << operator.
     *
     * @param argv Argument Vector with a name of command to show information.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CHELPCMD_H
