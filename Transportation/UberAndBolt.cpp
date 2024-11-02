#include "UberAndBolt.h"
#include "PublicTransit.h"
#include <iostream>

UberAndBolt::UberAndBolt() {}

UberAndBolt::~UberAndBolt() {}

bool UberAndBolt::buyUber(PublicTransit* transit) {
    std::cout << "Uber is already purchased.\n";
    return false;
}

bool UberAndBolt::buyBolt(PublicTransit* transit) {
    std::cout << "Bolt is already purchased.\n";
    return false;
}

std::string UberAndBolt::getStateName() const {
    return "UberAndBolt";
}

double UberAndBolt::getProductivity() const {
    return 1.4;
}

double UberAndBolt::getSatisfaction() const {
    return 100.0;
}
