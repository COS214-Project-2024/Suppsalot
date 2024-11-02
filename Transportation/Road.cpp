#include "Road.h"
#include "NotOperational.h"
#include "Bad.h"
#include "Okay.h"
#include "Good.h"
#include "Excellent.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Road::Road(double& budget)
    : currentState_(std::make_unique<NotOperational>()),
      yearsNotUpgraded_(0),
      cityBudget_(budget) 
{
    std::cout << "Initializing Road to Not Operational state.\n";
}

Road::~Road() = default;

void Road::upgradeRoad() {
    std::cout << "Attempting to upgrade the road...\n";
    double upgradeCost = currentState_->getUpgradeCost();
    if (cityBudget_ >= upgradeCost) {
        cityBudget_ -= upgradeCost;
        std::cout << "Upgrade cost of $" << upgradeCost << " deducted from city budget.\n";
        currentState_->upgrade(this);
        notify();
    }
    else {
        std::cout << "Insufficient funds to upgrade the road. Current Budget: $" << cityBudget_ << "\n";
    }
}

void Road::progressYear() {
    // std::cout << "Progressing to the next year...\n";
    currentState_->handleYear(this);
    std::cout << "Current Road State: " << getCurrentStateName() << "\n";
    std::cout << "City Budget: $" << cityBudget_ << "\n";
    std::cout << "Years Not Upgraded: " << yearsNotUpgraded_ << "\n\n";
    notify();
}


std::string Road::getCurrentStateName() const {
    return currentState_->getStateName();
}

double Road::getProductivity() const {
    return currentState_->getProductivity();
}

double Road::getSatisfaction() const {
    return currentState_->getSatisfaction();
}

double Road::getCityBudget() const {
    return cityBudget_;
}

void Road::adjustCityBudget(double amount) {
    cityBudget_ += amount;
    if (cityBudget_ < 0.0) {
        cityBudget_ = 0.0;
    }
}


void Road::setState(std::unique_ptr<RoadState> newState) {
    currentState_ = std::move(newState);
}

void Road::resetYearsNotUpgraded() {
    yearsNotUpgraded_ = 0;
}

void Road::incrementYearsNotUpgraded() {
    yearsNotUpgraded_++;
}

int Road::getYearsNotUpgraded() const {
    return yearsNotUpgraded_;
}
