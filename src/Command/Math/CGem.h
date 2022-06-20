#ifndef SEMWORK_CGEM_H
#define SEMWORK_CGEM_H


#include "../../Calculator/CCalculator.h"

/**
 * @brief Command class to transform matrix to the row echelon form.
 */
class CGem : public CCommand {
public:
    /**
     * @brief Constructs Determinant Command and links it with CCalculator and CMemory objects.
     *
     * First argument - name of a variable with matrix to get determinant from.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     */
    CGem(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Static method to create and get a CCommand shared pointer to a new CGem object.
     *
     * @param calculator Client class.
     * @param memory Receiver class.
     * @return CCommand shared pointer to a new CGem object.
     */
    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    /**
     * @brief Transforms given matrix to the row echelon form and saves to the result variable.
     *
     * Command implements an algorithm that is described in BI-LIN lecture:
     * https://kam.fit.cvut.cz/deploy/bi-lin//lin-prednaska-2.pdf (slide 36)
     *
     * That algorithm guarantees that the matrix can always be transformed to the row echelon form, using first and
     * third elementary row operations, starting from the upper left corner and coming downside right till the matrix
     * end.
     *
     * Created transformed matrix is saved in a CMemory with a first argument variable name. Command pushes to the
     * Return Vector two values - count of g1 operation usage (used for counting determinants) and matrix rank
     * (amount of non-zero rows in a row echelon form).
     *
     * @param argv Argument Vector with a result variable and variable of matrix to perform GEM.
     * @param retv Return Vector, Count of used g1 operation usage and Matrix rank will be added.
     */
    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    /**
     * @brief Reference to CCalculator Client object.
     */
    CCalculator &m_Calculator;

    /**
     * @brief First elementary row operation, swaps two rows.
     *
     * @param mtx Double vector matrix to be changed.
     * @param y1 First row.
     * @param y2 Second row.
     */
    void g1(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2);

    /**
     * @brief Third elementary row operation, adds a multiple of one row to another row.
     *
     * @param mtx Double vector matrix to be changed.
     * @param y1 First row to be multiplied.
     * @param y2 Second row that to which multiplied first row will be added.
     * @param x Current column of GEM algorithm.
     * @param width Width of a matrix.
     * @param zeroes Reference to the amount of zero values (will increase or decrease depending on values' change).
     */
    void
    g3(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2, unsigned x, unsigned width, unsigned &zeroes);
};


#endif //SEMWORK_CGEM_H
