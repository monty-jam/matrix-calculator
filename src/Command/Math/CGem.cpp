#include <cmath>
#include "CGem.h"

CGem::CGem(CCalculator &calculator, CMemory &memory)
        : CCommand(memory,
                   "gem", {"RESULT", "VARIABLE"},
                   "perform Gaussian elimination on a given variable and save to the result"),
          m_Calculator(calculator) {}

std::shared_ptr<CCommand> CGem::create(CCalculator &calculator, CMemory &memory) {
    return std::make_shared<CGem>(calculator, memory);
}

void CGem::execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) {
    std::shared_ptr<CMatrix> mtxVar = m_Memory.getMatrix(argv[1]);

    unsigned width = mtxVar->getWidth();
    unsigned height = mtxVar->getHeight();
    unsigned zeroes = mtxVar->getZeroes();

    std::vector<std::vector<double>> mtx(height);
    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x)
            mtx[y].push_back(mtxVar->at(x, y));

    int detSign = 1;

    unsigned y = 0;
    unsigned x = 0;
    while (true) {
        if (y >= height || x >= width)
            break;

        if (CCalculator::doubleEquals(mtx[y][x], 0)) {
            if (y == height - 1) // it's the last row and current is zero, so no values under the current
                x++;

            for (unsigned r = y + 1; r < height; ++r) {
                if (CCalculator::doubleNonEquals(mtx[r][x], 0)) { // swap non-zero value up
                    g1(mtx, y, r);
                    detSign *= -1;
                    break;
                }

                if (r == height - 1) // all values under current are 0
                    x++;
            }

        } else { // mtx[y][x] != 0
            for (unsigned r = y + 1; r < height; ++r)
                if (CCalculator::doubleNonEquals(mtx[r][x], 0)) // destroy non-zero value under the current
                    g3(mtx, y, r, x, width, zeroes);

            y++;
            x++;
        }
    }

    retv.push_back(std::to_string(detSign)); // sign of determinant
    retv.push_back(std::to_string(y)); // rank

    m_Memory.addMatrix(argv[0], CMatrix::create(width, height, zeroes, mtx));
}

void CGem::g1(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2) {
    mtx[y1].swap(mtx[y2]);
}

void CGem::g3(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2, unsigned x, unsigned width,
              unsigned &zeroes) {
    double k = mtx[y2][x] / mtx[y1][x];

    for (unsigned c = 0; c < width; ++c) {
        if (CCalculator::doubleNonEquals(mtx[y1][c], 0)) {
            double prev = mtx[y2][c];

            mtx[y2][c] -= mtx[y1][c] * k;

            if (CCalculator::doubleEquals(mtx[y2][c], 0)) // if non-zero becomes zero
                zeroes++;
            else if (CCalculator::doubleEquals(prev, 0)
                    && CCalculator::doubleNonEquals(mtx[y2][c], 0)) // if zero becomes non-zero
                zeroes--;
        }
    }
}
