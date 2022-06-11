#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CHelp : public CCommand {
public:
    CHelp(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CHELP_H
