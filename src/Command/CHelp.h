#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include <map>
#include <memory>
#include "CCommand.h"

class CHelp : public CCommand {
public:
    explicit CHelp(std::map<std::string, std::shared_ptr<CCommand>> &commands);

    void validate(const std::vector<std::string>& args) const override;

    void execute() override;
private:
    std::map<std::string, std::shared_ptr<CCommand>>& m_Commands;
};


#endif //SEMWORK_CHELP_H
