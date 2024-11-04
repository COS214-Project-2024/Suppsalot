#include "RegressiveTax.h"

RegressiveTax::RegressiveTax(double baseRate)
    : baseRate_(baseRate) {}

RegressiveTax::~RegressiveTax() {}

double RegressiveTax::calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const {
    double tax = 0.0;

    double highTaxRate = baseRate_ - 5.0;
    double middleTaxRate = baseRate_; 
    double lowTaxRate = baseRate_ + 5.0; 

    if (highTaxRate < 0.0) highTaxRate = 0.0;
    if (lowTaxRate > 100.0) lowTaxRate = 100.0;

    tax += highClassCitizens * 100000 * (highTaxRate / 100.0);
    tax += middleClassCitizens * 50000 * (middleTaxRate / 100.0);
    tax += lowClassCitizens * 25000 * (lowTaxRate / 100.0);

    return tax;
}

double RegressiveTax::getBaseRate() const {
    return baseRate_;
}

std::string RegressiveTax::getStrategyName() const {
    return "Regressive Tax";
}
