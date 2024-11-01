#ifndef REGRESSIVETAX_H
#define REGRESSIVETAX_H

#include "TaxStrategy.h"
#include <string>

class RegressiveTax : public TaxStrategy {
public:
    RegressiveTax(double baseRate);
    virtual ~RegressiveTax();
    
    virtual double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const override;

    virtual double getBaseRate() const override;

    virtual std::string getStrategyName() const override;

private:
    double baseRate_;
};

#endif
