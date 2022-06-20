#ifndef SEMWORK_CLOAD_H
#define SEMWORK_CLOAD_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to load matrix from readable file.
 */
class CLoad : public CCommand {
public:
    /**
     * @brief Constructs Load Command and links it with CCalculator and CMemory objects.
     *
     * First argument - Name of a result variable where matrix will be written.
     * Second argument - Path to the readable file.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CLoad(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CLoad object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CLoad object.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Loads matrix from readable file.
     *
     * Matrices are stored differently, memory-wise effective depending on their type (dense or sparse). For both
     * types command opens file in the second argument's path and reads type, width and length via ifstream >>.
     *
     * For sparse matrices, command reads amount of values and then reads each value in a cycle in a format
     * "column, row, value", after that expects the end of file.
     *
     * For dense matrices, command reads all "width * height" values by rows left to right, after that expects the end
     * of file.
     *
     * Reading from file ignores all whitespaces, except after the last expected value, there shouldn't be any
     * whitespaces or other unexpected values, otherwise the file data will be invalid.
     *
     * @note Prints the warning to the output stream, if file stores data about one type in other type formatting, so it
     * becomes not memory-wise effective.
     *
     * @param argv Argument Vector with a result variable and a readable file path.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument Unexpected value was read inside a file.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CLOAD_H
