#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include "CCalculator.h"
#include "../Command/Common/CHelp.h"

CCalculator::CCalculator() {
    m_MakeShared["help"] = &CHelp::create;
//    addCommand(std::make_shared<CHelp>(m_CommandList));
//    addCommand(std::make_shared<CHelpCmd>(m_Commands));
//    addCommand(std::make_shared<CExit>(m_ExitFlag));
//    addCommand(std::make_shared<CVars>(m_Matrices));
//    addCommand(std::make_shared<CDel>(m_Matrices));

    for (const auto& command : m_MakeShared) {
        m_Memory.addCommandName(command.first);
    }
}

void CCalculator::run() {
    std::cout << "Welcome to Matrix Calculator!" << std::endl;

    while(true) {
        std::cout << "[MtxCalculator]:$ ";
        std::getline(std::cin, line);
        std::deque<std::string> argv = parseLine();
        if (argv.empty())
            continue;

        try {
            auto makeShared = m_MakeShared.at(argv[0]);
            std::shared_ptr<CCommand> command = makeShared(*this, m_Memory);
            argv.pop_front();
            command->validate(argv);
            command->execute(argv);

        } catch (int end) {
            break;
        } catch (std::logic_error& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

std::deque<std::string> CCalculator::parseLine() const {
    std::deque<std::string> result;

    std::istringstream iss(line);
    for(std::string arg; iss >> arg; )
        result.push_back(arg);

    return result;
}
