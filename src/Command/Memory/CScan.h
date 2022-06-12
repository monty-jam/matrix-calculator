#ifndef SEMWORK_CSCAN_H
#define SEMWORK_CSCAN_H


#include "../../Calculator/CCalculator.h"

class CScan : public CCommand {
public:
    CScan(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CSCAN_H
