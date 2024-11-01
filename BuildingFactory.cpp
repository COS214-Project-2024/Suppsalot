#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "IndustrialBuilding.h"
#include "LandmarkBuilding.h"
#include "BuildingFactory.h"


BuildingFactory::~BuildingFactory() {}
BuildingFactory::BuildingFactory() {}

// ************************************
//          ResidentialFactory
// ************************************

ResidentialFactory::ResidentialFactory(){}


ResidentialBuilding* ResidentialFactory::BuildResidential(std::string r) {

    if (r == "house" || r == "House") {
        return new House();
    } else if (r == "flat" || r == "Flat") {
        return new Flat();
    } else if (r == "townhouse" || r=="Townhouse" || r == "TownHouse") {
        return new TownHouse();
    } else if (r == "estate" || r == "Estate") {
        return new Estate();
    } else {
        std::cout << "Please enter a valid residential building to build\n";
        return nullptr; // Return nullptr if the input is invalid
    }
}

// the others are not handled over here
CommercialBuilding* ResidentialFactory::BuildCommercial(std::string c){return nullptr;}
IndustrialBuilding* ResidentialFactory::BuildIndustrial(std::string i){return nullptr;}
LandmarkBuilding* ResidentialFactory::BuildLandmark(std::string l){return nullptr;}


// ************************************
//          IndustrialFactory
// ************************************

IndustrialFactory::IndustrialFactory() {}

IndustrialBuilding* IndustrialFactory::BuildIndustrial(std::string r) {
    if (r == "factory" || r == "Factory") {
        return new Factories();
    } else if (r == "warehouse" || r == "Warehouse") {
        return new WareHouses();
    } else if (r == "powerplant" || r == "PowerPlant" || "powerPlant") {
        return new Plants();
    } else if (r == "dam" || r == "Dam"){
        return new Dams();
    }
    else {
        std::cout << "Please enter a valid industrial building to build\n";
        return nullptr; 
    }
}

// The others are not handled over here
CommercialBuilding* IndustrialFactory::BuildCommercial(std::string c) {
    (void)c; 
    return nullptr;
}
ResidentialBuilding* IndustrialFactory::BuildResidential(std::string r) {
    (void)r; 
    return nullptr;
}
LandmarkBuilding* IndustrialFactory::BuildLandmark(std::string l) {
    (void)l; 
    return nullptr;
}

// ************************************
//          LandmarkFactory
// ************************************
LandmarkFactory::LandmarkFactory(){}

LandmarkBuilding* LandmarkFactory::BuildLandmark(std::string l){
    if (l == "park" || l == "Park") {
        return new Park();
    } else if (l == "monument" || l == "Monument") {
        return new Monument();
    } else if (l == "cultural" || l == "Cultural") {
        return new Cultural();
    }
    else {
        std::cout << "Please enter a valid industrial building to build\n";
        return nullptr; 
    }
}

CommercialBuilding* LandmarkFactory::BuildCommercial(std::string c) {
    (void)c; 
    return nullptr;
}
ResidentialBuilding* LandmarkFactory::BuildResidential(std::string r) {
    (void)r; 
    return nullptr;
}
IndustrialBuilding* LandmarkFactory::BuildIndustrial(std::string i){
    (void)i;
    return nullptr;
}
