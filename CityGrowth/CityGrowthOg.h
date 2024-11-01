#ifndef CITYGROWTHOG_H
#define CITYGROWTHOG_H

#include "CityStats.h"
#include "StatsMemento.h"
#include <memory>

class CityGrowthOg {
private:
    CityStats state;
public:
    void setState(const CityStats& s);
    CityStats getState() const;
    std::shared_ptr<StatsMemento> saveStateToMemento() const;
    void getStateFromMemento(std::shared_ptr<StatsMemento> m);
};

#endif
