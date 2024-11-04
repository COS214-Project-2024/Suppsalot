#ifndef ROAD_H
#define ROAD_H

#include "RoadState.h"
#include "Subject.h"
#include <memory>
#include <string>

class Road : public Subject {
public:
    Road(double& budget);
    ~Road();

    void upgradeRoad();
    void progressYear();
    std::string getCurrentStateName() const;
    double getProductivity() const;
    double getSatisfaction() const;
    double getCityBudget() const;
    void adjustCityBudget(double amount);
    void setState(std::unique_ptr<RoadState> newState);
    void resetYearsNotUpgraded();
    void incrementYearsNotUpgraded();
    int getYearsNotUpgraded() const;

private:
    std::unique_ptr<RoadState> currentState_;
    int yearsNotUpgraded_;
    double& cityBudget_;
};

#endif
