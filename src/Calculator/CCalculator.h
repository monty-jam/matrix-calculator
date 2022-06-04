#ifndef SEMESTRAL_CCALCULATOR_H
#define SEMESTRAL_CCALCULATOR_H


#include <string>
#include <memory>
#include <map>
#include "../Command/CCommand.h"

class CCalculator {
public:
    CCalculator();
    void run();

private:
    std::map<std::string, std::shared_ptr<CCommand>> m_Commands;

    std::vector<std::shared_ptr<CCommand>> m_CommandList;

    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;

    bool m_ExitFlag = false;

    std::string line;

    void addCommand(const std::shared_ptr<CCommand>& command);

    std::vector<std::string> parseLine() const;
};


#endif //SEMESTRAL_CCALCULATOR_H
