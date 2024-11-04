#include "TrainSystem.h"
#include "Star1.h"
#include "Star2.h"
#include "Star3.h"
#include "Star4.h"
#include "Star5.h"
#include <iostream>

/**
 * @file TrainSystem.cpp
 * @brief Implementation of the TrainSystem class, managing train system upgrades and state transitions.
 */

/**
 * @class TrainSystem
 * @brief Manages the train system's state, budget, and annual progression.
 * 
 * The TrainSystem class handles upgrading and transitioning through different states, with each state impacting productivity,
 * satisfaction, and city budget. It also tracks years without upgrades and notifies observers of changes.
 */

/**
 * @brief Constructs a TrainSystem object, initializing it to the Star1 state.
 * @param budget Reference to the city budget, used to manage upgrade costs.
 */
TrainSystem::TrainSystem(double& budget)
    : currentState_(std::make_unique<Star1>()),
      yearsNotUpgraded_(0),
      cityBudget_(budget)
{
    std::cout << "Initializing Train System to Star1 state.\n";
}

/** 
 * @brief Default destructor.
 */
TrainSystem::~TrainSystem() = default;

/**
 * @brief Attempts to upgrade the train system to the next state.
 * 
 * If the city budget is sufficient, the upgrade cost is deducted, the state is upgraded,
 * and observers are notified. Otherwise, a message indicating insufficient funds is printed.
 */
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

/**
 * @brief Advances the system by one year, handling state-specific changes.
 * 
 * Calls the current state's handleYear method to manage any changes associated with the new year,
 * updates internal counters, and notifies observers of the new state.
 */
void TrainSystem::progressYear() {
    std::cout << "Progressing to the next year...\n";
    currentState_->handleYear(this);
    std::cout << "Current Train System State: " << getCurrentStateName() << "\n";
    std::cout << "City Budget: $" << cityBudget_ << "\n";
    std::cout << "Years Not Upgraded: " << yearsNotUpgraded_ << "\n\n";
    notify();
}

/**
 * @brief Gets the name of the current state.
 * @return A string representing the current state's name.
 */
std::string TrainSystem::getCurrentStateName() const {
    return currentState_->getStateName();
}

/**
 * @brief Gets the productivity level provided by the current state.
 * @return A double representing the productivity metric.
 */
double TrainSystem::getProductivity() const {
    return currentState_->getProductivity();
}

/**
 * @brief Gets the satisfaction level associated with the current state.
 * @return A double representing the satisfaction metric.
 */
double TrainSystem::getSatisfaction() const {
    return currentState_->getSatisfaction();
}

/**
 * @brief Retrieves the current city budget.
 * @return The city budget as a double.
 */
double TrainSystem::getCityBudget() const {
    return cityBudget_;
}

/**
 * @brief Adjusts the city budget by a specified amount.
 * @param amount The amount to adjust the city budget by (can be positive or negative).
 */
void TrainSystem::adjustCityBudget(double amount) {
    cityBudget_ += amount;
    if (cityBudget_ < 0.0) {
        cityBudget_ = 0.0;
    }
}

/**
 * @brief Sets the train system's current state to a new state.
 * @param newState A unique pointer to the new TrainState object.
 */
void TrainSystem::setState(std::unique_ptr<TrainState> newState) {
    currentState_ = std::move(newState);
}

/**
 * @brief Resets the counter tracking years without upgrades.
 */
void TrainSystem::resetYearsNotUpgraded() {
    yearsNotUpgraded_ = 0;
}

/**
 * @brief Increments the counter tracking years without upgrades.
 */
void TrainSystem::incrementYearsNotUpgraded() {
    yearsNotUpgraded_++;
}

/**
 * @brief Gets the number of years since the last upgrade.
 * @return The number of years not upgraded as an integer.
 */
int TrainSystem::getYearsNotUpgraded() const {
    return yearsNotUpgraded_;
}
