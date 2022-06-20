#ifndef SEMWORK_CSCAN_H
#define SEMWORK_CSCAN_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to scan matrix from input stream and save to the variable.
 */
class CScan : public CCommand {
public:
    /**
     * @brief Constructs Scan Command and links it with CCalculator and CMemory instances.
     *
     * First argument - Name of a result variable where scanned matrix will be saved.
     * Second argument - Width of new matrix.
     * Third argument - Height of new matrix.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CScan(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CScan instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CScan instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Scans matrix from input stream and saves to the variable.
     *
     * Parses all the "width * height" values from the input stream to the double vector of matrix values,
     * which is then used for calling static create method of CMatrix. Shared pointer to created matrix will be saved
     * to the given variable.
     *
     * @note When getting EOF while parsing values, exits the program.
     * @param argv Argument Vector with a result variable, width and height of desired scanned matrix.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument Received EOF, invalid data type of the value.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CSCAN_H
