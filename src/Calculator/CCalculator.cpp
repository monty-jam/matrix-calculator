#include <iostream>
#include <sstream>
#include "CCalculator.h"
#include "../Command/Common/CHelp.h"
#include "../Command/Common/CExit.h"
#include "../Command/Common/CHelpCmd.h"
#include "../Command/Common/CVars.h"
#include "../Command/Common/CDel.h"

CCalculator::CCalculator() {
    addCommand(std::make_shared<CHelp>(m_CommandList));
    addCommand(std::make_shared<CHelpCmd>(m_Commands));
    addCommand(std::make_shared<CExit>(m_ExitFlag));
    addCommand(std::make_shared<CVars>(m_Matrices));
    addCommand(std::make_shared<CDel>(m_Matrices));
}

void CCalculator::run() {
    std::cout << "Welcome to Matrix Calculator!" << std::endl;

    while(!m_ExitFlag) {
        std::cout << "[MtxCalculator]:$ ";
        std::getline(std::cin, line);
        std::vector<std::string> args = parseLine();
        if (args.empty())
            continue;

        try {
            auto command = m_Commands.at(args[0]);
            command->validate(args);
            command->execute(args);

        } catch (std::logic_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void CCalculator::addCommand(const std::shared_ptr<CCommand>& command) {
    if (m_Commands.find(command->getName()) != m_Commands.end()) {
        std::cout << "Command " << command->getName() << " already exists." << std::endl;
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
