#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "CitySimulation.h"
#include "ProgressiveTax.h"
#include "FlatTax.h"
#include "RegressiveTax.h"
#include "TaxMemento.h"
#include "TaxHistoryManager.h"
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

class TaxManager {
public:
    TaxManager(double& cityBudgetRef, double& taxSatisfactionRef);

    void manageTax();
    void progressYear();
    double getTaxSatisfaction() const;

private:
    double& budget;
    double& taxSatisfaction;
    CitySimulation citySim;

    std::string formatMoney(double amount) const;
    void chooseTaxStrategy();
    void enterTaxRate();
    void viewTaxHistory() const;
};

#include "TaxManager.cpp"
#endif // TAXMANAGER_H
