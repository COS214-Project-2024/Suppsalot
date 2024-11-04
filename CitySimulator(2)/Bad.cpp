#include "Bad.h"
#include "Okay.h"
#include "NotOperational.h"
#include "Road.h"
#include <iostream>

Bad::Bad() {}

Bad::~Bad() {}

void Bad::upgrade(Road* road) {
    std::cout << "Upgrading road from Bad to Okay.\n";
    road->setState(std::make_unique<Okay>());
    road->resetYearsNotUpgraded();
}

void Bad::handleYear(Road* road) {
    road->incrementYearsNotUpgraded();
    std::cout << "Road is in Bad condition. Years not upgraded: " << road->getYearsNotUpgraded() << "\n";
    if (road->getYearsNotUpgraded() >= 3) {
        std::cout << "Road has not been upgraded for 3 years. Degrading from Bad to Not Operational.\n";
        road->setState(std::make_unique<NotOperational>());
        road->resetYearsNotUpgraded();
    }
}

std::string Bad::getStateName() const {
    return "Bad";
}

double Bad::getProductivity() const {
    return 0.5; 
}

double Bad::getSatisfaction() const {
    return 25.0;
}

double Bad::getUpgradeCost() const {
    return 80000.0;
}