#include "CommercialBuilding.h"
#include "ResourceManager.h"
#include <memory>
#include <iostream>
#include <string>

CommercialBuilding::CommercialBuilding() : resources{0,0,0}{}

void CommercialBuilding::allocateResources() {
    std::unique_ptr<ResourceManager> woodManager(new WoodManager());
    woodManager->useResource(resources.wood);
    
    std::unique_ptr<ResourceManager> steelManager(new SteelManager());
    steelManager->useResource(resources.steel);
    
    std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
    concreteManager->useResource(resources.concrete);
}

Shop::Shop(){
    resources = {500, 700, 750};  
    std::cout << "\nResources used to build a park:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();

}


Mall::Mall(){
    resources = {2000 , 2400 , 3000};
    std::cout << "\nResources used to build a park:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}

Office::Office(){
    resources = {2100,800,1400};
    std::cout << "\nResources used to build a park:\n-------------------------------------\n";
    std::cout << resources.wood << " Wood\n";
    std::cout << resources.steel << " Steel.\n";
    std::cout << resources.concrete << " Concrete.\n";
    std::cout << "-------------------------------------\n\n";

    allocateResources();
}



