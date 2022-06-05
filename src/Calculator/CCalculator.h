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

    void exit();

    void undo();

private:
    std::map<std::string,
            // Function pointer that returns a shared_ptr<CCommand> and takes CCalculator& and CMemory&
            std::shared_ptr<CCommand> (*)(CCalculator &, CMemory &)> m_MakeShared;

    CMemory m_Memory;

    CHistory m_History;

    std::string m_Line;

    std::deque<std::string> parseLine() const;

    bool m_ExitFlag = false;

    void printInfo(const std::string& name);
};


#endif //SEMESTRAL_CCALCULATOR_H
