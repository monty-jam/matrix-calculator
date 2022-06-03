#ifndef SEMWORK_CCOMMANDHELP_H
#define SEMWORK_CCOMMANDHELP_H


#include <map>
#include <memory>
#include "CCommand.h"

class CCommandHelp : public CCommand {
public:
    explicit CCommandHelp(std::map<std::string, std::shared_ptr<CCommand>> &commands);

    int validate(const std::string& line) const override;

    std::shared_ptr<CMatrix> execute() override;
private:
    std::map<std::string, std::shared_ptr<CCommand>>& m_Commands;
};


#endif //SEMWORK_CCOMMANDHELP_H
