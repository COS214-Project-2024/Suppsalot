#ifndef BAD_H
#define BAD_H

#include "RoadState.h"
#include <string>

class Bad : public RoadState {
public:
    Bad();
    virtual ~Bad();

    virtual void upgrade(Road* road) override;

    virtual void handleYear(Road* road) override;

    virtual std::string getStateName() const override;

    virtual double getProductivity() const override;

    virtual double getSatisfaction() const override;

    virtual double getUpgradeCost() const override;
};

#endif 
