#include "Uber.h"
#include "UberAndBolt.h"
#include "PublicTransit.h"
#include <iostream>

Uber::Uber() {}

Uber::~Uber() {}

bool Uber::buyUber(PublicTransit* transit) {
    std::cout << "Uber is already purchased.\n";
    return false;
}

bool Uber::buyBolt(PublicTransit* transit) {
    transit->setState(std::make_unique<UberAndBolt>());
    std::cout << "Bolt purchased. Transitioning to UberAndBolt state.\n";
    return true;
}

std::string Uber::getStateName() const {
    return "Uber";
}

double Uber::getProductivity() const {
    return 1.2;
}

double Uber::getSatisfaction() const {
    return 60.0;
}
