#ifndef SEMWORK_CDET_H
#define SEMWORK_CDET_H


#include "../../Calculator/CCalculator.h"

class CDet : public CCommand {
public:
    CDet(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CDET_H
