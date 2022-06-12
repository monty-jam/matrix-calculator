#ifndef SEMWORK_CLOAD_H
#define SEMWORK_CLOAD_H


#include "../../Calculator/CCalculator.h"

class CLoad : public CCommand {
public:
    CLoad(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CLOAD_H
