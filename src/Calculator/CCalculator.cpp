#include <iostream>
#include <sstream>
#include "CCalculator.h"
#include "../Command/CHelp.h"
#include "../Command/CExit.h"

CCalculator::CCalculator() {
    addCommand(std::make_shared<CHelp>(m_CommandList));
    addCommand(std::make_shared<CExit>(m_ExitFlag));
}

void CCalculator::run() {
    std::cout << "Welcome to Matrix Calculator!" << std::endl;

    while(!m_ExitFlag) {
        std::getline(std::cin, line);
        std::vector<std::string> args = parseLine();
        if (args.empty())
            continue;

        try {
            auto command = m_Commands.at(args[0]);
            command->validate(args);
            command->execute();

        } catch (std::logic_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void CCalculator::addCommand(const std::shared_ptr<CCommand>& command) {
    if (m_Commands.find(command->getName()) != m_Commands.end()) {
        std::cout << "Command " << command->getName() << " already exists.";
        return;
    }

    m_Commands[command->getName()] = command;
    m_CommandList.push_back(command);
}

std::vector<std::string> CCalculator::parseLine() const {
    std::vector<std::string> result;

    std::istringstream iss(line);
    for(std::string arg; iss >> arg; )
        result.push_back(arg);

    return result;
}
