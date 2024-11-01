#include "StatsCaretaker.h"

void StatsCaretaker::addMemento(std::shared_ptr<StatsMemento> m) {
    mementos.push_back(m);
}

std::shared_ptr<StatsMemento> StatsCaretaker::getMemento(int index) const {
    if(index >= 0 && index < mementos.size())
        return mementos[index];
    return nullptr;
}

int StatsCaretaker::getSize() const {
    return mementos.size();
}

std::vector<std::shared_ptr<StatsMemento>> StatsCaretaker::getAllMementos() const {
    return mementos;
}
