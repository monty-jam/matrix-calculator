#ifndef SEMESTRAL_CCALCULATOR_H
#define SEMESTRAL_CCALCULATOR_H


#include <string>
#include <memory>
#include <functional>
#include "CMemory.h"
#include "CHistory.h"

/**
 * @brief Program's Client class.
 *
 * Contains instances of CMemory (Receiver) and CHistory (Command Buffer), reads commands from input and calls them,
 * catches exceptions inside commands' calls. Has static methods for relative comparison of doubles.
 */
class CCalculator {
public:
    CCalculator();

    void run();

    void exit();

    void undo();

    std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &)> getCommand(const std::string &name) const;

    static bool doubleEquals(double lhs, double rhs);

    static bool doubleNonEquals(double lhs, double rhs);

private:
    std::map<std::string,
            // Function pointer that returns a shared_ptr<CCommand> and takes CCalculator& and CMemory&
            std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &) >> m_Commands;

    CMemory m_Memory;

    CHistory m_History;

    std::string m_Line;

    std::deque<std::string> parseLine() const;

    bool m_ExitFlag = false;
};


#endif //SEMESTRAL_CCALCULATOR_H
