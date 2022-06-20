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
    /**
     * @brief Constructs a Client instance, initializes all available commands in the program to the m_Commands map,
     * also saves command names to m_Memory Receiver instance.
     */
    CCalculator();

    /**
     * @brief Method called by main, starts the program.
     *
     * Run of program represented as a loop of getting the user's command from input and calling it with gotten
     * arguments (exceptions from command call will be catched and printed). Write commands will be added to the
     * CHistory's deque.
     *
     * @note When getting EOF while parsing the user command, exits the program.
     */
    void run();

    /**
     * @brief Changes m_ExitFlag on true to stop program run loop.
     */
    void exit();

    /**
     * @brief Changes the Command Buffer history, and restores the backup of the last called command.
     */
    void undo();

    /**
     * @brief Getter from a map of function pointers, pointing on commands' static create methods.
     *
     * @param name Name of desired command.
     * @return Function pointer, pointing on a desired command's static create method.
     */
    std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &)> getCommand(const std::string &name) const;

    /**
     * @brief Relative equality check of two values of type double.
     *
     * @param lhs First double value.
     * @param rhs Second double value.
     * @return true if values are approximately equal to each other.
     *         false if values are not approximately equal.
     */
    static bool doubleEquals(double lhs, double rhs);

    /**
     * @brief Relative non-equality check of two values of type double.
     *
     * @param lhs First double value.
     * @param rhs Second double value.
     * @return true if values are not approximately equal to each other.
     *         false if values are approximately equal.
     */
    static bool doubleNonEquals(double lhs, double rhs);

private:
    /**
     * @brief Map of all program command types.
     *
     * The key is a command name, value is a pointer to static command method to create a shared pointer of this
     * command's type.
     */
    std::map<std::string,
            // Function pointer that returns a shared_ptr<CCommand> and takes CCalculator& and CMemory&
            std::function<std::shared_ptr<CCommand>(CCalculator &, CMemory &) >> m_Commands;

    /**
     * @brief Receiver class.
     */
    CMemory m_Memory;

    /**
     * @brief Command Buffer class.
     */
    CHistory m_History;

    /**
     * @brief Flag, changed by exit() method, that stops the while loop of running program.
     */
    bool m_ExitFlag = false;

    /**
     * @brief Line, saved by getline, and parsed via istringstream.
     */
    std::string m_Line;

    /**
     * @brief Parses m_Line for separated string using istringstream.
     * @throw  std::invalid_argument If any argument starts with the ~ symbol (which is restricted by program rules).
     * @return Deque of parsed arguments
     */
    std::deque<std::string> parseLine() const;
};


#endif //SEMESTRAL_CCALCULATOR_H
