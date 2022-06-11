#ifndef SEMWORK_CEXIT_H
#define SEMWORK_CEXIT_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CExit : public CCommand {
public:
    CExit(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CEXIT_H
