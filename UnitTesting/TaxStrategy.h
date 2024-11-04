#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

#include <string>

class TaxStrategy {
public:
    virtual ~TaxStrategy() {}
    
    virtual double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const = 0;

    virtual double getBaseRate() const = 0;

    virtual std::string getStrategyName() const = 0;
};

#endif 
