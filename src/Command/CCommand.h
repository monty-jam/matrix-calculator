#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include <map>
#include <vector>
#include <deque>
#include "../Calculator/CMemory.h"

class CCommand {
public:
    virtual ~CCommand();

    virtual void validate(const std::deque<std::string> &argv) const = 0;

    virtual void execute(const std::deque<std::string> &argv) = 0;

    virtual void undo() = 0;

    bool isWrite() const;

    virtual void printInfo() = 0;

protected:
    std::string m_BackupName;
    std::shared_ptr<CMatrix> m_BackupMatrix = nullptr;
};


#endif //SEMWORK_CCOMMAND_H
