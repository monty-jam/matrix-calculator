#include <iostream>
#include "CHelp.h"

CHelp::CHelp(std::map<std::string, std::shared_ptr<CCommand>> &commands)
        : CCommand("help",
                   "help",
                   "print info about all commands"), m_Commands(commands) {}

void CHelp::validate(const std::vector<std::string>& args) const {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CHelp::execute() {
    for (const auto& command : m_Commands)
        std::cout << *command.second << std::endl;
}
