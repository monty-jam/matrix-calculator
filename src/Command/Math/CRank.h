#ifndef SEMWORK_CRANK_H
#define SEMWORK_CRANK_H


#include "../../Calculator/CCalculator.h"

class CRank : public CCommand {
public:
    CRank(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CRANK_H
