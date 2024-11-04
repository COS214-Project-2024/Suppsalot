#ifndef TAXMANAGER_H
#define TAXMANAGER_H

#include "CitySimulation.h"
#include "ProgressiveTax.h"
#include "FlatTax.h"
#include "RegressiveTax.h"
#include "TaxMemento.h"
#include "TaxHistoryManager.h"
#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

class TaxManager {
public:
    TaxManager(double& cityBudgetRef, double& taxSatisfactionRef)
        : budget(cityBudgetRef), taxSatisfaction(taxSatisfactionRef), 
          citySim(cityBudgetRef), highClassCitizens(100), middleClassCitizens(500), lowClassCitizens(1000) 
    {}

    void manageTax() {
        bool running = true;
        while (running) {
            std::cout << "============================\n";
            std::cout << "Tax Management Menu\n";
            std::cout << "============================\n";
            std::cout << "Choose an action:\n";
            std::cout << "1. Choose a Tax Strategy\n";
            std::cout << "2. View Tax Statistics\n";
            std::cout << "3. View Tax History\n";
            std::cout << "4. Back to Main Menu\n";
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    chooseTaxStrategy();
                    break;
                case 2:
                    std::cout << "----------------------------\n";
                    std::cout << "Tax Statistics\n";
                    std::cout << "\n";
                    std::cout << "Tax Satisfaction: " << citySim.getTaxSatisfaction() << "\n";
                    std::cout << "Tax Rate: " << citySim.getBaseTaxRate() << "\n";
                    std::cout << "Tax Strategy: " << citySim.getCurrentStrategyName() << "\n\n";
                    break;
                case 3:
                    viewTaxHistory();
                    break;
                case 4:
                    std::cout << "Returning to Main Menu.\n";
                    running = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\n";
        }
    }

    void progressYear() {
        std::cout << "Progressing to the next year in Tax Sector...\n\n";

        double taxCollected = citySim.advanceYear(highClassCitizens, middleClassCitizens, lowClassCitizens);
        
        budget += taxCollected;

        taxSatisfaction = citySim.getTaxSatisfaction();

        std::cout << "Year progressed successfully.\n";
        std::cout << "Tax collected this year: " << formatMoney(taxCollected) << "\n";
        std::cout << "Government's Total Money: " << formatMoney(citySim.getGovernmentMoney()) << "\n\n";
    }

    double getTaxSatisfaction() const {
        return taxSatisfaction;
    }

private:
    double& budget;
    double& taxSatisfaction;
    CitySimulation citySim;
    int highClassCitizens;
    int middleClassCitizens;
    int lowClassCitizens;

    std::string formatMoney(double amount) const {
        std::ostringstream oss;
        if (amount < 1000.0) {
            oss << "$" << static_cast<long long>(amount);
        }
        else if (amount < 1000000.0) {
            double thousands = amount / 1000.0;
            oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
        }
        else {
            double millions = amount / 1000000.0;
            oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
        }
        return oss.str();
    }

    void chooseTaxStrategy() {
        std::cout << "============================\n";
        std::cout << "Choose a Tax Strategy:\n";
        std::cout << "1. Flat Tax\n";
        std::cout << "2. Progressive Tax\n";
        std::cout << "3. Regressive Tax\n";
        std::cout << "4. Cancel\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        std::unique_ptr<TaxStrategy> strategy = nullptr;
        double baseRate = 0.0;

        switch (choice) {
            case 1:
                std::cout << "Enter Flat Tax rate (in %): ";
                std::cin >> baseRate;
                if (baseRate < 0.0 || baseRate > 100.0) {
                    std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                    return;
                }
                strategy = std::make_unique<FlatTax>(baseRate);
                std::cout << "Selected Flat Tax Strategy with rate " << baseRate << "%.\n";
                break;
            case 2:
                std::cout << "Enter Progressive Tax base rate (in %): ";
                std::cin >> baseRate;
                if (baseRate < 0.0 || baseRate > 100.0) {
                    std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                    return;
                }
                strategy = std::make_unique<ProgressiveTax>(baseRate);
                std::cout << "Selected Progressive Tax Strategy with base rate " << baseRate << "%.\n";
                break;
            case 3:
                std::cout << "Enter Regressive Tax base rate (in %): ";
                std::cin >> baseRate;
                if (baseRate < 0.0 || baseRate > 100.0) {
                    std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                    return;
                }
                strategy = std::make_unique<RegressiveTax>(baseRate);
                std::cout << "Selected Regressive Tax Strategy with base rate " << baseRate << "%.\n";
                break;
            case 4:
                std::cout << "Cancelled choosing Tax Strategy.\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                return;
        }

        citySim.setTaxStrategy(std::move(strategy));
    }

    void enterTaxRate() {
        std::string currentStrategy = citySim.getCurrentStrategyName();
        std::unique_ptr<TaxStrategy> newStrategy = nullptr;

        std::cout << "Enter the new tax rate (in %): ";
        double newRate;
        std::cin >> newRate;
        if (newRate < 0.0 || newRate > 100.0) {
            std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
            return;
        }

        if (currentStrategy == "FlatTax") {
            newStrategy = std::make_unique<FlatTax>(newRate);
        }
        else if (currentStrategy == "ProgressiveTax") {
            newStrategy = std::make_unique<ProgressiveTax>(newRate);
        }
        else if (currentStrategy == "RegressiveTax") {
            newStrategy = std::make_unique<RegressiveTax>(newRate);
        }
        else {
            std::cout << "No existing Tax Strategy to update.\n";
            return;
        }

        citySim.setTaxStrategy(std::move(newStrategy));
        std::cout << "Tax rate updated to " << newRate << "% for " << currentStrategy << " Strategy.\n";
    }

    void viewTaxHistory() const {
        const std::vector<TaxMemento>& history = citySim.getTaxHistory();
        if (!history.empty()) {
            std::cout << "=== Tax History ===\n";
            for (const auto& memento : history) {
                std::cout << "Year " << memento.getYear() << "\n";
                std::cout << "   Tax strategy: " << memento.getStrategyName() << "\n";
                std::cout << "   Tax rate: " << memento.getBaseRate() << "%\n";
                std::cout << "   Citizen satisfaction: " << memento.getTaxSatisfaction() << "\n";
            }
            std::cout << "====================\n";
        }
        else {
            std::cout << "No tax history available.\n";
        }
    }
};

#endif 
