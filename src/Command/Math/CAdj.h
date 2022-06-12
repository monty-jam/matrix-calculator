#ifndef SEMWORK_CADJ_H
#define SEMWORK_CADJ_H


#include "../../Calculator/CCalculator.h"

class CAdj : public CCommand {
public:
    CAdj(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;

    std::shared_ptr<CMatrix> getCofactor(const std::shared_ptr<CMatrix> &mtxVar, unsigned int x, unsigned int y);
};


#endif //SEMWORK_CADJ_H
