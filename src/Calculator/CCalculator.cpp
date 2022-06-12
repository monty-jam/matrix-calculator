#include <iostream>
#include <sstream>
#include <functional>
#include <deque>
#include "CCalculator.h"
#include "../Command/Basic/CHelp.h"
#include "../Command/Basic/CExit.h"
#include "../Command/Basic/CVars.h"
#include "../Command/Memory/CScan.h"
#include "../Command/Memory/CPrint.h"
#include "../Command/Operation/CAdd.h"
#include "../Command/Operation/CSub.h"
#include "../Command/Operation/CMul.h"
#include "../Command/Operation/CTrans.h"
#include "../Command/Operation/CMerge.h"
#include "../Command/Operation/CCut.h"
#include "../Command/Basic/CUndo.h"
#include "../Command/Basic/CHelpCmd.h"
#include "../Command/Math/CGem.h"

CCalculator::CCalculator() {
    m_Commands["help"] = &CHelp::create;
    m_Commands["help-cmd"] = &CHelpCmd::create;
    m_Commands["exit"] = &CExit::create;
    m_Commands["vars"] = &CVars::create;
    m_Commands["undo"] = &CUndo::create;

    m_Commands["scan"] = &CScan::create;
    m_Commands["print"] = &CPrint::create;

    m_Commands["+"] = &CAdd::create;
    m_Commands["-"] = &CSub::create;
    m_Commands["*"] = &CMul::create;
    m_Commands["T"] = &CTrans::create;
    m_Commands["merge"] = &CMerge::create;
    m_Commands["cut"] = &CCut::create;

    m_Commands["gem"] = &CGem::create;

    for (const auto &command: m_Commands)
        m_Memory.addCommandName(command.first);
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
            if (m_Commands.find(argv[0]) == m_Commands.end())
                throw std::invalid_argument("Unknown command.");
            std::shared_ptr<CCommand> command = m_Commands.at(argv[0])(*this, m_Memory);

            argv.pop_front();
            command->call(argv);

            if (command->isWrite())
                m_History.push(command);

        } catch (std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "Bye Bye!" << std::endl;
}

void CCalculator::exit() {
    m_ExitFlag = true;
}

void CCalculator::undo() {
    m_History.pop();
}

std::deque<std::string> CCalculator::parseLine() const {
    std::deque<std::string> result;

    std::istringstream iss(m_Line);
    for (std::string arg; iss >> arg;)
        result.push_back(arg);

    return result;
}

std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &)>
CCalculator::getCommand(const std::string &name) const {
    return m_Commands.at(name);
}
