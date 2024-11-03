#include "LandmarkBuilding.h"
#include "ResourceManager.h"
#include "BuildingStatistics.h"

#include <memory>
#include <iostream>
#include <string>

/**
 * @file LandmarkBuilding.cpp
 * @brief Implements the LandmarkBuilding class and its derived classes (Park, Monument, Cultural) with resource allocation and deallocation.
 */

/** @brief Initializes static counter for landmark buildings. */
int BuildingStatistics::LandmarkCounter = 0;

/**
 * @class LandmarkBuilding
 * @brief Base class for a generic landmark building.
 * Handles resource allocation and deallocation for construction and removal of landmark buildings.
 */
LandmarkBuilding::LandmarkBuilding() : resources{0, 0, 0} {}

/**
 * @brief Allocates resources required for constructing the landmark building.
 */
void LandmarkBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);

    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);

    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

/**
 * @brief Returns allocated resources when a landmark building is removed.
 */
void LandmarkBuilding::returnResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->returnResource(resources.wood);

    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->returnResource(resources.steel);

    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->returnResource(resources.concrete);
}

// ************************************
//          Park
// ************************************

/**
 * @class Park
 * @brief Class representing a park building.
 * Increments LandmarkCounter upon creation and allocates specific resources.
 */
Park::Park() {
    BuildingStatistics::LandmarkCounter++;
    resources = {50, 600, 250};
    std::cout << "\nResources used to build a park:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

/**
 * @brief Removes the park building, deallocates resources, and decrements LandmarkCounter.
 */
void Park::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nPark removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

// ************************************
//          Monument
// ************************************

/**
 * @class Monument
 * @brief Class representing a monument building.
 * Increments LandmarkCounter upon creation and allocates specific resources.
 */
Monument::Monument() {
    BuildingStatistics::LandmarkCounter++;
    resources = {400, 550, 200};
    std::cout << "\nResources used to build a Monument:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}

/**
 * @brief Removes the monument building, deallocates resources, and decrements LandmarkCounter.
 */
void Monument::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nMonument removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

// ************************************
//          Cultural
// ************************************

/**
 * @class Cultural
 * @brief Class representing a cultural building.
 * Increments LandmarkCounter upon creation and allocates specific resources.
 */
Cultural::Cultural() {
    BuildingStatistics::LandmarkCounter++;
    resources = {600, 160, 800};
    std::cout << "\nResources used to build a Cultural structure:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}

/**
 * @brief Removes the cultural building, deallocates resources, and decrements LandmarkCounter.
 */
void Cultural::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nCultural building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}
