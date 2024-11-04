#ifndef STAR1_H
#define STAR1_H

#include "TrainState.h"
#include <string>

class Star1 : public TrainState {
public:
    Star1();
    virtual ~Star1();
    virtual void upgrade(TrainSystem* train) override;
    virtual void handleYear(TrainSystem* train) override;
    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
    virtual double getUpgradeCost() const override;
};

#endif 
