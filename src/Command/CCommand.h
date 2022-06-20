#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include <map>
#include <vector>
#include <deque>
#include "../Calculator/CMemory.h"

/**
 * @brief Executable Command parent class.
 *
 * Each command is defined by name and vector of arguments' types. Commands are called from CCalculator.
 * CCommand can validate arguments and create a backup of memory that is going to change, while execution is
 * implemented by each class child differently.
 */
class CCommand {
public:
    /**
     * @brief Constructs command with given details, links it with CMemory Receiver instance, and sets the m_IsWrite
     * flag (command is Write if it overwrites/creates the result variable, or if it's a delete command).
     *
     * @param memory instance of Receiver class.
     * @param name Command name.
     * @param argFormat Vector of command arguments' types.
     * @param helpInfo Detailed command description.
     */
    CCommand(CMemory &memory, std::string name, std::vector<std::string> argFormat, std::string helpInfo);

    virtual ~CCommand();

    /**
     * @brief Calls the command, by validating syntax errors in arguments from input, creating a command backup (if
     * command has flag m_IsWrite set on true, i.e. changes program memory by execution) and executing implementation,
     * that is created in subclasses.
     *
     * @param argv Arguments Vector from user input.
     * @param retv Return Vector, used to call commands inside another commands and send values to each other.
     */
    void call(const std::deque<std::string> &argv, std::vector<std::string> &retv);

    /**
     * @brief Returns flag, if command changes program memory.
     *
     * @return true If it is a write command.
     *         false If it is a read command (doesn't change program memory).
     */
    bool isWrite() const;

    /**
     * @brief Undoes its execution, returning program to state before command was done, i.e. gives to the matrix
     * variable its previous value.
     */
    void undo();

protected:
    /**
     * @brief Reference to CMemory Receiver instance.
     */
    CMemory &m_Memory;

    /**
     * @brief Executes the command instructions, which are implemented in CCommand subclasses.
     *
     * @note Syntax of given arguments in argv shouldn't be checked in implementation, because it is already checked by
     * validate method.
     * @param argv Arguments Vector from user input.
     * @param retv Return Vector, used to call commands inside another commands and send values to each other.
     */
    virtual void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) = 0;

private:
    /**
     * @brief Command name.
     */
    std::string m_Name;
    /**
     * @brief Vector of arguments' formats.
     */
    std::vector<std::string> m_ArgFormat;
    /**
     * @brief Detailed command description.
     */
    std::string m_HelpInfo;

    /**
     * @brief Flag, that determines, whether the command changes program's memory or not.
     */
    bool m_IsWrite;
    /**
     * @brief Name of a variable, which will be changed/created after this command execution.
     */
    std::string m_BackupName;
    /**
     * @brief Shared pointer of a matrix, which was stored in the result variable name before command execution.
     */
    std::shared_ptr<CMatrix> m_BackupMatrix = nullptr;

    /**
     * @brief Validates syntax of command arguments from input.
     *
     * @param argv Arguments Vector from user input.
     * @throw std::invalid_argument Invalid amount of arguments, variable/command is not found, incorrect data types.
     */
    void validate(const std::deque<std::string> &argv) const;

    /**
     * @brief Saves backup to the m_BackupName and m_BackupMatrix, if the m_IsWrite is true (Command changes program
     * memory).
     *
     * @param argv Arguments Vector from user input.
     */
    void backup(const std::deque<std::string> &argv);

    /**
     * @brief Prints command name, arguments format and description to the output stream.
     *
     * @param os Output stream to which command details will be printed.
     */
    void print(std::ostream &os) const;

    /**
     * @brief Operator for printing the command to the output stream.
     *
     * @param os Output stream to which command details will be printed.
     * @param cmd Command that needs to be printed.
     * @return Same output stream but with a command details printed.
     */
    friend std::ostream &operator<<(std::ostream &os, const CCommand &cmd);
};


#endif //SEMWORK_CCOMMAND_H
