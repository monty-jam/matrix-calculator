#ifndef SEMWORK_CUNDO_H
#define SEMWORK_CUNDO_H


#include "../../Calculator/CCalculator.h"

class CUndo : public CCommand {
public:
    CUndo(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void validate(const std::deque<std::string> &argv) const override;

    void execute(const std::deque<std::string> &argv) override;

    void undo() override;

    void printInfo() override;

private:
    CCalculator& m_Calculator;
    CMemory& m_Memory;
};


#endif //SEMWORK_CUNDO_H
