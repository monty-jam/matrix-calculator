#ifndef SEMWORK_CEXIT_H
#define SEMWORK_CEXIT_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to stop the run of program.
 */
class CExit : public CCommand {
public:
    /**
     * @brief Constructs Exit Command and links it with CCalculator and CMemory objects.
     *
     * Exit Command doesn't contain any arguments.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CExit(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CExit object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CExit object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Stops the run of program.
     *
     * Calls CCalculator's exit() method to change the exit flag and stop program running loop.
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


#endif //SEMWORK_CEXIT_H
