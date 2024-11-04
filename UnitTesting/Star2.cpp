#include "Star2.h"
#include "Star3.h"
#include "Star1.h"
#include "TrainSystem.h"
#include <iostream>

Star2::Star2() {}

Star2::~Star2() {}

void Star2::upgrade(TrainSystem* train) {
    std::cout << "Upgrading train system from Star2 to Star3.\n";
    train->setState(std::make_unique<Star3>());
    train->resetYearsNotUpgraded();
}

void Star2::handleYear(TrainSystem* train) {
    train->incrementYearsNotUpgraded();
    std::cout << "Train system is in Star2 condition. Years not upgraded: " << train->getYearsNotUpgraded() << "\n";
    if (train->getYearsNotUpgraded() >= 3) {
        std::cout << "Train system has not been upgraded for 3 years. Degrading from Star2 to Star1.\n";
        train->setState(std::make_unique<Star1>());
        train->resetYearsNotUpgraded();
    }
}

std::string Star2::getStateName() const {
    return "Star2";
}

double Star2::getProductivity() const {
    return 1.10;
}

double Star2::getSatisfaction() const {
    return 30.0;
}

double Star2::getUpgradeCost() const {
    return 100000.0;
}
