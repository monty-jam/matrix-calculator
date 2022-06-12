#ifndef SEMWORK_CCUT_H
#define SEMWORK_CCUT_H


#include "../../Calculator/CCalculator.h"

class CCut : public CCommand {
public:
    CCut(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CCUT_H
