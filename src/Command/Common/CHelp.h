#ifndef SEMWORK_CHELP_H
#define SEMWORK_CHELP_H


#include <map>
#include <memory>
#include "CCommand.h"

class CHelp : public CCommand {
public:
    explicit CHelp(std::vector<std::shared_ptr<CCommand>> &commandList);

    void validate(const std::vector<std::string>& args) const override;

    void execute(const std::vector<std::string> &args) override;
private:
    std::vector<std::shared_ptr<CCommand>>& m_CommandList;
};


#endif //SEMWORK_CHELP_H
