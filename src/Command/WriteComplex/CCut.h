#ifndef SEMWORK_CCUT_H
#define SEMWORK_CCUT_H


#include "../../Calculator/CCalculator.h"

class CCut : public CCommand {
public:
    CCut(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void validate(const std::deque<std::string> &argv) const override;

    void execute(const std::deque<std::string> &argv) override;

    void undo() override;

    void printInfo() override;

private:
    CCalculator& m_Calculator;
    CMemory& m_Memory;
};


#endif //SEMWORK_CCUT_H
