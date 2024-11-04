#include "Star5.h"
#include "Star4.h"
#include "TrainSystem.h"
#include <iostream>

Star5::Star5() {}

Star5::~Star5() {}

void Star5::upgrade(TrainSystem* train) {
    std::cout << "Train system is already at Star5. No further upgrades possible.\n";
    double upgradeCost = getUpgradeCost();
    if (train->getCityBudget() >= upgradeCost) {
        train->adjustCityBudget(-upgradeCost);
        std::cout << "Upgrade cost of $" << upgradeCost << " deducted from city budget.\n";
    }
    else {
        std::cout << "Insufficient funds to pay the upgrade cost of $" << upgradeCost << ".\n";
    }
}

void Star5::handleYear(TrainSystem* train) {
    train->incrementYearsNotUpgraded();
    std::cout << "Train system is in Star5 condition. Years not upgraded: " << train->getYearsNotUpgraded() << "\n";
    if (train->getYearsNotUpgraded() >= 3) {
        std::cout << "Train system has not been upgraded for 3 years. Degrading from Star5 to Star4.\n";
        train->setState(std::make_unique<Star4>());
        train->resetYearsNotUpgraded();
    }
}

std::string Star5::getStateName() const {
    return "Star5";
}

double Star5::getProductivity() const {
    return 1.40;
}

double Star5::getSatisfaction() const {
    return 100.0;
}

double Star5::getUpgradeCost() const {
    return 250000.0;
}
