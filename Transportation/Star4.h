#ifndef STAR4_H
#define STAR4_H

#include "TrainState.h"
#include <string>

class Star4 : public TrainState {
public:
    Star4();
    virtual ~Star4();
    virtual void upgrade(TrainSystem* train) override;
    virtual void handleYear(TrainSystem* train) override;
    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
    virtual double getUpgradeCost() const override;
};

#endif 
