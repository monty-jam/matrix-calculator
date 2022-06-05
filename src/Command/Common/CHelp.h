#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include <map>
#include <memory>
#include "../CCommand.h"
#include "../../Calculator/CMemory.h"
#include "../../Calculator/CCalculator.h"

class CHelp : public CCommand {
public:
    CHelp(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void validate(const std::deque<std::string> &argv) const override;

    void execute(const std::deque<std::string> &args) override;

private:
    CCalculator& m_Calculator;
    CMemory& m_Memory;
};


#endif //SEMWORK_CHELP_H
