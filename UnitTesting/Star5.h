#ifndef STAR5_H
#define STAR5_H

#include "TrainState.h"
#include <string>

class Star5 : public TrainState {
public:
    Star5();
    virtual ~Star5();
    virtual void upgrade(TrainSystem* train) override;
    virtual void handleYear(TrainSystem* train) override;
    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
    virtual double getUpgradeCost() const override;
};

#endif 
