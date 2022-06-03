#ifndef SEMESTRAL_CCALCULATOR_H
#define SEMESTRAL_CCALCULATOR_H


#include <string>
#include <memory>
#include <map>
#include "../Command/CCommand.h"

class CCalculator {
public:
    CCalculator() = default;
    void run();

private:
    std::map<std::string, std::shared_ptr<CCommand>> m_Commands;

    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;

    void readInput();
};


#endif //SEMESTRAL_CCALCULATOR_H
