#ifndef SEMWORK_CPRINT_H
#define SEMWORK_CPRINT_H


#include "../CCommand.h"
#include "../../Calculator/CCalculator.h"

class CPrint : public CCommand {
public:
    CPrint(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CPRINT_H
