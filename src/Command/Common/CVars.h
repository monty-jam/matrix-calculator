#ifndef SEMWORK_CVARS_H
#define SEMWORK_CVARS_H


#include "CCommand.h"

class CVars : public CCommand {
public:
    explicit CVars(std::map<std::string, std::shared_ptr<CMatrix>> &matrices);

    void validate(const std::vector<std::string>& args) const override;

    void execute(const std::vector<std::string> &args) override;
private:
    std::map<std::string, std::shared_ptr<CMatrix>>& m_Matrices;
};


#endif //SEMWORK_CVARS_H
