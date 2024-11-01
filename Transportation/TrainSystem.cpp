#include "TrainSystem.h"
#include "Star1.h"
#include "Star2.h"
#include "Star3.h"
#include "Star4.h"
#include "Star5.h"
#include <iostream>

TrainSystem::TrainSystem(double& budget)
    : currentState_(std::make_unique<Star1>()),
      yearsNotUpgraded_(0),
      cityBudget_(budget)
{
    std::cout << "Initializing Train System to Star1 state.\n";
}

TrainSystem::~TrainSystem() = default;

void TrainSystem::upgradeTrainSystem() {
    std::cout << "Attempting to upgrade the train system...\n";
    double upgradeCost = currentState_->getUpgradeCost();
    if (cityBudget_ >= upgradeCost) {
        cityBudget_ -= upgradeCost;
        std::cout << "Upgrade cost of $" << upgradeCost << " deducted from city budget.\n";
        currentState_->upgrade(this);
        notify();
    }
    else {
        std::cout << "Insufficient funds to upgrade the train system. Current Budget: $" << cityBudget_ << "\n";
    }
}

void TrainSystem::progressYear() {
    std::cout << "Progressing to the next year...\n";
    currentState_->handleYear(this);
    std::cout << "Current Train System State: " << getCurrentStateName() << "\n";
    std::cout << "City Budget: $" << cityBudget_ << "\n";
    std::cout << "Years Not Upgraded: " << yearsNotUpgraded_ << "\n\n";
    notify();
}

std::string TrainSystem::getCurrentStateName() const {
    return currentState_->getStateName();
}

double TrainSystem::getProductivity() const {
    return currentState_->getProductivity();
}

double TrainSystem::getSatisfaction() const {
    return currentState_->getSatisfaction();
}

double TrainSystem::getCityBudget() const {
    return cityBudget_;
}

void TrainSystem::adjustCityBudget(double amount) {
    cityBudget_ += amount;
    if (cityBudget_ < 0.0) {
        cityBudget_ = 0.0;
    }
}

void TrainSystem::setState(std::unique_ptr<TrainState> newState) {
    currentState_ = std::move(newState);
}

void TrainSystem::resetYearsNotUpgraded() {
    yearsNotUpgraded_ = 0;
}

void TrainSystem::incrementYearsNotUpgraded() {
    yearsNotUpgraded_++;
}

int TrainSystem::getYearsNotUpgraded() const {
    return yearsNotUpgraded_;
}
