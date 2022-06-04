#ifndef SEMWORK_CDEL_H
#define SEMWORK_CDEL_H


#include <string>
#include <map>
#include <memory>
#include "../../Matrix/CMatrix.h"
#include "CCommand.h"

class CDel : public CCommand {
public:
    explicit CDel(std::map<std::string, std::shared_ptr<CMatrix>> &matrices);

    void validate(const std::vector<std::string> &args) const override;

    void execute(const std::vector<std::string> &args) override;

private:
    std::map<std::string, std::shared_ptr<CMatrix>> &m_Matrices;
};


#endif //SEMWORK_CDEL_H
