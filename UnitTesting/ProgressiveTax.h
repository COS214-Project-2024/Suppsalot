#ifndef PROGRESSIVETAX_H
#define PROGRESSIVETAX_H

#include "TaxStrategy.h"
#include <string>

class ProgressiveTax : public TaxStrategy {
public:
    ProgressiveTax(double baseRate);
    virtual ~ProgressiveTax();
    
    virtual double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const override;

    virtual double getBaseRate() const override;

    virtual std::string getStrategyName() const override;

private:
    double baseRate_;
};

#endif 
