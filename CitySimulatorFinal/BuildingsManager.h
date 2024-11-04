#ifndef BUILDINGSMANAGER_H
#define BUILDINGSMANAGER_H

#include "BuildingFactory.h"
#include "ResourceManager.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include "ResidentialBuilding.h"
#include "LandmarkBuilding.h"
#include "BuildingStatistics.h"

#include <iostream>
#include <memory>
#include <vector>
#include <string>

void showMainMenu();
void showBuildingOptions(const std::string& buildingType);

class BuildingsManager {
public:
    BuildingsManager(double& cityBudgetRef)
        : cityBudget(cityBudgetRef),
          rm(new WoodManager()),
          rm1(new SteelManager()),
          rm2(new ConcreteManager()),
          rm3(new PowerManager()),
          rm4(new WaterManager()),
          residentialFactory(),
          industrialFactory(),
          commercialFactory(),
          landmarkFactory()
    {
        std::cout << "********************************************\n";
        std::cout << "           Resource Managers Initialized     \n";
        std::cout << "********************************************\n\n";
    }

    ~BuildingsManager() {
        delete rm;
        delete rm1;
        delete rm2;
        delete rm3;
        delete rm4;
    }

    void manageBuildings() {
        bool running = true;
        while (running) {
            showMainMenu();
            int mainChoice;
            std::cin >> mainChoice;

            switch (mainChoice) {
                case 1: { 
                    showBuildingOptions("Industrial");
                    int industrialChoice;
                    std::cin >> industrialChoice;
                    switch (industrialChoice) {
                        case 1: 
                            industrialBuildings.emplace_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("factory")));
                            std::cout << "[Building] Factory has been built.\n";
                            break;
                        case 2: 
                            industrialBuildings.emplace_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("warehouse")));
                            std::cout << "[Building] Warehouse has been built.\n";
                            break;
                        case 3: 
                            industrialBuildings.emplace_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("plant")));
                            std::cout << "[Building] PowerPlant has been built.\n";
                            break;
                        case 4: 
                            industrialBuildings.emplace_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("dam")));
                            std::cout << "[Building] Dam has been built.\n";
                            break;
                        default: 
                            std::cout << "Invalid choice!\n"; 
                            break;
                    }
                    break;
                }
                case 2: { 
                    showBuildingOptions("Commercial");
                    int commercialChoice;
                    std::cin >> commercialChoice;
                    switch (commercialChoice) {
                        case 1: 
                            commercialBuildings.emplace_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("shop")));
                            std::cout << "[Building] Shop has been built.\n";
                            break;
                        case 2: 
                            commercialBuildings.emplace_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("mall")));
                            std::cout << "[Building] Mall has been built.\n";
                            break;
                        case 3: 
                            commercialBuildings.emplace_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("office")));
                            std::cout << "[Building] Office has been built.\n";
                            break;
                        default: 
                            std::cout << "Invalid choice!\n"; 
                            break;
                    }
                    break;
                }
                case 3: {
                    showBuildingOptions("Residential");
                    int residentialChoice;
                    std::cin >> residentialChoice;
                    switch (residentialChoice) {
                        case 1: 
                            residentialBuildings.emplace_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("house")));
                            std::cout << "[Building] House has been built.\n";
                            break;
                        case 2: 
                            residentialBuildings.emplace_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("flat")));
                            std::cout << "[Building] Flat has been built.\n";
                            break;
                        case 3: 
                            residentialBuildings.emplace_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("townhouse")));
                            std::cout << "[Building] Townhouse has been built.\n";
                            break;
                        case 4: 
                            residentialBuildings.emplace_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("estate")));
                            std::cout << "[Building] Estate has been built.\n";
                            break;
                        default: 
                            std::cout << "Invalid choice!\n"; 
                            break;
                    }
                    break;
                }
                case 4: {
                    showBuildingOptions("Landmark");
                    int landmarkChoice;
                    std::cin >> landmarkChoice;
                    switch (landmarkChoice) {
                        case 1: 
                            landmarkBuildings.emplace_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Park")));
                            std::cout << "[Building] Park has been built.\n";
                            break;
                        case 2: 
                            landmarkBuildings.emplace_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Monument")));
                            std::cout << "[Building] Monument has been built.\n";
                            break;
                        case 3: 
                            landmarkBuildings.emplace_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Cultural")));
                            std::cout << "[Building] Cultural Building has been built.\n";
                            break;
                        default: 
                            std::cout << "Invalid choice!\n"; 
                            break;
                    }
                    break;
                }
                case 5: { 
                    removeBuilding();
                    break;
                }
                case 6: { 
                    running = false;
                    break;
                }
                default: {
                    std::cout << "Invalid choice! Please try again.\n";
                    break;
                }
            }
        }
    }

    void progressYear() {
        BuildingStatistics::YearResourceIncrease();
        std::cout << "Resources have been increased for the year.\n";
    }

    double getRemainingWood() const { return rm->getResource(); }
    double getRemainingSteel() const { return rm1->getResource(); }
    double getRemainingConcrete() const { return rm2->getResource(); }
    double getRemainingPower() const { return rm3->getResource(); }
    double getRemainingWater() const { return rm4->getResource(); }

