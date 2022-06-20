#ifndef SEMWORK_CSAVE_H
#define SEMWORK_CSAVE_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to save matrix into writable file.
 */
class CSave : public CCommand {
public:
    /**
     * @brief Constructs Save Command and links it with CCalculator and CMemory objects.
     *
     * First argument - Name of a variable of a matrix to be saved.
     * Second argument - Path to the writable file.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CSave(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CSave object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CSave object.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Saves matrix to the given writable file.
     *
     * Matrix saving format is implemented by each CMatrix type differently because of different memory representations.
     *
     * @param argv Argument Vector with a variable of a matrix to be saved and a path to the writable file.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CSAVE_H
