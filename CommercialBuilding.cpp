#include "CommercialBuilding.h"
#include "ResourceManager.h"
#include "BuildingStatistics.h"
#include <memory>
#include <iostream>
#include <string>

/**
 * @file CommercialBuilding.cpp
 * @brief Implements the CommercialBuilding and its derived classes (Shop, Mall, Office) with resource allocation and deallocation.
 */

/** @brief Initializes static counters for each commercial building type. */
int BuildingStatistics::ShopCounter = 0;
int BuildingStatistics::MallCounter = 0;
int BuildingStatistics::OfficeCounter = 0;

/**
 * @class CommercialBuilding
 * @brief Base class representing a generic commercial building.
 * Handles resource allocation and deallocation for construction and removal.
 */
CommercialBuilding::CommercialBuilding() : resources{0, 0, 0} {}

/**
 * @brief Allocates resources required for the building.
 */
void CommercialBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);

    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);

    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

/**
 * @brief Returns allocated resources when a building is removed.
 */
void CommercialBuilding::returnResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->returnResource(resources.wood);

    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->returnResource(resources.steel);

    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->returnResource(resources.concrete);
}

// ************************************
//          Shop
// ************************************

/**
 * @class Shop
 * @brief Class representing a shop building.
 * Increments ShopCounter upon creation and allocates specific resources.
 */
Shop::Shop() {
    BuildingStatistics::ShopCounter++;

    resources = {500, 800, 750};
    std::cout << "\nResources used to build a shop:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

/**
 * @brief Removes the shop building, deallocates resources, and decrements ShopCounter.
 */
void Shop::removeBuilding() {
    BuildingStatistics::ShopCounter--;
    returnResources();
    std::cout << "\nShop building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

// ************************************
//          Mall
// ************************************

/**
 * @class Mall
 * @brief Class representing a mall building.
 * Increments MallCounter upon creation and allocates specific resources.
 */
Mall::Mall() {
    BuildingStatistics::MallCounter++;

    resources = {2000, 2400, 3000};
    std::cout << "\nResources used to build a Mall:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

/**
 * @brief Removes the mall building, deallocates resources, and decrements MallCounter.
 */
void Mall::removeBuilding() {
    BuildingStatistics::MallCounter--;
    returnResources();
    std::cout << "\nMall building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

// ************************************
//          Office
// ************************************

/**
 * @class Office
 * @brief Class representing an office building.
 * Increments OfficeCounter upon creation and allocates specific resources.
 */
Office::Office() {
    BuildingStatistics::OfficeCounter++;

    resources = {2100, 800, 1400};
    std::cout << "\nResources used to build an Office:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources
