#ifndef SEMWORK_CSAVE_H
#define SEMWORK_CSAVE_H


#include "../../Calculator/CCalculator.h"

class CSave : public CCommand {
public:
    CSave(CCalculator &calculator, CMemory &memory);

    static std::shared_ptr<CCommand> create(CCalculator &calculator, CMemory &memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator &m_Calculator;
};


#endif //SEMWORK_CSAVE_H
