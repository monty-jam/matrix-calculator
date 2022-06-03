#include "CCommandHelp.h"

CCommandHelp::CCommandHelp(std::map<std::string, std::shared_ptr<CCommand>> &commands)
        : CCommand("help",
                   "help [COMMAND-NAME]",
                   "print info about given command"), m_Commands(commands) {}

int CCommandHelp::validate(const std::string& line) const {
    return 0;
}

std::shared_ptr<CMatrix> CCommandHelp::execute() {
    return nullptr;
}
