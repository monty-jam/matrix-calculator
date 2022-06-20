#ifndef SEMWORK_CMERGE_H
#define SEMWORK_CMERGE_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to merge two matrices horizontally.
 */
class CMerge : public CCommand {
public:
    /**
     * @brief Constructs Merge Command and links it with CCalculator and CMemory objects.
     *
     * First argument - name of a result variable, where the merged matrix will be written.
     * Second argument - variable name of left matrix.
     * Third argument - variable name of right matrix.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CMerge(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CMerge object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CMerge object.
     */
    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    /**
     * @brief Merges horizontally two matrices into one.
     *
     * Firstly checks whether both matrices heights are equal. Then new double vector of values
     * (with the height of any matrix and the width as the sum of two matrices widths) will be filled by rows, where
     * each row is concatenation of two matrices rows. CMatrix shared pointer of this newly created
     * matrix will be saved in CMemory by the result variable name.
     *
     * @param argv Argument Vector with a result variable and two variables of matrices to merge.
     * @param retv Return Vector, no usage.
     * @throw std::invalid_argument If matrices heights are not equal.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CMERGE_H
