#ifndef SEMWORK_CHISTORY_H
#define SEMWORK_CHISTORY_H


#include <memory>
#include "../Command/CCommand.h"

class CHistory {
public:
    CHistory();

    void push(std::shared_ptr<CCommand>& command) {
        m_History.push_back(command);
    }

    void pop() {
        m_History.pop_back();
    }

private:
    std::vector<std::shared_ptr<CCommand>> m_History;
};


#endif //SEMWORK_CHISTORY_H
