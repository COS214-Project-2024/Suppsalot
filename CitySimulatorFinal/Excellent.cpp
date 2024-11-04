#include "Excellent.h"
#include "Good.h"
#include "Road.h"
#include <iostream>

Excellent::Excellent() {}

Excellent::~Excellent() {}

void Excellent::upgrade(Road* road) {
    std::cout << "Road is already in Excellent condition. No further upgrades possible.\n";
}

void Excellent::handleYear(Road* road) {
    road->incrementYearsNotUpgraded();
    std::cout << "Road is in Excellent condition. Years not upgraded: " << road->getYearsNotUpgraded() << "\n";
    if (road->getYearsNotUpgraded() >= 3) {
        std::cout << "Road has not been upgraded for 3 years. Degrading from Excellent to Good.\n";
        road->setState(std::make_unique<Good>());
        road->resetYearsNotUpgraded();
    }
}

std::string Excellent::getStateName() const {
    return "Excellent";
}

double Excellent::getProductivity() const {
    return 1.5; 
}

double Excellent::getSatisfaction() const {
    return 100.0;
}

double Excellent::getUpgradeCost() const {
    return 50000.0; 
}