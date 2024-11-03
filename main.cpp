/**
 * @file main.cpp
 * @brief Main file for the city simulation program.
 *
 * This file contains the main menu, helper functions, and control loops for managing
 * different components in the city, such as buildings and transportation systems.
 */

#include "BuildingFactory.h"
#include "ResourceManager.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include "BuildingStatistics.h"
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include "CityStats.h"
#include "StatsMemento.h"
#include "CityGrowthOg.h"
#include "StatsCaretaker.h"
#include "CitySimulation.h"
#include "ProgressiveTax.h"
#include "FlatTax.h"
#include "RegressiveTax.h"
#include "TaxMemento.h"
#include "TaxHistoryManager.h"
#include "Road.h"
#include "NotOperational.h"
#include "Bad.h"
#include "Okay.h"
#include "Good.h"
#include "Excellent.h"
#include "TrainSystem.h"
#include "Star1.h"
#include "Star2.h"
#include "Star3.h"
#include "Star4.h"
#include "Star5.h"
#include "TransportObserver.h"

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

/**
 * @brief Formats a double into a human-readable money format.
 * 
 * @param amount The monetary amount to be formatted.
 * @return A formatted string representing the amount in a user-friendly form (e.g., "$1.5k").
 */
std::string formatMoney(double amount) {
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

/**
 * @brief Manages the menu and operations for the TrainSystem.
 * 
 * @param train Reference to a TrainSystem object.
 */
void trainM(TrainSystem& train) {
    bool runningT = true;
    while (runningT) {
        std::cout << "============================\n";
        std::cout << "Current Train System State: " << train.getCurrentStateName() << "\n";
        std::cout << "City Budget: " << formatMoney(train.getCityBudget()) << "\n";
        std::cout << "Train Satisfaction: " << train.getSatisfaction() << "\n";
        std::cout << "============================\n";
        std::cout << "Choose an action:\n";
        std::cout << "1. Upgrade Train System\n";
        std::cout << "2. Progress to Next Year\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        int choiceT;
        std::cin >> choiceT;
        switch (choiceT) {
            case 1:
                train.upgradeTrainSystem();
                break;
            case 2:
                train.progressYear();
                break;
            case 3:
                std::cout << "Exiting Train.\n";
                runningT = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << "\n";
    }
}

/**
 * @brief Manages the menu and operations for the Road system.
 * 
 * @param road Reference to a Road object.
 */
void roadM(Road& road) {
    bool runningR = true;
    while (runningR) {
        std::cout << "============================\n";
        std::cout << "Current Road State: " << road.getCurrentStateName() << "\n";
        std::cout << "City Budget: " << formatMoney(road.getCityBudget()) << "\n";
        std::cout << "Road Satisfaction: " << road.getSatisfaction() << "\n";
        std::cout << "============================\n";

        std::cout << "Choose an action:\n";
        std::cout << "1. Upgrade Road\n";
        std::cout << "2. Progress to Next Year\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        int choiceR;
        std::cin >> choiceR;

        switch (choiceR) {
            case 1:
                road.upgradeRoad();
                break;
            case 2:
                road.progressYear();
                break;
            case 3:
                std::cout << "Exiting Road.\n";
                runningR = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        std::cout << "\n";
    }
}

/**
 * @brief Displays the current statistics of the city.
 * 
 * @param s A CityStats object containing the city's statistics.
 */
void displayStatistics(const CityStats& s) {
    std::cout << "Population: " << s.population << "\n"
              << "Housing Needs: " << s.housingNeeds << "\n"
              << "Citizen Satisfaction: " << s.citizenSatisfaction << "\n"
              << "Hygiene: " << s.hygiene << "\n"
              << "Productivity: " << s.productivity << "\n"
              << "Employment Rate: " << s.employmentRate << "%\n";
}

/**
 * @brief Displays the percentage change between two sets of city statistics.
 * 
 * @param prev The previous CityStats object.
 * @param current The current CityStats object.
 */
void displayPercentageChange(const CityStats& prev, const CityStats& current) {
    auto percentChange = [&](int prevVal, int currVal) -> double {
        if (prevVal == 0) return 0.0;
        return ((double)(currVal - prevVal) / prevVal) * 100.0;
    };
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Population Change: " << percentChange(prev.population, current.population) << "%\n"
              << "Housing Needs Change: " << percentChange(prev.housingNeeds, current.housingNeeds) << "%\n"
              << "Citizen Satisfaction Change: " << percentChange(prev.citizenSatisfaction, current.citizenSatisfaction) << "%\n"
              << "Hygiene Change: " << percentChange(prev.hygiene, current.hygiene) << "%\n"
              << "Productivity Change: " << percentChange(prev.productivity, current.productivity) << "%\n"
              << "Employment Rate Change: " << percentChange(prev.employmentRate, current.employmentRate) << "%\n";
}

/**
 * @brief Shows the main menu options to the user.
 */
void showMainMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "       Building Management System        \n";
    std::cout << "=========================================\n";
    std::cout << "1. Build Industrial Building\n";
    std::cout << "2. Build Commercial Building\n";
    std::cout << "3. Build Residential Building\n";
    std::cout << "4. Build Landmark Building\n";
    std::cout << "5. Remove a Building\n";
    std::cout << "6. Progress Year (Increase Resources)\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Shows the options for specific building types.
 * 
 * @param buildingType A string representing the type of building.
 */
void showBuildingOptions(const std::string& buildingType) {
    if (buildingType == "Industrial") {
        std::cout << "Choose an Industrial Building:\n";
        std::cout << "1. Factory\n";
        std::cout << "2. Warehouse\n";
        std::cout << "3. PowerPlant\n";
        std::cout << "4. Dam\n";
    } else if (buildingType == "Commercial") {
        std::cout << "Choose a Commercial Building:\n";
        std::cout << "1. Shop\n";
        std::cout << "2. Mall\n";
        std::cout << "3. Office\n";
    } else if (buildingType == "Residential") {
        std::cout << "Choose a Residential Building:\n";
        std::cout << "1. House\n";
        std::cout << "2. Flat\n";
        std::cout << "3. Townhouse\n";
        std::cout << "4. Estate\n";
    } else if (buildingType == "Landmark") {
        std::cout << "Choose a Landmark Building:\n";
        std::cout << "1. Park\n";
        std::cout << "2. Monument\n";
        std::cout << "3. Cultural\n";
    }
    std::cout << "Enter your choice: ";
}

// Storage for created buildings
std::vector<std::unique_ptr<ResidentialBuilding>> residentialBuildings;
std::vector<std::unique_ptr<IndustrialBuilding>> industrialBuildings;
std::vector<std::unique_ptr<LandmarkBuilding>> landmarkBuildings;
std::vector<std::unique_ptr<CommercialBuilding>> commercialBuildings;

// Main control loop flag
bool running = true;
int main() {
    // Initial setup (as specified)
    std::cout << "\n=========================================\n";
    std::cout << "       Main Menu       \n";
    std::cout << "=========================================\n";
    int choice = 0;
    std::cout << "1. Manage Buildings\n";
    std::cout << "2. Manage Citizens\n";
    std::cout << "3. Manage Transport\n";
    std::cout << "4. Manage Tax\n";
    std::cout << "5. Manage Government\n";
    std::cout << "6. Manage Utilities\n";
    std::cout << "7. View Resources\n";
    std::cout << "8. View Statistics\n";
    std::cout << "9. Progress Year\n";
    std::cout << "10. Exit\n";


    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Move ResourceManager initialization outside the switch statement
    ResourceManager* rm = new WoodManager();
    ResourceManager* rm1 = new SteelManager();
    ResourceManager* rm2 = new ConcreteManager();
    ResourceManager* rm3 = new PowerManager();
    ResourceManager* rm4 = new WaterManager();

    switch (choice) {
        case 1:
            std::cout << "********************************************\n";
            std::cout << "********************************************\n\n";

            // Factories for creating buildings
            ResidentialFactory residentialFactory;
            IndustrialFactory industrialFactory;
            LandmarkFactory landmarkFactory;
            CommercialFactory commercialFactory;

            while (running) {
                showMainMenu();
                int mainChoice;
                std::cin >> mainChoice;

                switch (mainChoice) {
                    case 1: { // Build Industrial Building
                        showBuildingOptions("Industrial");
                        int industrialChoice;
                        std::cin >> industrialChoice;
                        switch (industrialChoice) {
                            case 1: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("factory"))); break;
                            case 2: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("warehouse"))); break;
                            case 3: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("plant"))); break;
                            case 4: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("dam"))); break;
                            default: std::cout << "Invalid choice!\n"; break;
                        }
                        break;
                    }
                    case 2: { // Build Commercial Building
                        showBuildingOptions("Commercial");
                        int commercialChoice;
                        std::cin >> commercialChoice;
                        switch (commercialChoice) {
                            case 1: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("shop"))); break;
                            case 2: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("mall"))); break;
                            case 3: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("office"))); break;
                            default: std::cout << "Invalid choice!\n"; break;
                        }
                        break;
                    }
                    case 3: { // Build Residential Building
                        showBuildingOptions("Residential");
                        int residentialChoice;
                        std::cin >> residentialChoice;
                        switch (residentialChoice) {
                            case 1: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("house"))); break;
                            case 2: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("flat"))); break;
                            case 3: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("townhouse"))); break;
                            case 4: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("estate"))); break;
                            default: std::cout << "Invalid choice!\n"; break;
                        }
                        break;
                    }
                    case 4: { // Build Landmark Building
                        showBuildingOptions("Landmark");
                        int landmarkChoice;
                        std::cin >> landmarkChoice;
                        switch (landmarkChoice) {
                            case 1: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Park"))); break;
                            case 2: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Monument"))); break;
                            case 3: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Cultural"))); break;
                            default: std::cout << "Invalid choice!\n"; break;
                        }
                        break;
                    }
                    case 5: { // Remove Building
                        std::cout << "Choose a type of building to remove:\n";
                        std::cout << "1. Residential\n";
                        std::cout << "2. Industrial\n";
                        std::cout << "3. Landmark\n";
                        std::cout << "4. Commercial\n";
                        int buildingType;
                        std::cin >> buildingType;

                        if (buildingType == 1 && !residentialBuildings.empty()) {
                            residentialBuildings.back()->removeBuilding();
                            residentialBuildings.pop_back();
                        } else if (buildingType == 2 && !industrialBuildings.empty()) {
                            industrialBuildings.back()->removeBuilding();
                            industrialBuildings.pop_back();
                        } else if (buildingType == 3 && !landmarkBuildings.empty()) {
                            landmarkBuildings.back()->removeBuilding();
                            landmarkBuildings.pop_back();
                        } else if (buildingType == 4 && !commercialBuildings.empty()) {
                            commercialBuildings.back()->removeBuilding();
                            commercialBuildings.pop_back();
                        } else {
                            std::cout << "No building of the selected type to remove!\n";
                        }
                        break;
                    }
                    case 6: { // Progress Year
                        BuildingStatistics::YearResourceIncrease();
                        break;
                    }
                    case 7: { // Exit
                        running = false;
                        break;
                    }
                    default: {
                        std::cout << "Invalid choice! Please try again.\n";
                        break;
                    }
                }
            }

            // Cleanup resources
            delete rm;
            delete rm1;
            delete rm2;
            delete rm3;
            delete rm4;
            break;
            std::cout << "Exiting Buildings. All resources and buildings have been cleaned up.\n";
            break;
    case 2:
        std::srand(static_cast<unsigned int>(time(nullptr)));
        std::vector<PrototypeCitizen*> citizens;
        bool srunning = true;
        float totalSatisfaction = 0.0;

        while (srunning) {
            int choice;
            std::cout << "\nChoose an action:\n";
            std::cout << "1. Create High Class Citizens\n";
            std::cout << "2. Create Mid Class Citizens\n";
            std::cout << "3. Create Low Class Citizens\n";
            std::cout << "4. Toggle Employment Status\n";
            std::cout << "5. Display Citizen Info, Count, & Average Satisfaction\n";
            std::cout << "6. Kill Citizens\n";
            std::cout << "7. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    int num;
                    std::cout << "Enter the number of High Class Citizens to create: ";
                    std::cin >> num;
                    for (int i = 0; i < num; ++i) {
                        PrototypeCitizen* highCitizen = new HighClassCitizen();
                        citizens.push_back(highCitizen);
                        totalSatisfaction += highCitizen->getSatisfaction();
                    }
                    std::cout << num << " High Class Citizens created.\n";
                    break;
                }
                case 2: {
                    int num;
                    std::cout << "Enter the number of Mid Class Citizens to create: ";
                    std::cin >> num;
                    for (int i = 0; i < num; ++i) {
                        PrototypeCitizen* midCitizen = new MidClassCitizen();
                        citizens.push_back(midCitizen);
                        totalSatisfaction += midCitizen->getSatisfaction();
                    }
                    std::cout << num << " Mid Class Citizens created.\n";
                    break;
                }
                case 3: {
                    int num;
                    std::cout << "Enter the number of Low Class Citizens to create: ";
                    std::cin >> num;
                    for (int i = 0; i < num; ++i) {
                        PrototypeCitizen* lowCitizen = new LowClassCitizen();
                        citizens.push_back(lowCitizen);
                        totalSatisfaction += lowCitizen->getSatisfaction();
                    }
                    std::cout << num << " Low Class Citizens created.\n";
                    break;
                }
                case 4: {
                    int employmentChoice;
                    std::cout << "Choose Citizen Class to Toggle Employment Status:\n";
                    std::cout << "1. High Class\n";
                    std::cout << "2. Mid Class\n";
                    std::cout << "3. Low Class\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> employmentChoice;

                    for (PrototypeCitizen* citizen : citizens) {
                        if ((employmentChoice == 1 && dynamic_cast<HighClassCitizen*>(citizen)) ||
                            (employmentChoice == 2 && dynamic_cast<MidClassCitizen*>(citizen)) ||
                            (employmentChoice == 3 && dynamic_cast<LowClassCitizen*>(citizen))) {
                            citizen->toggleEmployment();
                            std::cout << "Employment status toggled for a citizen of chosen class.\n";
                        }
                    }
                    break;
                }
                case 5: {
                    float avgSatisfaction = citizens.empty() ? 0.0 : totalSatisfaction / citizens.size();
                    std::cout << "\n--- Citizen Information ---\n";
                    for (PrototypeCitizen* citizen : citizens) {
                        citizen->displayInfo();
                    }
                    std::cout << "\nTotal Citizens: " << PrototypeCitizen::getCitizenCount();
                    std::cout << "\nAverage Satisfaction: " << avgSatisfaction << "\n";
                    break;
                }
                case 6: {
                    int numToKill;
                    std::cout << "Enter the number of citizens to kill: ";
                    std::cin >> numToKill;

                    if (numToKill > static_cast<int>(citizens.size())) {
                        std::cout << "Not enough citizens to kill. Currently, there are only " << citizens.size() << " citizens.\n";
                        break;
                    }

                    for (int i = 0; i < numToKill; ++i) {
                        int index = std::rand() % citizens.size();
                        totalSatisfaction -= citizens[index]->getSatisfaction();
                        delete citizens[index];
                        citizens.erase(citizens.begin() + index);
                    }

                    std::cout << numToKill << " citizens have been killed.\n";
                    break;
                }
                case 7: {
                    srunning = false;
                    std::cout << "Exiting program.\n";
                    break;
                }
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
            }
            for (PrototypeCitizen* citizen : citizens) {
                delete citizen;
            }
                break;
    case 3:
        double budget = 2000000.00;
        Road road(budget);
        TrainSystem train(budget);
        TransportObserver observer(road, train);
        road.attach(&observer);
        train.attach(&observer);

        bool prunning = true;
        while(prunning){

            std::cout << "Choose an action:\n";
            std::cout << "1. Road\n";
            std::cout << "2. Train\n";
            std::cout << "3. View Statistics\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    roadM(road);
                break;
                case 2:
                    trainM(train);
                break;
                case 3:
                    observer.update();
                std::cout << "Total Transport Satisfaction: " << observer.getTransportSatisfaction() << "\n";
                std::cout << "Total Transport Productivity: " << observer.getTransportProductivity() * 100 << "%\n";
                std::cout << "Total City Budget: " << formatMoney(budget) << "\n";
                break;
                case 4:
                    std::cout << "Exiting simulation.\n";
                prunning = false;
                break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
            break;
    case 4:
        CitySimulation citySim;
        int highClass = 100;
        int middleClass = 500;
        int lowClass = 1000;

        bool trunning = true;
        while (trunning) {
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
                    strategy = std::unique_ptr<FlatTax>(new FlatTax(baseRate));
                    std::cout << "Selected Flat Tax Strategy with rate " << baseRate << "%.\n";
                    break;
                case 2:
                    std::cout << "Enter Progressive Tax base rate (in %): ";
                    std::cin >> baseRate;
                    if (baseRate < 0.0 || baseRate > 100.0) {
                        std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                        continue;
                    }
                strategy = std::unique_ptr<RegressiveTax>(new RegressiveTax(baseRate));
                    std::cout << "Selected Progressive Tax Strategy with base rate " << baseRate << "%.\n";
                    break;
                case 3:
                    std::cout << "Enter Regressive Tax base rate (in %): ";
                    std::cin >> baseRate;
                    if (baseRate < 0.0 || baseRate > 100.0) {
                        std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
                        continue;
                    }
                    strategy = std::unique_ptr<RegressiveTax>(new RegressiveTax(baseRate));
                    std::cout << "Selected Regressive Tax Strategy with base rate " << baseRate << "%.\n";
                    break;
                case 4:
                    std::cout << "Exiting simulation.\n";
                    trunning = false;
                    continue;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    continue;
            }

            if (trunning) {
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

               break;
    case 5:
        std::cout<<"Managing Government\n";
            break;
    case 6:
        std::cout<<"Managing Utilities\n";
            break;
    case 7:
        std::cout<<"Viewing Resources\n";
        std::cout << "Wood: " << rm->getQuantity() << " units\n";
        std::cout << "Steel: " << rm1->getQuantity() << " units\n";
        std::cout << "Concrete: " << rm2->getQuantity() << " units\n";
        std::cout << "Power: " << rm3->getQuantity() << " units\n";
        std::cout << "Water: " << rm4->getQuantity() << " units\n";
    break;

    case 8:
        std::cout<<"Viewing Statistics\n";
        CityStats currentStats = CityStats::getInstance();
        CityStats previousStats = StatsCaretaker::getInstance().getMemento().getStats();
        displayStatistics(currentStats);
        displayPercentageChange(previousStats, currentStats);
    break;
    case 9:
        std::cout<<"Progressing Year\n";
        break;
    default:
            std::cout<<"Invalid choice. Exiting program.\n";
            return 0;
    }

    return 0;


//     std::cout << "********************************************\n";
//     ResourceManager* rm = new WoodManager();
//     ResourceManager* rm1 = new SteelManager();
//     ResourceManager* rm2 = new ConcreteManager();
//     ResourceManager* rm3 = new PowerManager();
//     ResourceManager* rm4 = new WaterManager();
//     std::cout << "********************************************\n\n";
//
//     // Factories for creating buildings
//     ResidentialFactory residentialFactory;
//     IndustrialFactory industrialFactory;
//     LandmarkFactory landmarkFactory;
//     CommercialFactory commercialFactory;
//
//     // Storage for created buildings
//     std::vector<std::unique_ptr<ResidentialBuilding>> residentialBuildings;
//     std::vector<std::unique_ptr<IndustrialBuilding>> industrialBuildings;
//     std::vector<std::unique_ptr<LandmarkBuilding>> landmarkBuildings;
//     std::vector<std::unique_ptr<CommercialBuilding>> commercialBuildings;
//
//     bool running = true;
//     while (running) {
//         showMainMenu();
//         int mainChoice;
//         std::cin >> mainChoice;
//
//         switch (mainChoice) {
//             case 1: { // Build Industrial Building
//                 showBuildingOptions("Industrial");
//                 int industrialChoice;
//                 std::cin >> industrialChoice;
//                 switch (industrialChoice) {
//                     case 1: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("factory"))); break;
//                     case 2: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("warehouse"))); break;
//                     case 3: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("plant"))); break;
//                     case 4: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("dam"))); break;
//                     default: std::cout << "Invalid choice!\n"; break;
//                 }
//                 break;
//             }
//             case 2: { // Build Commercial Building
//                 showBuildingOptions("Commercial");
//                 int commercialChoice;
//                 std::cin >> commercialChoice;
//                 switch (commercialChoice) {
//                     case 1: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("shop"))); break;
//                     case 2: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("mall"))); break;
//                     case 3: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("office"))); break;
//                     default: std::cout << "Invalid choice!\n"; break;
//                 }
//                 break;
//             }
//             case 3: { // Build Residential Building
//                 showBuildingOptions("Residential");
//                 int residentialChoice;
//                 std::cin >> residentialChoice;
//                 switch (residentialChoice) {
//                     case 1: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("house"))); break;
//                     case 2: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("flat"))); break;
//                     case 3: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("townhouse"))); break;
//                     case 4: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("estate"))); break;
//                     default: std::cout << "Invalid choice!\n"; break;
//                 }
//                 break;
//             }
//             case 4: { // Build Landmark Building
//                 showBuildingOptions("Landmark");
//                 int landmarkChoice;
//                 std::cin >> landmarkChoice;
//                 switch (landmarkChoice) {
//                     case 1: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Park"))); break;
//                     case 2: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Monument"))); break;
//                     case 3: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Cultural"))); break;
//                     default: std::cout << "Invalid choice!\n"; break;
//                 }
//                 break;
//             }
//             case 5: { // Remove Building
//                 std::cout << "Choose a type of building to remove:\n";
//                 std::cout << "1. Residential\n";
//                 std::cout << "2. Industrial\n";
//                 std::cout << "3. Landmark\n";
//                 std::cout << "4. Commercial\n";
//                 int buildingType;
//                 std::cin >> buildingType;
//
//                 if (buildingType == 1 && !residentialBuildings.empty()) {
//                     residentialBuildings.back()->removeBuilding();
//                     residentialBuildings.pop_back();
//                 } else if (buildingType == 2 && !industrialBuildings.empty()) {
//                     industrialBuildings.back()->removeBuilding();
//                     industrialBuildings.pop_back();
//                 } else if (buildingType == 3 && !landmarkBuildings.empty()) {
//                     landmarkBuildings.back()->removeBuilding();
//                     landmarkBuildings.pop_back();
//                 } else if (buildingType == 4 && !commercialBuildings.empty()) {
//                     commercialBuildings.back()->removeBuilding();
//                     commercialBuildings.pop_back();
//                 } else {
//                     std::cout << "No building of the selected type to remove!\n";
//                 }
//                 break;
//             }
//             case 6: { // Progress Year
//                 BuildingStatistics::YearResourceIncrease();
//                 break;
//             }
//             case 7: { // Exit
//                 running = false;
//                 break;
//             }
//             default: {
//                 std::cout << "Invalid choice! Please try again.\n";
//                 break;
//             }
//         }
//     }
//
//     // Cleanup resources
//     delete rm;
//     delete rm1;
//     delete rm2;
//     delete rm3;
//     delete rm4;
//
//
//     std::cout << "Exiting program. All resources and buildings have been cleaned up.\n";
//
//
//     //////////////////////////////////////////////////////////////////////////////////////////////////
//     std::srand(static_cast<unsigned int>(time(nullptr)));
//     std::vector<PrototypeCitizen*> citizens;
//     bool srunning = true;
//     float totalSatisfaction = 0.0;
//
//     while (srunning) {
//         int choice;
//         std::cout << "\nChoose an action:\n";
//         std::cout << "1. Create High Class Citizens\n";
//         std::cout << "2. Create Mid Class Citizens\n";
//         std::cout << "3. Create Low Class Citizens\n";
//         std::cout << "4. Toggle Employment Status\n";
//         std::cout << "5. Display Citizen Info, Count, & Average Satisfaction\n";
//         std::cout << "6. Kill Citizens\n";
//         std::cout << "7. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;
//
//         switch (choice) {
//             case 1: {
//                 int num;
//                 std::cout << "Enter the number of High Class Citizens to create: ";
//                 std::cin >> num;
//                 for (int i = 0; i < num; ++i) {
//                     PrototypeCitizen* highCitizen = new HighClassCitizen();
//                     citizens.push_back(highCitizen);
//                     totalSatisfaction += highCitizen->getSatisfaction();
//                 }
//                 std::cout << num << " High Class Citizens created.\n";
//                 break;
//             }
//             case 2: {
//                 int num;
//                 std::cout << "Enter the number of Mid Class Citizens to create: ";
//                 std::cin >> num;
//                 for (int i = 0; i < num; ++i) {
//                     PrototypeCitizen* midCitizen = new MidClassCitizen();
//                     citizens.push_back(midCitizen);
//                     totalSatisfaction += midCitizen->getSatisfaction();
//                 }
//                 std::cout << num << " Mid Class Citizens created.\n";
//                 break;
//             }
//             case 3: {
//                 int num;
//                 std::cout << "Enter the number of Low Class Citizens to create: ";
//                 std::cin >> num;
//                 for (int i = 0; i < num; ++i) {
//                     PrototypeCitizen* lowCitizen = new LowClassCitizen();
//                     citizens.push_back(lowCitizen);
//                     totalSatisfaction += lowCitizen->getSatisfaction();
//                 }
//                 std::cout << num << " Low Class Citizens created.\n";
//                 break;
//             }
//             case 4: {
//                 int employmentChoice;
//                 std::cout << "Choose Citizen Class to Toggle Employment Status:\n";
//                 std::cout << "1. High Class\n";
//                 std::cout << "2. Mid Class\n";
//                 std::cout << "3. Low Class\n";
//                 std::cout << "Enter your choice: ";
//                 std::cin >> employmentChoice;
//
//                 for (PrototypeCitizen* citizen : citizens) {
//                     if ((employmentChoice == 1 && dynamic_cast<HighClassCitizen*>(citizen)) ||
//                         (employmentChoice == 2 && dynamic_cast<MidClassCitizen*>(citizen)) ||
//                         (employmentChoice == 3 && dynamic_cast<LowClassCitizen*>(citizen))) {
//                         citizen->toggleEmployment();
//                         std::cout << "Employment status toggled for a citizen of chosen class.\n";
//                     }
//                 }
//                 break;
//             }
//             case 5: {
//                 float avgSatisfaction = citizens.empty() ? 0.0 : totalSatisfaction / citizens.size();
//                 std::cout << "\n--- Citizen Information ---\n";
//                 for (PrototypeCitizen* citizen : citizens) {
//                     citizen->displayInfo();
//                 }
//                 std::cout << "\nTotal Citizens: " << PrototypeCitizen::getCitizenCount();
//                 std::cout << "\nAverage Satisfaction: " << avgSatisfaction << "\n";
//                 break;
//             }
//             case 6: {
//                 int numToKill;
//                 std::cout << "Enter the number of citizens to kill: ";
//                 std::cin >> numToKill;
//
//                 if (numToKill > static_cast<int>(citizens.size())) {
//                     std::cout << "Not enough citizens to kill. Currently, there are only " << citizens.size() << " citizens.\n";
//                     break;
//                 }
//
//                 for (int i = 0; i < numToKill; ++i) {
//                     int index = std::rand() % citizens.size();
//                     totalSatisfaction -= citizens[index]->getSatisfaction();
//                     delete citizens[index];
//                     citizens.erase(citizens.begin() + index);
//                 }
//
//                 std::cout << numToKill << " citizens have been killed.\n";
//                 break;
//             }
//             case 7: {
//                 srunning = false;
//                 std::cout << "Exiting program.\n";
//                 break;
//             }
//             default:
//                 std::cout << "Invalid choice. Please try again.\n";
//         }
//     }
//     for (PrototypeCitizen* citizen : citizens) {
//         delete citizen;
//     }
//
//     //////////////////////////////////////////////////////////////////////////////////////////////////
//
//     CityGrowthOg originator;
//     StatsCaretaker caretaker;
//     int year = 1;
//     while(true){
//         std::cout << "Year " << year << " - Enter statistics:\n";
//         CityStats current;
//         std::cout << "Population: ";
//         std::cin >> current.population;
//         std::cout << "Housing Needs: ";
//         std::cin >> current.housingNeeds;
//         std::cout << "Citizen Satisfaction: ";
//         std::cin >> current.citizenSatisfaction;
//         std::cout << "Hygiene: ";
//         std::cin >> current.hygiene;
//         std::cout << "Productivity: ";
//         std::cin >> current.productivity;
//         std::cout << "Employment Rate (%): ";
//         std::cin >> current.employmentRate;
//         originator.setState(current);
//         caretaker.addMemento(originator.saveStateToMemento());
//         if(year > 1){
//             CityStats prev = caretaker.getMemento(year-2)->getState();
//             displayPercentageChange(prev, current);
//         }
//         std::cout << "Options:\n1. Progress to next year\n2. View previous year's statistics\n3. Exit\nChoose an option: ";
//         int option;
//         std::cin >> option;
//         if(option == 1){
//             year++;
//             continue;
//         }
//         else if(option == 2){
//             if(year == 1){
//                 std::cout << "No previous year data.\n";
//             }
//             else{
//                 CityStats prev = caretaker.getMemento(year-2)->getState();
//                 std::cout << "Year " << year-1 << " Statistics:\n";
//                 displayStatistics(prev);
//             }
//         }
//         else if(option == 3){
//             std::cout << "All Years Statistics:\n";
//             for(int i=0;i<caretaker.getSize();i++){
//                 CityStats s = caretaker.getMemento(i)->getState();
//                 std::cout << "Year " << i+1 << ":\n";
//                 displayStatistics(s);
//             }
//             break;
//         }
//         else{
//             std::cout << "Invalid option.\n";
//         }
//     }
//
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// //    govtesting should go here
//
//     ////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//         CitySimulation citySim;
//
//     int highClass = 100;
//     int middleClass = 500;
//     int lowClass = 1000;
//
//     bool trunning = true;
//     while (trunning) {
//         std::cout << "============================\n";
//         std::cout << "Year " << citySim.getCurrentYear() << "\n";
//         std::cout << "Government's Total Money: " << formatMoney(citySim.getGovernmentMoney()) << "\n";
//         std::cout << "Tax Satisfaction: " << citySim.getTaxSatisfaction() << "\n";
//         std::cout << "============================\n";
//
//         std::cout << "Choose a Tax Strategy:\n";
//         std::cout << "1. Flat Tax\n";
//         std::cout << "2. Progressive Tax\n";
//         std::cout << "3. Regressive Tax\n";
//         std::cout << "4. Exit\n";
//         std::cout << "Enter your choice: ";
//
//         int choice;
//         std::cin >> choice;
//
//         std::unique_ptr<TaxStrategy> strategy = nullptr;
//         double baseRate = 0.0;
//         switch (choice) {
//             case 1:
//                 std::cout << "Enter Flat Tax rate (in %): ";
//                 std::cin >> baseRate;
//                 if (baseRate < 0.0 || baseRate > 100.0) {
//                     std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
//                     continue;
//                 }
//                 strategy = std::unique_ptr<FlatTax>(new FlatTax(baseRate));
//                 std::cout << "Selected Flat Tax Strategy with rate " << baseRate << "%.\n";
//                 break;
//             case 2:
//                 std::cout << "Enter Progressive Tax base rate (in %): ";
//                 std::cin >> baseRate;
//                 if (baseRate < 0.0 || baseRate > 100.0) {
//                     std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
//                     continue;
//                 }
//             strategy = std::unique_ptr<RegressiveTax>(new RegressiveTax(baseRate));
//                 std::cout << "Selected Progressive Tax Strategy with base rate " << baseRate << "%.\n";
//                 break;
//             case 3:
//                 std::cout << "Enter Regressive Tax base rate (in %): ";
//                 std::cin >> baseRate;
//                 if (baseRate < 0.0 || baseRate > 100.0) {
//                     std::cout << "Invalid tax rate. Must be between 0 and 100.\n";
//                     continue;
//                 }
//                 strategy = std::unique_ptr<RegressiveTax>(new RegressiveTax(baseRate));
//                 std::cout << "Selected Regressive Tax Strategy with base rate " << baseRate << "%.\n";
//                 break;
//             case 4:
//                 std::cout << "Exiting simulation.\n";
//                 trunning = false;
//                 continue;
//             default:
//                 std::cout << "Invalid choice. Please try again.\n";
//                 continue;
//         }
//
//         if (trunning) {
//             citySim.setTaxStrategy(std::move(strategy));
//
//             double taxCollected = citySim.advanceYear(highClass, middleClass, lowClass);
//
//             std::cout << "Tax collected this year: " << formatMoney(taxCollected) << "\n\n";
//         }
//     }
//
//     const std::vector<TaxMemento>& history = citySim.getTaxHistory();
//     if (!history.empty()) {
//         std::cout << "=== Tax History ===\n";
//         for (const auto& memento : history) {
//             std::cout << "Year " << memento.getYear() << "\n";
//             std::cout << "   Tax strategy: " << memento.getStrategyName() << "\n";
//             std::cout << "   Tax rate: " << memento.getBaseRate() << "%\n";
//             std::cout << "   Citizen satisfaction: " << memento.getTaxSatisfaction() << "\n";
//         }
//         std::cout << "====================\n";
//     }
//     else {
//         std::cout << "No tax history available.\n";
//     }
//
//    /////////////////////////////////////////////////////////////////////////////////////////////
//
//     double budget = 2000000.00;
//     Road road(budget);
//     TrainSystem train(budget);
//     TransportObserver observer(road, train);
//     road.attach(&observer);
//     train.attach(&observer);
//
//     bool prunning = true;
//     while(prunning){
//
//         std::cout << "Choose an action:\n";
//         std::cout << "1. Road\n";
//         std::cout << "2. Train\n";
//         std::cout << "3. View Statistics\n";
//         std::cout << "4. Exit\n";
//         std::cout << "Enter your choice: ";
//
//         int choice;
//         std::cin >> choice;
//
//         switch (choice) {
//             case 1:
//                 roadM(road);
//             break;
//             case 2:
//                 trainM(train);
//             break;
//             case 3:
//                 observer.update();
//             std::cout << "Total Transport Satisfaction: " << observer.getTransportSatisfaction() << "\n";
//             std::cout << "Total Transport Productivity: " << observer.getTransportProductivity() * 100 << "%\n";
//             std::cout << "Total City Budget: " << formatMoney(budget) << "\n";
//             break;
//             case 4:
//                 std::cout << "Exiting simulation.\n";
//             prunning = false;
//             break;
//             default:
//                 std::cout << "Invalid choice. Please try again.\n";
//         }
//     }

    // return 0;

}
