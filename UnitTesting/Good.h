#ifndef GOOD_H
#define GOOD_H

#include "RoadState.h"
#include <string>

class Good : public RoadState {
public:
    Good();
    virtual ~Good();

    virtual void upgrade(Road* road) override;

    virtual void handleYear(Road* road) override;

    virtual std::string getStateName() const override;

    virtual double getProductivity() const override;

    virtual double getSatisfaction() const override;

    virtual double getUpgradeCost() const override;
};

#endif 
