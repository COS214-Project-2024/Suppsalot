#include "IndustrialBuilding.h"
#include "BuildingStatistics.h"

#include <memory>

int BuildingStatistics::FactoryCounter = 0;
int BuildingStatistics::WarehouseCounter = 0;
int BuildingStatistics::PlantCounter = 0;
int BuildingStatistics::DamCounter = 0;

IndustrialBuilding::IndustrialBuilding(): resources{0,0,0} {
}

void IndustrialBuilding::allocateResources(){
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

// now for all the derived class constructors:
Factories::Factories(){
    BuildingStatistics::FactoryCounter++;
    resources = {600,600,800};
    std::cout << "\nResources used to build a factory:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
    std::unique_ptr<ResourceManager> steelAdd(new SteelManager());
    steelAdd->incCapacityPerc(0.15);
}

WareHouses::WareHouses(){
    BuildingStatistics::WarehouseCounter++;
    resources = {400,1000,600};
    std::cout << "\nResources used to build a WareHoue:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
    std::unique_ptr<ResourceManager> woodAdd(new WoodManager());
    std::unique_ptr<ResourceManager> concreteAdd(new ConcreteManager());
    woodAdd->incCapacityPerc(0.15);
    concreteAdd->incCapacityPerc(0.15);
}

Plants::Plants(){
    BuildingStatistics::PlantCounter++;

    resources = {2000,2000,2000};
    std::cout << "\nResources used to build a Power Plant:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
    std::unique_ptr<ResourceManager> PowerAdd(new PowerManager());
    PowerAdd->incCapacityPerc(0.15);
}

Dams::Dams(){
    BuildingStatistics::DamCounter++;


    resources = {500,800,3000};
    std::cout << "\nResources used to build a Dam:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
    std::unique_ptr<ResourceManager> WaterAdd(new WaterManager());
    WaterAdd->incCapacityPerc(0.15);
}