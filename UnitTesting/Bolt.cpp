#include "Bolt.h"
#include "UberAndBolt.h"
#include "PublicTransit.h"
#include <iostream>

Bolt::Bolt() {}

Bolt::~Bolt() {}

bool Bolt::buyUber(PublicTransit* transit) {
    transit->setState(std::make_unique<UberAndBolt>());
    std::cout << "Uber purchased. Transitioning to UberAndBolt state.\n";
    return true;
}

bool Bolt::buyBolt(PublicTransit* transit) {
    std::cout << "Bolt is already purchased.\n";
    return false;
}

std::string Bolt::getStateName() const {
    return "Bolt";
}

double Bolt::getProductivity() const {
    return 1.2;
}

double Bolt::getSatisfaction() const {
    return 40.0;
}
