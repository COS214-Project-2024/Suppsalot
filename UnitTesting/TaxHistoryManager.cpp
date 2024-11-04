#include "TaxHistoryManager.h"

void TaxHistoryManager::addMemento(const TaxMemento& memento) {
    history_.push_back(memento);
}

const std::vector<TaxMemento>& TaxHistoryManager::getHistory() const {
    return history_;
}
