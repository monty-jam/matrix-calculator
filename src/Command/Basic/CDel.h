#ifndef SEMWORK_CDEL_H
#define SEMWORK_CDEL_H


#include "../../Calculator/CCalculator.h"

class CDel : public CCommand {
public:
    CDel(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CDEL_H
