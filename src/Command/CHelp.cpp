#include <iostream>
#include "CHelp.h"

CHelp::CHelp(std::vector<std::shared_ptr<CCommand>> &commandList)
        : CCommand("help",
                   "help",
                   "print info about all commands"), m_CommandList(commandList) {}

void CHelp::validate(const std::vector<std::string>& args) const {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CHelp::execute() {
    for (const auto& command : m_CommandList)
        std::cout << *command << std::endl;
}