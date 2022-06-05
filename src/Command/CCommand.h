#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include <map>
#include <vector>
#include <deque>
#include "../Calculator/CMemory.h"

class CCommand {
public:
    CCommand(CMemory &memory);

    virtual void validate(const std::deque<std::string> &argv) const = 0;

    virtual void execute(const std::deque<std::string> &argv) = 0;

protected:
    CMemory& m_Memory;

};


#endif //SEMWORK_CCOMMAND_H
