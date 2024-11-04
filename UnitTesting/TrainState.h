#ifndef TRAINSTATE_H
#define TRAINSTATE_H

#include <string>

class TrainSystem;

class TrainState {
public:
    virtual ~TrainState() {}
    virtual void upgrade(TrainSystem* train) = 0;
    virtual void handleYear(TrainSystem* train) = 0;
    virtual std::string getStateName() const = 0;
    virtual double getProductivity() const = 0;
    virtual double getSatisfaction() const = 0;
    virtual double getUpgradeCost() const = 0;
};

#endif 
