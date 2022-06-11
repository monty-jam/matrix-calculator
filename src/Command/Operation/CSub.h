#ifndef SEMWORK_CSUB_H
#define SEMWORK_CSUB_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CSub : public CCommand {
public:
    CSub(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CSUB_H
