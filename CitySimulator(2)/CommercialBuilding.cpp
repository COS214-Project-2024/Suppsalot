#include "CommercialBuilding.h"
#include "ResourceManager.h"
#include "BuildingStatistics.h"
#include <memory>
#include <iostream>
#include <string>

int BuildingStatistics::ShopCounter = 0;
int BuildingStatistics::MallCounter = 0;
int BuildingStatistics::OfficeCounter = 0;

CommercialBuilding::CommercialBuilding() : resources{0,0,0}{}

void CommercialBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

void CommercialBuilding::returnResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->returnResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->returnResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->returnResource(resources.concrete);
}

Shop::Shop(){
    BuildingStatistics::ShopCounter++;

    resources = {500, 800, 750};  
    std::cout << "\nResources used to build a shop:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();

}

void Shop::removeBuilding() {
    //decrease number of shop counters:
    BuildingStatistics::ShopCounter--;
    returnResources();
    std::cout << "\nShop building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}


Mall::Mall(){
    BuildingStatistics::MallCounter++;

    resources = {2000 , 2400 , 3000};
    std::cout << "\nResources used to build a Mall:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

void Mall::removeBuilding(){
    BuildingStatistics::MallCounter--;
    returnResources();
    std::cout << "\nMall building removed:\n-------------------------------------\n";
    std::cout << "\nShop building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}

Office::Office(){
    BuildingStatistics::OfficeCounter++;

    resources = {2100,800,1400};
    std::cout << "\nResources used to build an Office:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

void Office::removeBuilding(){
    BuildingStatistics::OfficeCounter--;
    returnResources();
    std::cout << "\nOffice building removed:\n-------------------------------------\n";
    std::cout << "\nShop building removed:\n-------------------------------------\n";
    std::cout << "Returned Wood: " << resources.wood << std::endl;
    std::cout << "Returned Steel: " << resources.steel << std::endl;
    std::cout << "Returned Concrete: " << resources.concrete << std::endl;
    std::cout << "-------------------------------------\n\n";
}



