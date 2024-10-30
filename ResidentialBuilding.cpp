#include "ResidentialBuilding.h"

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
    resources = {50, 200, 150};  
    allocateResources();
}

Flat::Flat() {
    resources = {400, 600, 300};  
    allocateResources();
}

TownHouse::TownHouse() {
    resources = {60, 250, 180};  
    allocateResources();
}

Estate::Estate() {
    resources = {1000, 4000, 4000};  
    allocateResources();
}
