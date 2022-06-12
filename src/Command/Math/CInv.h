#ifndef SEMWORK_CINV_H
#define SEMWORK_CINV_H


#include "../../Calculator/CCalculator.h"

class CInv : public CCommand {
public:
    CInv(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CINV_H
