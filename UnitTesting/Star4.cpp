#include "Star4.h"
#include "Star5.h"
#include "Star3.h"
#include "TrainSystem.h"
#include <iostream>

Star4::Star4() {}

Star4::~Star4() {}

void Star4::upgrade(TrainSystem* train) {
    std::cout << "Upgrading train system from Star4 to Star5.\n";
    train->setState(std::make_unique<Star5>());
    train->resetYearsNotUpgraded();
}

void Star4::handleYear(TrainSystem* train) {
    train->incrementYearsNotUpgraded();
    std::cout << "Train system is in Star4 condition. Years not upgraded: " << train->getYearsNotUpgraded() << "\n";
    if (train->getYearsNotUpgraded() >= 3) {
        std::cout << "Train system has not been upgraded for 3 years. Degrading from Star4 to Star3.\n";
        train->setState(std::make_unique<Star3>());
        train->resetYearsNotUpgraded();
    }
}

std::string Star4::getStateName() const {
    return "Star4";
}

double Star4::getProductivity() const {
    return 1.30;
}

double Star4::getSatisfaction() const {
    return 70.0;
}

double Star4::getUpgradeCost() const {
    return 200000.0;
}
