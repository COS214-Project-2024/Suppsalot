#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "LandmarkBuilding.h"
#include "BuildingFactory.h"

/**
 * @class BuildingFactory
 * @brief Abstract base class for building factories.
 */
BuildingFactory::~BuildingFactory() {}
BuildingFactory::BuildingFactory() {}

// ************************************
//          ResidentialFactory
// ************************************

/**
 * @class ResidentialFactory
 * @brief Factory class for creating residential buildings.
 */
ResidentialFactory::ResidentialFactory() {}

/**
 * @brief Creates a residential building based on the provided type.
 * @param r The type of residential building (e.g., "house", "flat", "townhouse", "estate").
 * @return A pointer to the created ResidentialBuilding object, or nullptr if the type is invalid.
 */
ResidentialBuilding* ResidentialFactory::BuildResidential(std::string r) {
    if (r == "house" || r == "House") {
        return new House();
    } else if (r == "flat" || r == "Flat") {
        return new Flat();
    } else if (r == "townhouse" || r == "Townhouse" || r == "TownHouse") {
        return new TownHouse();
    } else if (r == "estate" || r == "Estate") {
        return new Estate();
    } else {
        std::cout << "Please enter a valid residential building to build\n";
        return nullptr;
    }
}

/**
 * @brief Unsupported for ResidentialFactory, returns nullptr.
 */
CommercialBuilding* ResidentialFactory::BuildCommercial(std::string c) {(void)c; return nullptr;}

/**
 * @brief Unsupported for ResidentialFactory, returns nullptr.
 */
IndustrialBuilding* ResidentialFactory::BuildIndustrial(std::string i) {(void)i; return nullptr;}

/**
 * @brief Unsupported for ResidentialFactory, returns nullptr.
 */
LandmarkBuilding* ResidentialFactory::BuildLandmark(std::string l) {(void)l; return nullptr;}

// ************************************
//          IndustrialFactory
// ************************************

/**
 * @class IndustrialFactory
 * @brief Factory class for creating industrial buildings.
 */
IndustrialFactory::IndustrialFactory() {}

/**
 * @brief Creates an industrial building based on the provided type.
 * @param r The type of industrial building (e.g., "factory", "warehouse", "powerplant", "dam").
 * @return A pointer to the created IndustrialBuilding object, or nullptr if the type is invalid.
 */
IndustrialBuilding* IndustrialFactory::BuildIndustrial(std::string r) {
    if (r == "factory" || r == "Factory") {
        return new Factories();
    } else if (r == "warehouse" || r == "Warehouse") {
        return new WareHouses();
    } else if (r == "powerplant" || r == "PowerPlant" || r == "powerPlant") {
        return new Plants();
    } else if (r == "dam" || r == "Dam") {
        return new Dams();
    } else {
        std::cout << "Please enter a valid industrial building to build\n";
        return nullptr;
    }
}

// Unsupported for IndustrialFactory, returns nullptr.
CommercialBuilding* IndustrialFactory::BuildCommercial(std::string c) {(void)c; return nullptr;}
ResidentialBuilding* IndustrialFactory::BuildResidential(std::string r) {(void)r; return nullptr;}
LandmarkBuilding* IndustrialFactory::BuildLandmark(std::string l) {(void)l; return nullptr;}

// ************************************
//          LandmarkFactory
// ************************************

/**
 * @class LandmarkFactory
 * @brief Factory class for creating landmark buildings.
 */
LandmarkFactory::LandmarkFactory() {}

/**
 * @brief Creates a landmark building based on the provided type.
 * @param l The type of landmark (e.g., "park", "monument", "cultural").
 * @return A pointer to the created LandmarkBuilding object, or nullptr if the type is invalid.
 */
LandmarkBuilding* LandmarkFactory::BuildLandmark(std::string l) {
    if (l == "park" || l == "Park") {
        return new Park();
    } else if (l == "monument" || l == "Monument") {
        return new Monument();
    } else if (l == "cultural" || l == "Cultural") {
        return new Cultural();
    } else {
        std::cout << "Please enter a valid landmark building to build\n";
        return nullptr;
    }
}

// Unsupported for LandmarkFactory, returns nullptr.
CommercialBuilding* LandmarkFactory::BuildCommercial(std::string c) {(void)c; return nullptr;}
ResidentialBuilding* LandmarkFactory::BuildResidential(std::string r) {(void)r; return nullptr;}
IndustrialBuilding* LandmarkFactory::BuildIndustrial(std::string i) {(void)i; return nullptr;}

// ************************************
//          CommercialFactory
// ************************************

/**
 * @class CommercialFactory
 * @brief Factory class for creating commercial buildings.
 */
CommercialFactory::CommercialFactory() {}

/**
 * @brief Creates a commercial building based on the provided type.
 * @param l The type of commercial building (e.g., "mall", "shop", "office").
 * @return A pointer to the created CommercialBuilding object, or nullptr if the type is invalid.
 */
CommercialBuilding* CommercialFactory::BuildCommercial(std::string l) {
    if (l == "mall" || l == "Mall") {
        return new Mall();
    } else if (l == "shop" || l == "Shop") {
        return new Shop();
    } else if (l == "office" || l == "Office") {
        return new Office();
    } else {
        std::cout << "Please enter a valid commercial building to build\n";
        return nullptr;
    }
}

// Unsupported for CommercialFactory, returns nullptr.
LandmarkBuilding* CommercialFactory::BuildLandmark(std::string l) {(void)l; return nullptr;}
ResidentialBuilding* CommercialFactory::BuildResidential(std::string r) {(void)r; return nullptr;}
IndustrialBuilding* CommercialFactory::BuildIndustrial(std::string i) {(void)i; return nullptr;}
