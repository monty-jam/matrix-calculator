#ifndef SEMWORK_CCOMMAND_H
#define SEMWORK_CCOMMAND_H


#include <string>
#include <map>
#include <vector>
#include <deque>
#include "../Calculator/CMemory.h"

/**
 * @brief Executable command parent class, each command is defined by name and list of arguments and called from CCalculator.
 * CCommand can validate arguments and create a backup of memory that is going to change, while execution is implemented by each class child differently.
 */
class CCommand {
public:
    CCommand(CMemory &memory, std::string name, std::vector<std::string> argFormat, std::string helpInfo);

    virtual ~CCommand();

    void call(const std::deque<std::string> &argv, std::vector<std::string> &retv);

    bool isWrite() const;

    void undo();

protected:
    CMemory &m_Memory;

    virtual void execute(const std::deque<std::string> &argv, std::vector<std::string> &retv) = 0;

    std::string randomName() const;

private:
    std::string m_Name;
    std::vector<std::string> m_ArgFormat;
    std::string m_HelpInfo;

    bool m_IsWrite;
    std::string m_BackupName;
    std::shared_ptr<CMatrix> m_BackupMatrix = nullptr;

    void validate(const std::deque<std::string> &argv) const;

    void backup(const std::deque<std::string> &argv);

    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const CCommand &cmd);
};


#endif //SEMWORK_CCOMMAND_H
