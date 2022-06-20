#ifndef SEMWORK_CMEMORY_H
#define SEMWORK_CMEMORY_H


#include <map>
#include <set>
#include <vector>
#include <memory>
#include "../Matrix/CMatrix.h"

/**
 * @brief Program's Receiver class.
 *
 * Stores names of available commands and matrices by their variable names, memory can be changed with public methods.
 */
class CMemory {
public:
    /**
     * @brief Constructs a Receiver object.
     */
    CMemory();

    /**
     * @brief Gets the set with all available commands.
     *
     * @return Set with all available commands.
     */
    std::set<std::string> getCommandNames() const;

    /**
     * @brief Checks if given command name is available in program.
     *
     * @param name Command name to check availability for.
     * @return true if command name is available.
     *         false if command name is unavailable.
     */
    bool doesCommandNameExist(const std::string &name) const;

    /**
     * @brief Gets the vector with all variable names, storing matrices.
     *
     * @return Vector with all variable names of stored matrices.
     */
    std::vector<std::string> getMatrixNames() const;

    /**
     * @brief Checks if given variable name of matrix exists.
     *
     * @param name Variable name to check.
     * @return true if variable exists.
     *         false if variable doesn't exist.
     */
    bool doesMatrixExist(const std::string &name) const;

    /**
     * @brief Gets the shared pointer on a matrix, stored in a variable with given name.
     *
     * @param name Variable name of matrix to get.
     * @return Shared Pointer on matrix by its variable name.
     */
    std::shared_ptr<CMatrix> getMatrix(const std::string &name) const;

    /**
     * @brief Adds command name to the m_CommandNames.
     *
     * @param name Command name to be added.
     */
    void addCommandName(const std::string &name);

    /**
     * @brief Adds and stores shared pointer of matrix to the map of variables with given variable name.
     *
     * @param name Desired name of variable.
     * @param mtx Shared pointer of matrix to store.
     */
    void addMatrix(const std::string &name, std::shared_ptr<CMatrix> mtx);

    /**
     * @brief Deletes the variable with stored matrix by name.
     *
     * @param name Name of variable to delete.
     */
    void deleteMatrix(const std::string &name);

private:
    /**
     * @brief Set of available command names.
     */
    std::set<std::string> m_CommandNames;

    /**
     * @brief Map of variables with stored matrix shared pointers in them.
     *
     * The key is the variable name, value is the shared pointer on matrix.
     */
    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;
};


#endif //SEMWORK_CMEMORY_H