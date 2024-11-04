#ifndef STAR3_H
#define STAR3_H

#include "TrainState.h"
#include <string>

class Star3 : public TrainState {
public:
    Star3();
    virtual ~Star3();
    virtual void upgrade(TrainSystem* train) override;
    virtual void handleYear(TrainSystem* train) override;
    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
    virtual double getUpgradeCost() const override;
};

#endif
