#ifndef SEMWORK_CPRINT_H
#define SEMWORK_CPRINT_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to print matrix to the output stream.
 */
class CPrint : public CCommand {
public:
    /**
     * @brief Constructs Print Command and links it with CCalculator and CMemory objects.
     *
     * First argument - Name of a variable to be printed.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CPrint(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CPrint object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CPrint object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Prints matrix to the output stream via << operator.
     *
     * Matrix printing is implemented by each CMatrix type differently because of different memory representations.
     *
     * @param argv Argument Vector with a variable of a matrix to be printed.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CPRINT_H
