#ifndef STATSMEMENTO_H
#define STATSMEMENTO_H

#include "CityStats.h"

class StatsMemento {
private:
    CityStats state;
public:
    StatsMemento(const CityStats& s);
    CityStats getState() const;
};

#endif
