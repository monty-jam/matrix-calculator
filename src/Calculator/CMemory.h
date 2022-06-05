#ifndef SEMWORK_CMEMORY_H
#define SEMWORK_CMEMORY_H


#include <map>
#include <set>
#include <vector>
#include <memory>
#include "../Matrix/CMatrix.h"

class CMemory {
public:
    CMemory();

    std::string getCommandInfo() const;

    const std::map<std::string, std::shared_ptr<CMatrix>>& getMatrices() const;

    void addCommandName(const std::string& name);

    void addCommandInfo(const std::string& format, const std::string& helpInfo);

private:
    std::set<std::string> m_CommandNames;

    std::string m_CommandInfo;

    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;
};


#endif //SEMWORK_CMEMORY_H