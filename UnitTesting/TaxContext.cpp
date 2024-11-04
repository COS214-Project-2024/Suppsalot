#include "TaxContext.h"

TaxContext::TaxContext(std::unique_ptr<TaxStrategy> strategy)
    : strategy_(std::move(strategy)) {}

TaxContext::~TaxContext() = default;

void TaxContext::setStrategy(std::unique_ptr<TaxStrategy> strategy) {
    strategy_ = std::move(strategy);
}

double TaxContext::calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const {
    if (strategy_) {
        return strategy_->calculateTax(highClassCitizens, middleClassCitizens, lowClassCitizens);
    } else {
        return 0.0;
    }
}

double TaxContext::getBaseRate() const {
    if (strategy_) {
        return strategy_->getBaseRate();
    } else {
        return 0.0;
    }
}

std::string TaxContext::getStrategyName() const {
    if (strategy_) {
        return strategy_->getStrategyName();
    } else {
        return "No Tax Strategy";
    }
}
