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
    CMemory();


    std::set<std::string> getCommandNames() const;

    bool doesCommandNameExist(const std::string &name) const;

    std::vector<std::string> getMatrixNames() const;

    bool doesMatrixExist(const std::string &name) const;

    std::shared_ptr<CMatrix> getMatrix(const std::string &name) const;

    void addCommandName(const std::string &name);

    void addMatrix(const std::string &name, std::shared_ptr<CMatrix> mtx);

    void deleteMatrix(const std::string &name);

private:
    std::set<std::string> m_CommandNames;

    std::map<std::string, std::shared_ptr<CMatrix>> m_Matrices;
};


#endif //SEMWORK_CMEMORY_H