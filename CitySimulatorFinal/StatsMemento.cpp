#include "StatsMemento.h"

StatsMemento::StatsMemento(const CityStats& s) : state(s) {}

CityStats StatsMemento::getState() const {
    return state;
}
