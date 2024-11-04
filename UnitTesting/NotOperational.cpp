#include "NotOperational.h"
#include "Bad.h"
#include "Road.h"
#include <iostream>

NotOperational::NotOperational() {}

NotOperational::~NotOperational() {}

void NotOperational::upgrade(Road* road) {
    std::cout << "Upgrading road from Not Operational to Bad.\n";
    road->setState(std::make_unique<Bad>());
    road->resetYearsNotUpgraded();
}

void NotOperational::handleYear(Road* road) {
    std::cout << "Road is Not Operational. No changes this year.\n";
    // Since the road is not operational, do not degrade further.
}

std::string NotOperational::getStateName() const {
    return "Not Operational";
}

double NotOperational::getProductivity() const {
    return 0.0; 
}

double NotOperational::getSatisfaction() const {
    return 0.0;
}

double NotOperational::getUpgradeCost() const {
    return 40000.0; 
}