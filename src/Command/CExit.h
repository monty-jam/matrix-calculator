#ifndef SEMWORK_CEXIT_H
#define SEMWORK_CEXIT_H


#include "CCommand.h"

class CExit : public CCommand {
public:
    explicit CExit(bool &exitFlag);

    void validate(const std::vector<std::string>& args) const override;

    void execute() override;
private:
    bool& m_ExitFlag;
};


#endif //SEMWORK_CEXIT_H
