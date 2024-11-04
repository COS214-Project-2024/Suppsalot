#ifndef TRAINSYSTEM_H
#define TRAINSYSTEM_H

#include "TrainState.h"
#include "Subject.h"
#include <memory>
#include <string>

class TrainSystem : public Subject {
public:
    TrainSystem(double& budget);
    ~TrainSystem();

    void upgradeTrainSystem();
    void progressYear();
    std::string getCurrentStateName() const;
    double getProductivity() const;
    double getSatisfaction() const;
    double getCityBudget() const;
    void adjustCityBudget(double amount);
    void setState(std::unique_ptr<TrainState> newState);
    void resetYearsNotUpgraded();
    void incrementYearsNotUpgraded();
    int getYearsNotUpgraded() const;

private:
    std::unique_ptr<TrainState> currentState_;
    int yearsNotUpgraded_;
    double& cityBudget_;
};

#endif 
