#include "ProgressiveTax.h"

ProgressiveTax::ProgressiveTax(double baseRate)
    : baseRate_(baseRate) {}

ProgressiveTax::~ProgressiveTax() {}

double ProgressiveTax::calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const {
    double tax = 0.0;

    double highTaxRate = baseRate_ + 10.0;
    double middleTaxRate = baseRate_;
    double lowTaxRate = baseRate_ - 10.0;

    if (highTaxRate > 100.0) highTaxRate = 100.0;
    if (lowTaxRate < 0.0) lowTaxRate = 0.0;

    tax += highClassCitizens * 100000 * (highTaxRate / 100.0);
    tax += middleClassCitizens * 50000 * (middleTaxRate / 100.0);
    tax += lowClassCitizens * 25000 * (lowTaxRate / 100.0);

    return tax;
}

double ProgressiveTax::getBaseRate() const {
    return baseRate_;
}

std::string ProgressiveTax::getStrategyName() const {
    return "Progressive Tax";
}
