#include "CCommand.h"

#include <iostream>
#include <utility>

CCommand::CCommand(std::string name, std::string format, std::string helpInfo)
        : name(std::move(name)),
          format(std::move(format)),
          helpInfo(std::move(helpInfo)) {}

std::string CCommand::getName() const {
    return name;
}

void CCommand::print(std::ostream &os) const {
    os << format << std::endl;
    os << '\t' << helpInfo;
}

std::ostream &operator<<(std::ostream &os, const CCommand &cmd) {
    cmd.print(os);
    return os;
}
