#ifndef SEMWORK_CGEM_H
#define SEMWORK_CGEM_H


#include "../../Calculator/CCalculator.h"

class CGem : public CCommand {
public:
    CGem(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv) override;

protected:
    int getSign() const;

    unsigned getRank() const;

private:
    CCalculator &m_Calculator;
    int detSign = 1;
    unsigned rank = 0;

    void g1(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2);

    void
    g3(std::vector<std::vector<double>> &mtx, unsigned y1, unsigned y2, unsigned x, unsigned width, unsigned &zeroes);
};


#endif //SEMWORK_CGEM_H
