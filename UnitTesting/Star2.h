#ifndef STAR2_H
#define STAR2_H

#include "TrainState.h"
#include <string>

class Star2 : public TrainState {
public:
    Star2();
    virtual ~Star2();
    virtual void upgrade(TrainSystem* train) override;
    virtual void handleYear(TrainSystem* train) override;
    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
    virtual double getUpgradeCost() const override;
};

#endif
