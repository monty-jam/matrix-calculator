#ifndef SEMWORK_CADD_H
#define SEMWORK_CADD_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CAdd : public CCommand {
public:
    CAdd(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CADD_H
