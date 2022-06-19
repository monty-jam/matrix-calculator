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
    /**
     * @brief Constructs a Command Buffer instance.
     */
    CHistory();

    /**
     * @brief Pushes new command to the back of called commands' deque.
     *
     * Command deque can't contain more than 10 last commands, and will clear the deque with new commands adding.
     */
    void push(std::shared_ptr<CCommand>& command);

    /**
     * @brief Pops the latest called command and undoes its execution.
     *
     * Can't pop if deque is empty.
     */
    void pop();

private:
    /**
     * @brief Deque, storing commands in the sequence of their calls.
     */
    std::deque<std::shared_ptr<CCommand>> m_History;
};


#endif //SEMWORK_CHISTORY_H
