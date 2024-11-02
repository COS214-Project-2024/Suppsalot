#include "LandmarkBuilding.h"
#include "ResourceManager.h"
#include "BuildingStatistics.h"

#include <memory>
#include <iostream>
#include <string>

int BuildingStatistics::LandmarkCounter = 0;


LandmarkBuilding::LandmarkBuilding() : resources{0, 0, 0} {}

void LandmarkBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

void LandmarkBuilding::returnResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->returnResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->returnResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->returnResource(resources.concrete);
}


//Remember: first steel, wood, concrete
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

void Park::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nPark removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

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

void Monument::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nMonument removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

Cultural::Cultural() {
    BuildingStatistics::LandmarkCounter++;
    resources = {600,160 , 800};  
    std::cout << "\nResources used to build a Cultural structure:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";
    allocateResources();
}

void Cultural::removeBuilding() {
    BuildingStatistics::LandmarkCounter--;
    returnResources();
    std::cout << "\nCultural building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

