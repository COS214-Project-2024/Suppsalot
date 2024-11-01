#include "ResidentialBuilding.h"
#include "BuildingStatistics.h"

int BuildingStatistics::HouseCounter = 0;
int BuildingStatistics::FlatCounter = 0;
int BuildingStatistics::TownhouseCounter = 0;
int BuildingStatistics::EstateCounter = 0;

ResidentialBuilding::ResidentialBuilding() : resources{0, 0, 0} {}

void ResidentialBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

//Remember: first steel, wood, concrete
House::House() {
    BuildingStatistics::HouseCounter++;
    resources = {50, 200, 150};  
    std::cout << "\nResources used to build a house:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

Flat::Flat() {
    BuildingStatistics::FlatCounter++;
    resources = {400, 600, 300};  
    std::cout << "\nResources used to build a Flat:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}

TownHouse::TownHouse() {
    BuildingStatistics::TownhouseCounter++;

    resources = {60, 250, 180};  
    std::cout << "\nResources used to build a TownHouse:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}

Estate::Estate() {
    BuildingStatistics::EstateCounter++;

    resources = {1000, 4000, 4000};  
    std::cout << "\nResources used to build an Estate:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}
