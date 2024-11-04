#ifndef NOTOPERATIONAL_H
#define NOTOPERATIONAL_H

#include "RoadState.h"
#include <string>

class NotOperational : public RoadState {
public:
    NotOperational();
    virtual ~NotOperational();

    virtual void upgrade(Road* road) override;

    virtual void handleYear(Road* road) override;

    virtual std::string getStateName() const override;

    virtual double getProductivity() const override;

    virtual double getSatisfaction() const override;

    virtual double getUpgradeCost() const override;
};

#endif
