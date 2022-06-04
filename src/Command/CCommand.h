#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include <map>
#include "../Matrix/CMatrix.h"

class CCommand {
public:
    CCommand(std::string name, std::string format, std::string helpInfo);

    virtual void validate(const std::vector<std::string>& args) const = 0;

    virtual void execute() = 0;

    std::string getName() const;

protected:
    const std::string name;
    const std::string format;
    const std::string helpInfo;

    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const CCommand &cmd);
};

std::ostream &operator<<(std::ostream &os, const CCommand &cmd);


#endif //SEMWORK_CCOMMAND_H
