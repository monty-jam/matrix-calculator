#ifndef SEMESTRAL_CCALCULATOR_H
#define SEMESTRAL_CCALCULATOR_H


#include <string>
#include <memory>
#include "CMemory.h"
#include "CHistory.h"

class CCalculator {
public:
    CCalculator();

    void run();

private:
    std::map<std::string,
            // Function pointer that returns a shared_ptr<CCommand> and takes CMemory&
            std::shared_ptr<CCommand> (*)(CMemory &)> m_MakeShared;

    CMemory m_Memory;

    CHistory m_History;

    std::string line;

    std::deque<std::string> parseLine() const;
};


#endif //SEMESTRAL_CCALCULATOR_H
