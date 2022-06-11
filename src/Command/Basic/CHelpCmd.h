#ifndef SEMWORK_CHELPCMD_H
#define SEMWORK_CHELPCMD_H


#include "../../Calculator/CCalculator.h"

class CHelpCmd : public CCommand {
public:
    CHelpCmd(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CHELPCMD_H
