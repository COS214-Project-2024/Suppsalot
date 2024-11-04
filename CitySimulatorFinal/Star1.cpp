#include "Star1.h"
#include "Star2.h"
#include "TrainSystem.h"
#include <iostream>

Star1::Star1() {}

Star1::~Star1() {}

void Star1::upgrade(TrainSystem* train) {
    std::cout << "Upgrading train system from Star1 to Star2.\n";
    train->setState(std::make_unique<Star2>());
    train->resetYearsNotUpgraded();
}

void Star1::handleYear(TrainSystem* train) {
    train->incrementYearsNotUpgraded();
    std::cout << "Train system is in Star1 condition. Years not upgraded: " << train->getYearsNotUpgraded() << "\n";
    if (train->getYearsNotUpgraded() >= 3) {
        std::cout << "Train system has not been upgraded for 3 years. Degrading from Star1 to Star1.\n";
        train->resetYearsNotUpgraded();
    }
}

std::string Star1::getStateName() const {
    return "Star1";
}

double Star1::getProductivity() const {
    return 1.05;
}

double Star1::getSatisfaction() const {
    return 10.0;
}

double Star1::getUpgradeCost() const {
    return 75000.0;
}
