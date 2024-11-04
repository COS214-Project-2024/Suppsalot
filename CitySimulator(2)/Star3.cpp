#include "Star3.h"
#include "Star4.h"
#include "Star2.h"
#include "TrainSystem.h"
#include <iostream>

Star3::Star3() {}

Star3::~Star3() {}

void Star3::upgrade(TrainSystem* train) {
    std::cout << "Upgrading train system from Star3 to Star4.\n";
    train->setState(std::make_unique<Star4>());
    train->resetYearsNotUpgraded();
}

void Star3::handleYear(TrainSystem* train) {
    train->incrementYearsNotUpgraded();
    std::cout << "Train system is in Star3 condition. Years not upgraded: " << train->getYearsNotUpgraded() << "\n";
    if (train->getYearsNotUpgraded() >= 3) {
        std::cout << "Train system has not been upgraded for 3 years. Degrading from Star3 to Star2.\n";
        train->setState(std::make_unique<Star2>());
        train->resetYearsNotUpgraded();
    }
}

std::string Star3::getStateName() const {
    return "Star3";
}

double Star3::getProductivity() const {
    return 1.20;
}

double Star3::getSatisfaction() const {
    return 50.0;
}

double Star3::getUpgradeCost() const {
    return 150000.0;
}
