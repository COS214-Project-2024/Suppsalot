#ifndef TAXHISTORYMANAGER_H
#define TAXHISTORYMANAGER_H

#include "TaxMemento.h"
#include <vector>
#include <memory>

class TaxHistoryManager {
public:
    TaxHistoryManager() = default;
    ~TaxHistoryManager() = default;

    TaxHistoryManager(const TaxHistoryManager&) = delete;
    TaxHistoryManager& operator=(const TaxHistoryManager&) = delete;

    TaxHistoryManager(TaxHistoryManager&&) = default;
    TaxHistoryManager& operator=(TaxHistoryManager&&) = default;

    void addMemento(const TaxMemento& memento);

    const std::vector<TaxMemento>& getHistory() const;

private:
    std::vector<TaxMemento> history_;
};

#endif 
