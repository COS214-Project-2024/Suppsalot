#ifndef FLATTAX_H
#define FLATTAX_H

#include "TaxStrategy.h"
#include <string>

class FlatTax : public TaxStrategy {
public:
    FlatTax(double baseRate);
    virtual ~FlatTax();

    virtual double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const override;

    virtual double getBaseRate() const override;

    virtual std::string getStrategyName() const override;

private:
    double baseRate_;
};

#endif 
