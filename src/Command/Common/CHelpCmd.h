#ifndef SEMWORK_CHELPCMD_H
#define SEMWORK_CHELPCMD_H


#include <vector>
#include <string>
#include "CCommand.h"

class CHelpCmd : public CCommand {
public:
    explicit CHelpCmd(std::map<std::string, std::shared_ptr<CCommand>> &commands);

    void validate(const std::vector<std::string>& args) const override;

    void execute(const std::vector<std::string> &args) override;
private:
    std::map<std::string, std::shared_ptr<CCommand>>& m_Commands;
};


#endif //SEMWORK_CHELPCMD_H
