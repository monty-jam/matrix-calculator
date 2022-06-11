#ifndef SEMWORK_CMERGE_H
#define SEMWORK_CMERGE_H


#include "../../Calculator/CCalculator.h"

class CMerge : public CCommand {
public:
    CMerge(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CMERGE_H