private:
    double& cityBudget;

    ResourceManager* rm;
    ResourceManager* rm1;
    ResourceManager* rm2;
    ResourceManager* rm3;
    ResourceManager* rm4;

    ResidentialFactory residentialFactory;
    IndustrialFactory industrialFactory;
    CommercialFactory commercialFactory;
    LandmarkFactory landmarkFactory;

    std::vector<std::unique_ptr<ResidentialBuilding>> residentialBuildings;
    std::vector<std::unique_ptr<IndustrialBuilding>> industrialBuildings;
    std::vector<std::unique_ptr<LandmarkBuilding>> landmarkBuildings;
    std::vector<std::unique_ptr<CommercialBuilding>> commercialBuildings;

    void showMainMenu() {
        std::cout << "\n=========================================\n";
        std::cout << "       Building Management System        \n";
        std::cout << "=========================================\n";
        std::cout << "1. Build Industrial Building\n";
        std::cout << "2. Build Commercial Building\n";
        std::cout << "3. Build Residential Building\n";
        std::cout << "4. Build Landmark Building\n";
        std::cout << "5. Remove a Building\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
    }

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

    void removeBuilding() {
        std::cout << "Choose a type of building to remove:\n";
        std::cout << "1. Residential\n";
        std::cout << "2. Industrial\n";
        std::cout << "3. Landmark\n";
        std::cout << "4. Commercial\n";
        std::cout << "Enter your choice: ";
        int buildingType;
        std::cin >> buildingType;

        switch (buildingType) {
            case 1: { 
                if (!residentialBuildings.empty()) {
                    residentialBuildings.back()->removeBuilding();
                    residentialBuildings.pop_back();
                } else {
                    std::cout << "No Residential Buildings to remove!\n";
                }
                break;
            }
            case 2: { 
                if (!industrialBuildings.empty()) {
                    industrialBuildings.back()->removeBuilding();
                    industrialBuildings.pop_back();
                } else {
                    std::cout << "No Industrial Buildings to remove!\n";
                }
                break;
            }
            case 3: { 
                if (!landmarkBuildings.empty()) {
                    landmarkBuildings.back()->removeBuilding();
                    landmarkBuildings.pop_back();
                } else {
                    std::cout << "No Landmark Buildings to remove!\n";
                }
                break;
            }
            case 4: { 
                if (!commercialBuildings.empty()) {
                    commercialBuildings.back()->removeBuilding();
                    commercialBuildings.pop_back();
                } else {
                    std::cout << "No Commercial Buildings to remove!\n";
                }
                break;
            }
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
};

#endif 