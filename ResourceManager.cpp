#include "ResourceManager.h";
/*************************************
RecourseManager
**************************************/
void ResourceManager::attach(CommandInvoker* observer) {
    observers.push_back(observer);
}

void ResourceManager::detach(CommandInvoker* observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break; 
        }
    }
}

void ResourceManager::notify(const std::string& resourceType) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update(resourceType); 
    }
}

ResourceManager::~ResourceManager() {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        delete *it; 
    }
    observers.clear();
}




// all the warning of resources should be done through command, 
// make sure to change it up eventually
/*************************************
WoodManager
**************************************/
WoodManager::WoodManager(){
    initialWoodCap = 10000;
    woodCap = initialWoodCap;
    std::cout<< "Setting initial Wood Capacity to: " << initialWoodCap << std::endl;
}

WoodManager::~WoodManager()=default;

double WoodManager::getResource() const{
    return woodCap;
}

void WoodManager::useResource(double amount){
    if(woodCap - amount >= 0){
        woodCap -= amount;
        std::cout << "Remaining resources: " << woodCap << std::endl;
    }else{
        std::cout << "Not enough wood to build this item!\n";
        woodCap = 0;
    }


    if (woodCap < 3000){
        std::cout << "WARNING! Running low on Wood!\n";
    }
}

void WoodManager::incCapacityPerc(double perc){
    // take the percentage variable and divide by 100
    // and multiply by initial capacity. Add to current capacity
    woodCap += (initialWoodCap * perc/100);
    woodCap = std::ceil(woodCap);
    std::cout << "Wood capacity has increased by " << perc << "% to" << woodCap << std::endl;
}


/*************************************
SteelManager
**************************************/
SteelManager::SteelManager() : initialSteelCap(8000), steelCap(initialSteelCap) {
    std::cout << "Setting initial Steel Capacity to: " << initialSteelCap << std::endl;
}

SteelManager::~SteelManager() = default;

double SteelManager::getResource() const {
    return steelCap;
}

void SteelManager::useResource(double amount) {
    if (steelCap >= amount) {
        steelCap -= amount;
    } else {
        std::cout << "Not enough steel to build this item!\n";
        steelCap = 0;
    }

    std::cout << "Remaining resources: " << steelCap << std::endl;

    if (steelCap < 2000) {
        std::cout << "WARNING! Running low on Steel!\n";
    }
}

void SteelManager::incCapacityPerc(double perc) {
    steelCap += std::ceil(initialSteelCap * (perc / 100));
    std::cout << "Steel capacity has increased by " << perc << "% to " << steelCap << std::endl;
}

/*************************************
ConcreteManager
**************************************/
ConcreteManager::ConcreteManager() : initialConcreteCap(12000), concreteCap(initialConcreteCap) {
    std::cout << "Setting initial Concrete Capacity to: " << initialConcreteCap << std::endl;
}

ConcreteManager::~ConcreteManager() = default;

double ConcreteManager::getResource() const {
    return concreteCap;
}

void ConcreteManager::useResource(double amount) {
    if (concreteCap >= amount) {
        concreteCap -= amount;
    } else {
        std::cout << "Not enough concrete to build this item!\n";
        concreteCap = 0;
    }

    std::cout << "Remaining resources: " << concreteCap << std::endl;

    if (concreteCap < 4000) {
        std::cout << "WARNING! Running low on Concrete!\n";
    }
}

void ConcreteManager::incCapacityPerc(double perc) {
    concreteCap += std::ceil(initialConcreteCap * (perc / 100));
    std::cout << "Concrete capacity has increased by " << perc << "% to " << concreteCap << std::endl;
}

/*************************************
WaterManager
**************************************/
WaterManager::WaterManager() : initialWaterCap(20000), waterCap(initialWaterCap) {
    std::cout << "Setting initial Water Capacity to: " << initialWaterCap << std::endl;
}

WaterManager::~WaterManager() = default;

double WaterManager::getResource() const {
    return waterCap;
}

void WaterManager::useResource(double amount) {
    if (waterCap >= amount) {
        waterCap -= amount;
    } else {
        std::cout << "Not enough water to build this item!\n";
        waterCap = 0;
    }

    std::cout << "Remaining resources: " << waterCap << std::endl;

    if (waterCap < 5000) {
        std::cout << "WARNING! Running low on Water! A draught may be approuching!\n";
    }
}

void WaterManager::incCapacityPerc(double perc) {
    waterCap += std::ceil(initialWaterCap * (perc / 100));
    std::cout << "Water capacity has increased by " << perc << "% to " << waterCap << std::endl;
}

/*************************************
PowerManager
**************************************/
PowerManager::PowerManager() : initialPowerCap(25000), powerCap(initialPowerCap) {
    std::cout << "Setting initial Power Capacity to: " << initialPowerCap << std::endl;
}

PowerManager::~PowerManager() = default;

double PowerManager::getResource() const {
    return powerCap;
}

void PowerManager::useResource(double amount) {
    if (powerCap >= amount) {
        powerCap -= amount;
    } else {
        std::cout << "Not enough power to build this item!\n";
        powerCap = 0;
    }

    std::cout << "Remaining resources: " << powerCap << std::endl;

    if (powerCap < 6000) {
        std::cout << "WARNING! Running low on Power!Switching to Nuclear power soon!\n";
    }
    if (powerCap == 0){
        std::cout << "Switch to Nuclear power!\n";
    }
}

void PowerManager::incCapacityPerc(double perc) {
    powerCap += std::ceil(initialPowerCap * (perc / 100));
    std::cout << "Power capacity has increased by " << perc << "% to " << powerCap << std::endl;
}

void PowerManager::switchToNuclear(){
    std::cout << "************************\nCRITICAL NOTICE\n***********************\n";
    std::cout << "Your city has run out of electricty!\n";
    std::cout << "Switching to nuclear power.\n";
    std::cout << "Note: Not being careful will be the downfall of your city.\n";
    powerCap += 15000;
}

void PowerManager::endWorld(){
    std::cout << "************************\nCRITICAL NOTICE\n***********************\n";
    std::cout << "NUCLEAR FAILURE OCCURED!\n";
    std::cout << "3...\n2...\n1...\n\n\n\n\n\n\n\n...\nBOOOOMMMMMM!!!\n\n\n\n\n\n\n\n\n\n\n\n\n.";
    exit(0); // the program must end once the game gets to this point.
}
