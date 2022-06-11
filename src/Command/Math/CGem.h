#ifndef SEMWORK_CGEM_H
#define SEMWORK_CGEM_H


#include "../../Calculator/CCalculator.h"

class CGem : public CCommand {
public:
    CGem(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CGEM_H
