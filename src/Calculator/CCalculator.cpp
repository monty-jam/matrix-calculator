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
#include "../Command/Basic/CDel.h"
#include "../Command/Math/CRank.h"
#include "../Command/Math/CDet.h"
#include "../Command/Math/CInv.h"
#include "../Command/Math/CAdj.h"
#include "../Command/Memory/CSave.h"
#include "../Command/Memory/CLoad.h"

CCalculator::CCalculator() {
    m_Commands["help"] = &CHelp::create;
    m_Commands["help-cmd"] = &CHelpCmd::create;
    m_Commands["exit"] = &CExit::create;
    m_Commands["vars"] = &CVars::create;
    m_Commands["del"] = &CDel::create;
    m_Commands["undo"] = &CUndo::create;

    m_Commands["scan"] = &CScan::create;
    m_Commands["print"] = &CPrint::create;
    m_Commands["save"] = &CSave::create;
    m_Commands["load"] = &CLoad::create;

    m_Commands["+"] = &CAdd::create;
    m_Commands["-"] = &CSub::create;
    m_Commands["*"] = &CMul::create;
    m_Commands["T"] = &CTrans::create;
    m_Commands["merge"] = &CMerge::create;
    m_Commands["cut"] = &CCut::create;

    m_Commands["gem"] = &CGem::create;
    m_Commands["rank"] = &CRank::create;
    m_Commands["det"] = &CDet::create;
    m_Commands["adj"] = &CAdj::create;
    m_Commands["inv"] = &CInv::create;

    for (const auto &command: m_Commands)
        m_Memory.addCommandName(command.first);
}

void CCalculator::run() {
    std::cout << "Welcome to Matrix Calculator!" << std::endl;

    while (!m_ExitFlag) {
        std::cout << "[MtxCalculator]:$ ";
        std::getline(std::cin, m_Line);

        try {
            std::deque<std::string> argv = parseLine();
            if (argv.empty())
                continue;

            if (m_Commands.find(argv[0]) == m_Commands.end())
                throw std::invalid_argument("Unknown command.");
            std::shared_ptr<CCommand> command = m_Commands.at(argv[0])(*this, m_Memory);

            argv.pop_front();
            std::vector<std::string> emptyRetv;
            command->call(argv, emptyRetv);

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
    for (std::string arg; iss >> arg;) {
        if (arg[0] == '~')
            throw std::invalid_argument("Arguments can't start with ~ symbol.");
        result.push_back(arg);
    }

    return result;
}

std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &)>
CCalculator::getCommand(const std::string &name) const {
    return m_Commands.at(name);
}
