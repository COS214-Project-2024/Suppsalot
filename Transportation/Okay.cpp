#include "Okay.h"
#include "Good.h"
#include "Bad.h"
#include "Road.h"
#include <iostream>

Okay::Okay() {}

Okay::~Okay() {}

void Okay::upgrade(Road* road) {
    std::cout << "Upgrading road from Okay to Good.\n";
    road->setState(std::make_unique<Good>());
    road->resetYearsNotUpgraded();
}

void Okay::handleYear(Road* road) {
    road->incrementYearsNotUpgraded();
    std::cout << "Road is in Okay condition. Years not upgraded: " << road->getYearsNotUpgraded() << "\n";
    if (road->getYearsNotUpgraded() >= 3) {
        std::cout << "Road has not been upgraded for 3 years. Degrading from Okay to Bad.\n";
        road->setState(std::make_unique<Bad>());
        road->resetYearsNotUpgraded();
    }
}

std::string Okay::getStateName() const {
    return "Okay";
}

double Okay::getProductivity() const {
    return 1.0; 
}

double Okay::getSatisfaction() const {
    return 50.0;
}

double Okay::getUpgradeCost() const {
    return 140000.0; 
}