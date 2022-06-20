#ifndef SEMWORK_CRANK_H
#define SEMWORK_CRANK_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to calculate the matrix rank.
 */
class CRank : public CCommand {
public:
    /**
     * @brief Constructs Rank Command and links it with CCalculator and CMemory instances.
     *
     * First argument - name of a variable with matrix to get rank from.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CRank(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CRank instance.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CRank instance.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Finds the matrix rank.
     *
     * Matrix rank equals to the amount of non-zero rows in row echelon form. CGem command is called to transform
     * given matrix to the row echelon form, and the rank will be returned by CGem in its Return Vector as the second
     * value, which will be printed to the output stream.
     *
     * @note All temporary variables should be deleted, or called Write commands be undone.
     *
     * @param argv Argument Vector with a variable of matrix to calculate rank from.
     * @param retv Return Vector, no usage.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client instance.
     */
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CRANK_H
