#ifndef SEMWORK_CHISTORY_H
#define SEMWORK_CHISTORY_H


#include <memory>
#include "../Command/CCommand.h"

/**
 * @brief Program's Command Buffer class.
 *
 * By storing sequence of commands can call their undo() methods to return Receiver memory to previous state.
 */
class CHistory {
public:
    CHistory();

    void push(std::shared_ptr<CCommand>& command);

    void pop();

private:
    std::deque<std::shared_ptr<CCommand>> m_History;
};


#endif //SEMWORK_CHISTORY_H
