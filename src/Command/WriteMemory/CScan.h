#ifndef SEMWORK_CSCAN_H
#define SEMWORK_CSCAN_H


#include "../../Calculator/CCalculator.h"

class CScan : public CCommand {
public:
    CScan(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void validate(const std::deque<std::string> &argv) const override;

    void execute(const std::deque<std::string> &argv) override;

    void undo() override;

    void printInfo() override;

private:
    CCalculator& m_Calculator;
    CMemory& m_Memory;
};


#endif //SEMWORK_CSCAN_H
