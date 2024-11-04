#ifndef TAXCONTEXT_H
#define TAXCONTEXT_H

#include "TaxStrategy.h"
#include <memory>
#include <string>

class TaxContext {
public:
    TaxContext(std::unique_ptr<TaxStrategy> strategy);

    ~TaxContext();

    TaxContext(const TaxContext&) = delete;
    TaxContext& operator=(const TaxContext&) = delete;

    TaxContext(TaxContext&&) = default;
    TaxContext& operator=(TaxContext&&) = default;

    void setStrategy(std::unique_ptr<TaxStrategy> strategy);

    double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens) const;

    double getBaseRate() const;

    std::string getStrategyName() const;

private:
    std::unique_ptr<TaxStrategy> strategy_;
};

#endif
