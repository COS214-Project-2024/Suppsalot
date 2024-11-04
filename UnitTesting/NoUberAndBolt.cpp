#include "NoUberAndBolt.h"
#include "Uber.h"
#include "Bolt.h"
#include "UberAndBolt.h"
#include "PublicTransit.h"
#include <iostream>

NoUberAndBolt::NoUberAndBolt() {}

NoUberAndBolt::~NoUberAndBolt() {}

bool NoUberAndBolt::buyUber(PublicTransit* transit) {
    transit->setState(std::make_unique<Uber>());
    std::cout << "Uber purchased. Transitioning to Uber state.\n";
    return true;
}

bool NoUberAndBolt::buyBolt(PublicTransit* transit) {
    transit->setState(std::make_unique<Bolt>());
    std::cout << "Bolt purchased. Transitioning to Bolt state.\n";
    return true;
}

std::string NoUberAndBolt::getStateName() const {
    return "NoUberAndBolt";
}

double NoUberAndBolt::getProductivity() const {
    return 1.0; 
}

double NoUberAndBolt::getSatisfaction() const {
    return 0.0;
}
