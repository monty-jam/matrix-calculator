#ifndef SEMWORK_CMUL_H
#define SEMWORK_CMUL_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CMul : public CCommand {
public:
    CMul(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CMUL_H
