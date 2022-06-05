#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include "CCalculator.h"
#include "../Command/Read/CHelp.h"
#include "../Command/Read/CExit.h"
#include "../Command/Read/CVars.h"

CCalculator::CCalculator() {
    m_MakeShared["help"] = &CHelp::create; printInfo("help");
    m_MakeShared["exit"] = &CExit::create; printInfo("exit");
    m_MakeShared["vars"] = &CVars::create; printInfo("vars");
}

void CCalculator::run() {
    std::cout << "Welcome to Matrix Calculator!" << std::endl;

    while (!m_ExitFlag) {
        std::cout << "[MtxCalculator]:$ ";
        std::getline(std::cin, m_Line);
        std::deque<std::string> argv = parseLine();
        if (argv.empty())
            continue;

        try {
            std::shared_ptr<CCommand> command = m_MakeShared.at(argv[0])(*this, m_Memory);

            argv.pop_front();
            command->validate(argv);
            command->execute(argv);

            if (command->isWrite())
                m_History.push(command);

        } catch (int end) {
            break;
        } catch (std::logic_error &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "Bye Bye!" << std::endl;
}

std::deque<std::string> CCalculator::parseLine() const {
    std::deque<std::string> result;

    std::istringstream iss(m_Line);
    for (std::string arg; iss >> arg;)
        result.push_back(arg);

    return result;
}

void CCalculator::exit() {
    m_ExitFlag = true;
}

void CCalculator::undo() {
    m_History.pop();
}

void CCalculator::printInfo(const std::string& name) {
    try {
        std::shared_ptr<CCommand> command = m_MakeShared.at(name)(*this, m_Memory);
        command->printInfo();
        m_Memory.addCommandName(name);
    } catch (std::logic_error &e) {
        std::cerr << "Command not found." << std::endl;
    }
}
