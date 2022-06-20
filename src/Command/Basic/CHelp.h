#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to show details of all available commands.
 */
class CHelp : public CCommand {
public:
    /**
     * @brief Constructs Help Command and links it with CCalculator and CMemory instances.
     *
     * Help Command doesn't contain any arguments.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CHelp(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CHelp instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CHelp instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Prints details of all available commands to the output stream.
     *
     * Creates every initialized command from CCalculator's m_Commands by calling function pointers and prints each
     * to the output stream with the implemented << operator.
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


#endif //SEMWORK_CHELP_H
