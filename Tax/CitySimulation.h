#ifndef CITYSIMULATION_H
#define CITYSIMULATION_H

#include "TaxContext.h"
#include "TaxHistoryManager.h"
#include <memory>
#include <vector>

class CitySimulation {
public:
    CitySimulation();
    ~CitySimulation();

    CitySimulation(const CitySimulation&) = delete;
    CitySimulation& operator=(const CitySimulation&) = delete;

    CitySimulation(CitySimulation&&) = default;
    CitySimulation& operator=(CitySimulation&&) = default;

    double calculateTax(int highClassCitizens, int middleClassCitizens, int lowClassCitizens);

    void setTaxStrategy(std::unique_ptr<TaxStrategy> strategy);

    double advanceYear(int highClassCitizens, int middleClassCitizens, int lowClassCitizens);

    int getCurrentYear() const;
    double getGovernmentMoney() const;
    double getTaxSatisfaction() const;

    const std::vector<TaxMemento>& getTaxHistory() const;

private:
    TaxContext taxContext_;
    int currentYear_;
    double governmentMoney_;
    double taxSatisfaction_;

    TaxHistoryManager taxHistoryManager_;
};

#endif
