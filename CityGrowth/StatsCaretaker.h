#ifndef STATSCARETAKER_H
#define STATSCARETAKER_H

#include "StatsMemento.h"
#include <vector>
#include <memory>

class StatsCaretaker {
private:
    std::vector<std::shared_ptr<StatsMemento>> mementos;
public:
    void addMemento(std::shared_ptr<StatsMemento> m);
    std::shared_ptr<StatsMemento> getMemento(int index) const;
    int getSize() const;
    std::vector<std::shared_ptr<StatsMemento>> getAllMementos() const;
};

#endif
