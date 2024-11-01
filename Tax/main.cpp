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

std::string formatMoney(double amount) {
    std::ostringstream oss;
    if (amount < 1000) {
        oss << "$" << static_cast<long long>(amount);
    }
    else if (amount < 1000000) {
        double thousands = amount / 1000.0;
        oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
    }
    else {
        double millions = amount / 1000000.0;
        oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
    }
    return oss.str();
}

int main() {
    CitySimulation citySim;

    int highClass = 100;   
    int middleClass = 500;  
    int lowClass = 1000;

    bool running = true;
    while (running) {
        std::cout << "============================\n";
        std::cout << "Year " << citySim.getCurrentYear() << "\n";
        std::cout << "Government's Total Money: " << formatMoney(citySim.getGovernmentMoney()) << "\n";
        std::cout << "Tax Satisfaction: " << citySim.getTaxSatisfaction() << "\n";
        std::cout << "============================\n";

        std::cout << "Choose a Tax Strategy:\n";
        std::cout << "1. Flat Tax\n";
        std::cout << "2. Progressive Tax\n";
        std::cout << "3. Regressive Tax\n";
        std::cout << "4. Exit\n";
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
                    continue; 
                }
                strategy = std::make_unique<FlatTax>(baseRate);
                std::cout << "Selected Flat Tax Strategy with rate " << baseRate << "%.\n";
                break;
            case 2:
                std::cout << "Enter Progressive Tax base rate (in %): ";
                std::cin >> baseRate;
                if (baseRate < 0.0 || baseRate > 100.0) {
                    std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                    continue; 
                }
                strategy = std::make_unique<ProgressiveTax>(baseRate);
                std::cout << "Selected Progressive Tax Strategy with base rate " << baseRate << "%.\n";
                break;
            case 3:
                std::cout << "Enter Regressive Tax base rate (in %): ";
                std::cin >> baseRate;
                if (baseRate < 0.0 || baseRate > 100.0) {
                    std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                    continue; 
                }
                strategy = std::make_unique<RegressiveTax>(baseRate);
                std::cout << "Selected Regressive Tax Strategy with base rate " << baseRate << "%.\n";
                break;
            case 4:
                std::cout << "Exiting simulation.\n";
                running = false;
                continue;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                continue; 
        }

        if (running) {
            citySim.setTaxStrategy(std::move(strategy));

            double taxCollected = citySim.advanceYear(highClass, middleClass, lowClass);

            std::cout << "Tax collected this year: " << formatMoney(taxCollected) << "\n\n";
        }
    }

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

    return 0;
}
