#include "CCommand.h"

CCommand::~CCommand() = default;

bool CCommand::isWrite() const {
    return !m_BackupName.empty();
}
