#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include "CCalculator.h"
#include "../Command/ReadBasic/CHelp.h"
#include "../Command/ReadBasic/CExit.h"
#include "../Command/ReadBasic/CVars.h"
#include "../Command/WriteMemory/CScan.h"
#include "../Command/ReadBasic/CPrint.h"
#include "../Command/WriteBasic/CAdd.h"
#include "../Command/WriteBasic/CSub.h"
#include "../Command/WriteBasic/CMul.h"
#include "../Command/WriteBasic/CTrans.h"
#include "../Command/WriteComplex/CMerge.h"
#include "../Command/WriteComplex/CCut.h"
#include "../Command/ReadBasic/CUndo.h"

CCalculator::CCalculator() {
    m_MakeShared["help"] = &CHelp::create; printInfo("help");
    m_MakeShared["exit"] = &CExit::create; printInfo("exit");
    m_MakeShared["vars"] = &CVars::create; printInfo("vars");
    m_MakeShared["print"] = &CPrint::create; printInfo("print");
    m_MakeShared["undo"] = &CUndo::create; printInfo("undo");

    m_MakeShared["scan"] = &CScan::create; printInfo("scan");
    m_MakeShared["+"] = &CAdd::create; printInfo("+");
    m_MakeShared["-"] = &CSub::create; printInfo("-");
    m_MakeShared["*"] = &CMul::create; printInfo("*");
    m_MakeShared["T"] = &CTrans::create; printInfo("T");
    m_MakeShared["merge"] = &CMerge::create; printInfo("merge");
    m_MakeShared["cut"] = &CCut::create; printInfo("cut");
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
            if (m_MakeShared.find(argv[0]) == m_MakeShared.end())
                throw std::invalid_argument("Unknown command.");
            std::shared_ptr<CCommand> command = m_MakeShared.at(argv[0])(*this, m_Memory);

            argv.pop_front();
            command->validate(argv);
            command->execute(argv);

            if (command->isWrite())
                m_History.push(command);

        } catch (int end) {
            break;
        } catch (std::logic_error &e) {
            std::cout << e.what() << std::endl;
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
        std::cout << "Command not found." << std::endl;
    }
}
