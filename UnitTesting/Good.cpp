#include "Good.h"
#include "Excellent.h"
#include "Okay.h"
#include "Road.h"
#include <iostream>

Good::Good() {}

Good::~Good() {}

void Good::upgrade(Road* road) {
    std::cout << "Upgrading road from Good to Excellent.\n";
    road->setState(std::make_unique<Excellent>());
    road->resetYearsNotUpgraded();
}

void Good::handleYear(Road* road) {
    road->incrementYearsNotUpgraded();
    std::cout << "Road is in Good condition. Years not upgraded: " << road->getYearsNotUpgraded() << "\n";
    if (road->getYearsNotUpgraded() >= 3) {
        std::cout << "Road has not been upgraded for 3 years. Degrading from Good to Okay.\n";
        road->setState(std::make_unique<Okay>());
        road->resetYearsNotUpgraded();
    }
}

std::string Good::getStateName() const {
    return "Good";
}

double Good::getProductivity() const {
    return 1.2; 
}

double Good::getSatisfaction() const {
    return 75.0;
}

double Good::getUpgradeCost() const {
    return 170000.0;
}