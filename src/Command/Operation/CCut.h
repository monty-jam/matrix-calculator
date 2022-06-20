#ifndef SEMWORK_CCUT_H
#define SEMWORK_CCUT_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to cut a matrix of any dimensions, starting from desired coordinates.
 */
class CCut : public CCommand {
public:
    /**
     * @brief Constructs Cut Command and links it with CCalculator and CMemory objects.
     *
     * First argument - name of a result variable, where the cut matrix will be written.
     * Second argument - variable name of matrix to be cut.
     * Third argument - Width of new matrix.
     * Fourth argument - Height of new matrix.
     * Fifth argument - Column coordinate to start the cut (left to right).
     * Sixth argument - Row coordinate to start the cut (downwards).
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CCut(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CCut object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CCut object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Cuts new matrix of any dimensions from a given matrix, starting from desired coordinates.
     *
     * Firstly checks whether given coordinates and dimensions won't go out of matrix range. Then new double vector of
     * values (with the width and height from the input arguments) will be filled with the values of the original matrix,
     * starting from the coordinates from the input arguments. CMatrix shared pointer of this newly created matrix
     * will be saved in CMemory by the result variable name.
     *
     * @param argv Argument Vector with a result variable, the variable which matrix to cut, dimensions and coordinates.
     * @param retv Return Vector, no usage.
     * @throw std::out_of_range If coordinates and dimensions go out of matrix range.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CCUT_H
