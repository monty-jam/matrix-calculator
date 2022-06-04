#include <iostream>
#include "CHelpCmd.h"

CHelpCmd::CHelpCmd(std::map<std::string, std::shared_ptr<CCommand>> &commands)
        : CCommand("helpcmd",
                   "helpcmd [COMMAND-NAME]",
                   "print info about given command"), m_Commands(commands) {}

void CHelpCmd::validate(const std::vector<std::string>& args) const {
    if (args.size() != 2)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CHelpCmd::execute(const std::vector<std::string> &args) {
    std::cout << *m_Commands.at(args[1]) << std::endl;
}