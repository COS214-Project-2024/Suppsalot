#include "CityGrowthOg.h"

void CityGrowthOg::setState(const CityStats& s) {
    state = s;
}

CityStats CityGrowthOg::getState() const {
    return state;
}

std::shared_ptr<StatsMemento> CityGrowthOg::saveStateToMemento() const {
    return std::make_shared<StatsMemento>(state);
}

void CityGrowthOg::getStateFromMemento(std::shared_ptr<StatsMemento> m) {
    state = m->getState();
}
