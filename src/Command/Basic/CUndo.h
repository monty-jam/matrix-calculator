#ifndef SEMWORK_CUNDO_H
#define SEMWORK_CUNDO_H


#include "../../Calculator/CCalculator.h"

class CUndo : public CCommand {
public:
    CUndo(CCalculator& calculator, CMemory& memory);

    static std::shared_ptr<CCommand> create(CCalculator& calculator, CMemory& memory);

    void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) override;

private:
    CCalculator& m_Calculator;
};


#endif //SEMWORK_CUNDO_H
