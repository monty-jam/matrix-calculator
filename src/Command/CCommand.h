#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include "../Matrix/CMatrix.h"

class CCommand {
public:
    CCommand(std::string name, std::string format, std::string helpInfo);

    virtual int validate(const std::string& line) const = 0;

    virtual std::shared_ptr<CMatrix> execute() = 0;

protected:
    const std::string name;
    const std::string format;
    const std::string helpInfo;

    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const CCommand &cmd);
};

std::ostream &operator<<(std::ostream &os, const CCommand &x);


#endif //SEMWORK_CCOMMAND_H
