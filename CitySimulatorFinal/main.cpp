/**
 * @file main.cpp
 * @brief City simulation program that manages city resources, transportation, taxes, buildings, and citizen satisfaction.
 */

#include "TransportationManager.h"
#include "TaxManager.h"
#include "BuildingsManager.h"
#include "CitizensManager.h"

#include "CityStats.h"
#include "StatsMemento.h"
#include "CityGrowthOg.h"
#include "StatsCaretaker.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <vector>


/**
 * @brief Formats a monetary value for display.
 * 
 * This function converts a given amount into a readable string format,
 * with "k" for thousands and "m" for millions.
 * 
 * @param amount The amount of money to format.
 * @return A formatted string representing the monetary value.
 */

std::string formatMoney(double amount)
{
    std::ostringstream oss;
    if (amount < 1000.0)
    {
        oss << "$" << static_cast<long long>(amount);
    }
    else if (amount < 1000000.0)
    {
        double thousands = amount / 1000.0;
        oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
    }
    else
    {
        double millions = amount / 1000000.0;
        oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
    }
    return oss.str();
}

/**
 * @brief Structure to store city growth statistics.
 */

struct GrowthStats
{
    int population; /**< Population of the city */
    double employmentRate;  /**< Employment rate percentage */
    double governmentBudget;  /**< Current government budget */
    double totalSatisfaction;  /**< Overall citizen satisfaction percentage */
};
/**
 * @brief Main function to run the city simulation program.
 * 
 * This function provides a menu interface for managing transportation, tax,
 * buildings, and citizen satisfaction within the simulation. It tracks
 * growth statistics over multiple years.
 * 
 * @return int Program exit status.
 */
