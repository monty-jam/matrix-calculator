#include <iostream>
#include "CExit.h"

CExit::CExit(bool &exitFlag)
        : CCommand("exit",
                   "exit",
                   "leave the program"), m_ExitFlag(exitFlag) {}

void CExit::validate(const std::vector<std::string> &args) const {
    if (args.size() != 1)
        throw std::invalid_argument("Invalid amount of arguments.");
}

void CExit::execute() {
    std::cout << "Bye Bye!" << std::endl;
    m_ExitFlag = true;
}
