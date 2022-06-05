#include <iostream>
#include "CHistory.h"

CHistory::CHistory() = default;

void CHistory::push(std::shared_ptr<CCommand> &command) {
    m_History.push_back(command);
    if (m_History.size() > 10)
        m_History.pop_front();
}

void CHistory::pop() {
    if (!m_History.empty()) {
        m_History.back()->undo();
        m_History.pop_back();
    } else {
        std::cout << "Nothing to undo." << std::endl;
    }
}
