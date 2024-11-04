#include "FlatTax.h"
#include <string>

FlatTax::FlatTax(double baseRate)
    : baseRate_(baseRate) {}

FlatTax::~FlatTax() {}

double FlatTax::calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const {
    double tax = 0.0;

    tax += highClassCitizens * 100000 * (baseRate_ / 100.0);
    tax += middleClassCitizens * 50000 * (baseRate_ / 100.0);
    tax += lowClassCitizens * 25000 * (baseRate_ / 100.0);

    return tax;
}

double FlatTax::getBaseRate() const {
    return baseRate_;
}

std::string FlatTax::getStrategyName() const {
    return "Flat Tax";
}
