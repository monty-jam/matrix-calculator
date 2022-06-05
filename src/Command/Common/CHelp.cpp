#include <iostream>
#include <deque>
#include "CHelp.h"

CHelp::CHelp(CMemory& memory)
        : CCommand(memory) {}

std::shared_ptr<CCommand> CHelp::create(CMemory& memory) {
    memory.addCommandInfo("help",
                          "print information about all available commands");
    return std::make_shared<CHelp>(memory);
}

void CHelp::validate(const std::deque<std::string> &argv) const {
    if (!argv.empty())
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CHelp::execute(const std::deque<std::string> &args) {
    std::cout << m_Memory.getCommandInfo() << std::endl;
}