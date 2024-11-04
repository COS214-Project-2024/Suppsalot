#include "CitySimulation.h"
#include "FlatTax.h" 
#include <iostream>

CitySimulation::CitySimulation(double& cityBudgetRef)
    : taxContext_(std::make_unique<FlatTax>(10.0)), // Default strategy with baseRate = 10%
      currentYear_(1),
      governmentMoney_(cityBudgetRef), // Initialize reference to cityBudget
      taxSatisfaction_(100.0 - 10.0), // Starting satisfaction based on default strategy
      taxHistoryManager_()
{
}

CitySimulation::~CitySimulation() = default;

double CitySimulation::calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) {
    return taxContext_.calculateTax(highClassCitizens, middleClassCitizens, lowClassCitizens);
}

void CitySimulation::setTaxStrategy(std::unique_ptr<TaxStrategy> strategy) {
    taxContext_.setStrategy(std::move(strategy));
}

double CitySimulation::advanceYear(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) {
    double taxCollected = calculateTax(highClassCitizens, middleClassCitizens, lowClassCitizens);
    governmentMoney_ += taxCollected; 
    currentYear_++;

    double baseRate = taxContext_.getBaseRate();
    taxSatisfaction_ = 100.0 - baseRate;

    std::string strategyName = taxContext_.getStrategyName();
    TaxMemento memento(currentYear_ - 1, strategyName, baseRate, taxSatisfaction_);
    taxHistoryManager_.addMemento(memento);

    return taxCollected;
}

int CitySimulation::getCurrentYear() const {
    return currentYear_;
}

double CitySimulation::getGovernmentMoney() const {
    return governmentMoney_;
}

double CitySimulation::getTaxSatisfaction() const {
    return taxSatisfaction_;
}

const std::vector<TaxMemento>& CitySimulation::getTaxHistory() const {
    return taxHistoryManager_.getHistory();
}

std::string CitySimulation::getCurrentStrategyName() const {
    return taxContext_.getStrategyName();
}

double CitySimulation::getBaseTaxRate() const {
    return taxContext_.getBaseRate();
}