int main()
{
    double cityBudget = 2000000.00;  /**< Initial city budget */
    double taxSatisfaction = 0.0;     /**< Tax satisfaction percentage */
    double transportSatisfaction = 0.0; /**< Transport satisfaction percentage */
    double citizenSatisfaction = 0.0;  /**< Citizen satisfaction percentage */
    double productivity = 0.0;   /**< Productivity percentage */
    double overallSatisfaction = 0.0; /**< Overall satisfaction percentage */

    TransportationManager transportationManager(cityBudget, transportSatisfaction, productivity);
    TaxManager taxManager(cityBudget, taxSatisfaction);
    BuildingsManager buildingsManager(cityBudget); 
    CitizensManager citizensManager;
    std::vector<GrowthStats> growthHistory;

    bool running = true;
    int year = 1;
    while (running)
    {
        std::cout << "============================\n";
        std::cout << "City Simulation Main Menu\n";
        std::cout << "============================\n";
        std::cout << "Choose an action:\n";
        std::cout << "1. Manage Transport\n";
        std::cout << "2. Manage Tax\n";
        std::cout << "3. Manage Buildings\n"; 
        std::cout << "4. Manage Citizens\n";
        std::cout << "5. Manage Government\n";
        std::cout << "6. View Resources\n";
        std::cout << "7. View Statistics\n";
        std::cout << "8. Progress Year\n";
        std::cout << "9. View Growth History\n";
        std::cout << "10. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();                                                   
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
            continue; 
        }

        switch (choice)
        {
        case 1:
            transportationManager.manageTransport();
            break;
        case 2:
            taxManager.manageTax();
            break;
        case 3:
            buildingsManager.manageBuildings();
            break;
        case 4:
            citizensManager.manageCitizens();
            break;
        case 5:
            std::cout << "Government Management is under construction.\n";
            break;
        case 6:
            std::cout << "------------------------\n";
            std::cout << "Resources for the city:\n";
            std::cout << "Materials:\n";
            std::cout << "   Remaining Wood: " << buildingsManager.getRemainingWood() << "\n";
            std::cout << "   Remaining Steel: " << buildingsManager.getRemainingSteel() << "\n";
            std::cout << "   Remaining Concrete: " << buildingsManager.getRemainingConcrete() << "\n";
            std::cout << "Utilities:\n";
            std::cout << "   Remaining Power: " << buildingsManager.getRemainingPower() << "\n";
            std::cout << "   Remaining Water: " << buildingsManager.getRemainingWater() << "\n";
            std::cout << "------------------------\n\n";
            break;
        case 7:
            std::cout << "============================\n";
            std::cout << "City Statistics:\n";
            std::cout << "============================\n";
            std::cout << "Satisfaction: " << std::fixed << std::setprecision(1)
                      << (0.3 * taxSatisfaction + 0.3 * transportSatisfaction + 0.4 * citizenSatisfaction) << "%\n";
            std::cout << "\tTax Satisfaction: " << std::fixed << std::setprecision(1)
                      << taxSatisfaction << "%\n";
            std::cout << "\tTransport Satisfaction: " << std::fixed << std::setprecision(1)
                      << transportSatisfaction << "%\n";
            std::cout << "\tCitizen Satisfaction: " << std::fixed << std::setprecision(1)
                      << citizenSatisfaction << "%\n";
            std::cout << "Productivity: " << std::fixed << std::setprecision(1)
                      << productivity << "%\n";
            std::cout << "City Budget: " << formatMoney(cityBudget) << "\n";
            std::cout << "============================\n\n";
            break;
        case 8:{
            std::cout << "Progressing to the next year...\n\n";

            transportationManager.progressYear();
            taxManager.progressYear();
            buildingsManager.progressYear();
            citizensManager.progressYear();

            citizenSatisfaction = citizensManager.getAverageSatisfaction();

            overallSatisfaction = 0.3 * taxSatisfaction + 0.3 * transportSatisfaction + 0.4 * citizenSatisfaction;

            int currentPopulation = citizensManager.getTotalPopulation();
            int totalEmployed = citizensManager.getTotalEmployed();
            double currentEmploymentRate = (currentPopulation > 0) ? 
                (static_cast<double>(totalEmployed) / currentPopulation) * 100.0 : 0.0;

            double currentGovernmentBudget = cityBudget;

            double currentTotalSatisfaction = overallSatisfaction;

            double populationGrowth = 0.0;
            double employmentRateChange = 0.0;
            double budgetGrowth = 0.0;
            double satisfactionGrowth = 0.0;

            if (!growthHistory.empty())
            {
                const GrowthStats &prevStats = growthHistory.back();
                if (prevStats.population > 0) {
                    populationGrowth = ((static_cast<double>(currentPopulation - prevStats.population) / prevStats.population) * 100.0);
                }

                if (prevStats.employmentRate > 0.0) {
                    employmentRateChange = currentEmploymentRate - prevStats.employmentRate;
                }

                if (prevStats.governmentBudget > 0.0) {
                    budgetGrowth = ((currentGovernmentBudget - prevStats.governmentBudget) / prevStats.governmentBudget) * 100.0;
                }

                if (prevStats.totalSatisfaction > 0.0) {
                    satisfactionGrowth = ((currentTotalSatisfaction - prevStats.totalSatisfaction) / prevStats.totalSatisfaction) * 100.0;
                }
            }

            GrowthStats currentStats = {currentPopulation, currentEmploymentRate, currentGovernmentBudget, currentTotalSatisfaction};
            growthHistory.push_back(currentStats);

            std::cout << "Population: " << currentPopulation;
            if (year > 1) {
                std::cout << " (" << std::fixed << std::setprecision(2) << populationGrowth << "%)\n";
            } else {
                std::cout << "\n";
            }

            std::cout << "Employment Rate: " << std::fixed << std::setprecision(1) << currentEmploymentRate << "%";
            if (year > 1) {
                std::cout << " (" << std::fixed << std::setprecision(2) << employmentRateChange << "%)\n";
            } else {
                std::cout << "\n";
            }

            std::cout << "Government Budget: " << formatMoney(currentGovernmentBudget);
            if (year > 1) {
                std::cout << " (" << std::fixed << std::setprecision(2) << budgetGrowth << "%)\n";
            } else {
                std::cout << "\n";
            }

            std::cout << "Total Satisfaction: " << std::fixed << std::setprecision(1) << currentTotalSatisfaction << "%";
            if (year > 1) {
                std::cout << " (" << std::fixed << std::setprecision(2) << satisfactionGrowth << "%)\n";
            } else {
                std::cout << "\n";
            }

            std::cout << "\n";

            year++;

            break;
        }
        case 9:{
            if (growthHistory.empty())
            {
                std::cout << "No growth data available.\n\n";
            }
            else
            {
                std::cout << "=== Growth History ===\n";
                for (size_t i = 0; i < growthHistory.size(); ++i)
                {
                    const GrowthStats &stats = growthHistory[i];
                    std::cout << "Year " << i + 1 << ":\n";

                    std::cout << "\tPopulation: " << stats.population;
                    if (i > 0)
                    {
                        double popChange = ((static_cast<double>(stats.population) - growthHistory[i - 1].population) / growthHistory[i - 1].population) * 100.0;
                        std::cout << " (" << std::fixed << std::setprecision(2) << popChange << "%)\n";
                    }
                    else
                    {
                        std::cout << "\n";
                    }

                    std::cout << "\tEmployment Rate: " << std::fixed << std::setprecision(1)
                              << stats.employmentRate << "%";
                    if (i > 0)
                    {
                        double empChange = stats.employmentRate - growthHistory[i - 1].employmentRate;
                        std::cout << " (" << std::fixed << std::setprecision(2) << empChange << "%)\n";
                    }
                    else
                    {
                        std::cout << "\n";
                    }

                    std::cout << "\tGovernment Budget: " << formatMoney(stats.governmentBudget);
                    if (i > 0)
                    {
                        double budgetChange = ((stats.governmentBudget - growthHistory[i - 1].governmentBudget) / growthHistory[i - 1].governmentBudget) * 100.0;
                        std::cout << " (" << std::fixed << std::setprecision(2) << budgetChange << "%)\n";
                    }
                    else
                    {
                        std::cout << "\n";
                    }

                    std::cout << "\tTotal Satisfaction: " << std::fixed << std::setprecision(1)
                              << stats.totalSatisfaction << "%";
                    if (i > 0)
                    {
                        double satisfactionChange = ((stats.totalSatisfaction - growthHistory[i - 1].totalSatisfaction) / growthHistory[i - 1].totalSatisfaction) * 100.0;
                        std::cout << " (" << std::fixed << std::setprecision(2) << satisfactionChange << "%)\n";
                    }
                    else
                    {
                        std::cout << "\n";
                    }

                    std::cout << "\n";
                }
                std::cout << "=========================\n\n";
            }
            break;
        }
        case 10:
            std::cout << "Exiting simulation.\n";
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
    return 0;
}
