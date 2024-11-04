#ifndef OKAY_H
#define OKAY_H

#include "RoadState.h"
#include <string>

class Okay : public RoadState {
public:
    Okay();
    virtual ~Okay();

    virtual void upgrade(Road* road) override;

    virtual void handleYear(Road* road) override;

    virtual std::string getStateName() const override;

    virtual double getProductivity() const override;

    virtual double getSatisfaction() const override;

    virtual double getUpgradeCost() const override;
};

#endif 
