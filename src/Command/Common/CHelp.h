#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include <map>
#include <memory>
#include "../CCommand.h"
#include "../../Calculator/CMemory.h"

class CHelp : public CCommand {
public:
    explicit CHelp(CMemory& memory);

    static std::shared_ptr<CCommand> create(CMemory& memory);

    void validate(const std::deque<std::string> &argv) const override;

    void execute(const std::deque<std::string> &args) override;

};


#endif //SEMWORK_CHELP_H
