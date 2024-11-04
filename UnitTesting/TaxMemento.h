#ifndef TAXMEMENTO_H
#define TAXMEMENTO_H

#include <string>

class TaxMemento {
public:
    TaxMemento(int year, const std::string& strategyName, double baseRate, double taxSatisfaction)
        : year_(year), strategyName_(strategyName), baseRate_(baseRate), taxSatisfaction_(taxSatisfaction) {}

    int getYear() const { return year_; }
    std::string getStrategyName() const { return strategyName_; }
    double getBaseRate() const { return baseRate_; }
    double getTaxSatisfaction() const { return taxSatisfaction_; }

private:
    int year_;
    std::string strategyName_;
    double baseRate_;
    double taxSatisfaction_;
};

#endif 
