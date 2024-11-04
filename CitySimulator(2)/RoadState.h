#ifndef ROADSTATE_H
#define ROADSTATE_H

#include <string>

//forward declaration
class Road;

class RoadState {
public:
    virtual ~RoadState() {}

    virtual void upgrade(Road* road) = 0;

    virtual void handleYear(Road* road) = 0;

    virtual std::string getStateName() const = 0;

    virtual double getProductivity() const = 0;

    virtual double getSatisfaction() const = 0;

    virtual double getUpgradeCost() const = 0;
};

#endif 
