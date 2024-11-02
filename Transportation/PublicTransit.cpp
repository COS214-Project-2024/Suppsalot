#include "PublicTransit.h"
#include "NoUberAndBolt.h"
#include "Uber.h"
#include "Bolt.h"
#include "UberAndBolt.h"
#include <iostream>

PublicTransit::PublicTransit(double& budget)
    : currentState_(std::make_unique<NoUberAndBolt>()),
      cityBudget_(budget)
{
    std::cout << "Initializing Public Transit to NoUberAndBolt state.\n";
}

PublicTransit::~PublicTransit() = default;

void PublicTransit::buyUber() {
    std::cout << "Attempting to buy Uber...\n";
    double cost = 250000.0;

    if (cityBudget_ < cost) {
        std::cout << "Insufficient funds to buy Uber. Current Budget: $" << formatMoney(cityBudget_) << "\n";
        return;
    }

    bool success = currentState_->buyUber(this);
    if (success) {
        cityBudget_ -= cost;
        std::cout << "Uber purchased for $" << formatMoney(cost) << ". Remaining Budget: $" << formatMoney(cityBudget_) << "\n";
        notify(); 
    }
    else {
        std::cout << "Uber is already owned. No funds deducted.\n";
    }
}

void PublicTransit::buyBolt() {
    std::cout << "Attempting to buy Bolt...\n";
    double cost = 150000.0;

    if (cityBudget_ < cost) {
        std::cout << "Insufficient funds to buy Bolt. Current Budget: $" << formatMoney(cityBudget_) << "\n";
        return;
    }

    bool success = currentState_->buyBolt(this);
    if (success) {
        cityBudget_ -= cost;
        std::cout << "Bolt purchased for $" << formatMoney(cost) << ". Remaining Budget: $" << formatMoney(cityBudget_) << "\n";
        notify(); 
    }
    else {
        std::cout << "Bolt is already owned. No funds deducted.\n";
    }
}

void PublicTransit::progressYear() {
    // std::cout << "Progressing to the next year for Public Transit...\n";
    std::cout << "Current Public Transit State: " << getCurrentStateName() << "\n";
    std::cout << "City Budget: $" << formatMoney(cityBudget_) << "\n\n";
    notify(); 
}

std::string PublicTransit::getCurrentStateName() const {
    return currentState_->getStateName();
}

double PublicTransit::getProductivity() const {
    return currentState_->getProductivity();
}

double PublicTransit::getSatisfaction() const {
    return currentState_->getSatisfaction();
}

double PublicTransit::getCityBudget() const {
    return cityBudget_;
}

void PublicTransit::adjustCityBudget(double amount) {
    cityBudget_ += amount;
    if (cityBudget_ < 0.0) {
        cityBudget_ = 0.0;
    }
}

void PublicTransit::setState(std::unique_ptr<PublicTransitState> newState) {
    currentState_ = std::move(newState);
}

// Helper function to format money (ensure it's declared in PublicTransit.h or make it accessible)
std::string PublicTransit::formatMoney(double amount) const {
    std::ostringstream oss;
    if (amount < 1000.0) {
        oss << "$" << static_cast<long long>(amount);
    }
    else if (amount < 1000000.0) {
        double thousands = amount / 1000.0;
        oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
    }
    else {
        double millions = amount / 1000000.0;
        oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
    }
    return oss.str();
}
