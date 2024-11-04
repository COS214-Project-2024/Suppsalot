// #include "ResourceManager.h";
// /*************************************
// RecourseManager
// **************************************/
// void ResourceManager::attach(CommandInvoker* observer) {
//     observers.push_back(observer);
// }

// void ResourceManager::detach(CommandInvoker* observer) {
//     for (auto it = observers.begin(); it != observers.end(); ++it) {
//         if (*it == observer) {
//             observers.erase(it);
//             break; 
//         }
//     }
// }

// void ResourceManager::notify(const std::string& resourceType) {
//     for (auto it = observers.begin(); it != observers.end(); ++it) {
//         (*it)->update(resourceType); 
//     }
// }

// ResourceManager::~ResourceManager() {
//     for (auto it = observers.begin(); it != observers.end(); ++it) {
//         delete *it; 
//     }
//     observers.clear();
// }




// // all the warning of resources should be done through command, 
// // make sure to change it up eventually
// /*************************************
// WoodManager
// **************************************/
// WoodManager::WoodManager(){
//     initialWoodCap = 10000;
//     woodCap = initialWoodCap;
//     std::cout<< "Setting initial Wood Capacity to: " << initialWoodCap << std::endl;
// }

// WoodManager::~WoodManager()=default;

// double WoodManager::getResource() const{
//     return woodCap;
// }

// void WoodManager::useResource(double amount){
//     if(woodCap - amount >= 0){
//         woodCap -= amount;
//         std::cout << "Remaining resources: " << woodCap << std::endl;
//     }else{
//         std::cout << "Not enough wood to build this item!\n";
//         woodCap = 0;
//     }


//     if (woodCap < 3000){
//         std::cout << "WARNING! Running low on Wood!\n";
//     }
// }

// void WoodManager::incCapacityPerc(double perc){
//     // take the percentage variable and divide by 100
//     // and multiply by initial capacity. Add to current capacity
//     woodCap += (initialWoodCap * perc/100);
//     woodCap = std::ceil(woodCap);
//     std::cout << "Wood capacity has increased by " << perc << "% to" << woodCap << std::endl;
// }


// /*************************************
// SteelManager
// **************************************/
// SteelManager::SteelManager() : initialSteelCap(8000), steelCap(initialSteelCap) {
//     std::cout << "Setting initial Steel Capacity to: " << initialSteelCap << std::endl;
// }

// SteelManager::~SteelManager() = default;

// double SteelManager::getResource() const {
//     return steelCap;
// }

// void SteelManager::useResource(double amount) {
//     if (steelCap >= amount) {
//         steelCap -= amount;
//     } else {
//         std::cout << "Not enough steel to build this item!\n";
//         steelCap = 0;
//     }

//     std::cout << "Remaining resources: " << steelCap << std::endl;

//     if (steelCap < 2000) {
//         std::cout << "WARNING! Running low on Steel!\n";
//     }
// }

// void SteelManager::incCapacityPerc(double perc) {
//     steelCap += std::ceil(initialSteelCap * (perc / 100));
//     std::cout << "Steel capacity has increased by " << perc << "% to " << steelCap << std::endl;
// }

// /*************************************
// ConcreteManager
// **************************************/
// ConcreteManager::ConcreteManager() : initialConcreteCap(12000), concreteCap(initialConcreteCap) {
//     std::cout << "Setting initial Concrete Capacity to: " << initialConcreteCap << std::endl;
// }

// ConcreteManager::~ConcreteManager() = default;

// double ConcreteManager::getResource() const {
//     return concreteCap;
// }

// void ConcreteManager::useResource(double amount) {
//     if (concreteCap >= amount) {
//         concreteCap -= amount;
//     } else {
//         std::cout << "Not enough concrete to build this item!\n";
//         concreteCap = 0;
//     }

//     std::cout << "Remaining resources: " << concreteCap << std::endl;

//     if (concreteCap < 4000) {
//         std::cout << "WARNING! Running low on Concrete!\n";
//     }
// }

// void ConcreteManager::incCapacityPerc(double perc) {
//     concreteCap += std::ceil(initialConcreteCap * (perc / 100));
//     std::cout << "Concrete capacity has increased by " << perc << "% to " << concreteCap << std::endl;
// }

// /*************************************
// WaterManager
// **************************************/
// WaterManager::WaterManager() : initialWaterCap(20000), waterCap(initialWaterCap) {
//     std::cout << "Setting initial Water Capacity to: " << initialWaterCap << std::endl;
//     invoker = new CommandInvoker();

//     // adding the command that could be used
//     // invoker->addCommand("emergencyRefill", new EmergencyRefillCommand());
//     // invoker->addCommand("enterDrought", new EnterDroughtCommand(this));

// }

// WaterManager::~WaterManager(){
//     delete invoker;
// };

// double WaterManager::getResource() const {
//     return waterCap;
// }

// void WaterManager::useResource(double amount) {
//     if (waterCap >= amount) {
//         waterCap -= amount;
//     } else {
//         std::cout << "Not enough water to build this item!\n";
//         waterCap = 0;
//     }

//     std::cout << "Remaining resources: " << waterCap << std::endl;

//     if (waterCap < 5000) {
//         std::cout << "WARNING! Running low on Water! A draught may be approuching!\n";
//     }

//     //trigger command over here
//     if (waterCap == 0) {
//         if (reserve) {
//             invoker->update("emergencyRefill");
//         } else {
//             invoker->update("enterDrought");
//         }
//     }
// }

// void WaterManager::incCapacityPerc(double perc) {
//     waterCap += std::ceil(initialWaterCap * (perc / 100));
//     std::cout << "Water capacity has increased by " << perc << "% to " << waterCap << std::endl;
// }

// void WaterManager::EmergencyRefill(){
//     std::cout << "************************************************\n";
//     std::cout << "                  CRITICAL NOTICE\n";
//     std::cout << "************************************************\n";    
//     std::cout << "Water reservoirs have been depleted.\n";
//     std::cout << "Opening up damn walls with accumulated rain water over the year.\n";
//     std::cout<< "This is a final warning!!! Without water your city cannot be maintained.\n";
//     waterCap+=15000;
//     std::cout << "Water capacity after refill: " << waterCap << std::endl;
// }

// void WaterManager::enterDraught(){
//     std::cout << "************************************************\n";
//     std::cout << "                  CRITICAL NOTICE\n";
//     std::cout << "************************************************\n";
//     std::cout << "      A WORLDWIDE WATER CRISIS HAS ERUPTED!\n";
//     std::cout << "       DRAUGHT IS UPON US! Satisfaction Rates are PLUMMETING!\n";
//     std::cout << "       CROPS WITHERING, BARREN FIELDS EVERYWHERE!\n";
//     std::cout << "       PEOPLE SLOWLY FADING AWAY IN DESPAIR.\n";
//     std::cout << "     ABSOLUTELY NOTHING CAN BE DONE. FAREWELL.\n";
//     std::cout << "************************************************\n";
//     exit(0); // program must end here
// }

// /*************************************
// PowerManager
// **************************************/
// PowerManager::PowerManager() : initialPowerCap(25000), powerCap(initialPowerCap) {
//     std::cout << "Setting initial Power Capacity to: " << initialPowerCap << std::endl;
//     invoker = new CommandInvoker();
// }

// PowerManager::~PowerManager(){
//     delete invoker;
// };

// double PowerManager::getResource() const {
//     return powerCap;
// }

// void PowerManager::useResource(double amount) {
//     if (powerCap >= amount) {
//         powerCap -= amount;
//     } else {
//         std::cout << "Not enough power to build this item!\n";
//         powerCap = 0;
//     }

//     std::cout << "Remaining resources: " << powerCap << std::endl;

//     if (powerCap < 6000) {
//         std::cout << "WARNING! Running low on Power!Switching to Nuclear power soon!\n";
//     }

//     // trigger the command
//     if (powerCap == 0) {
//         if (reserve) {
//             invoker->update("switchToNuclear");
//         } else {
//             invoker->update("endWorld");
//         }
//     }

// }

// void PowerManager::incCapacityPerc(double perc) {
//     powerCap += std::ceil(initialPowerCap * (perc / 100));
//     std::cout << "Power capacity has increased by " << perc << "% to " << powerCap << std::endl;
// }

// void PowerManager::switchToNuclear(){
//     std::cout << "************************************************\n";
//     std::cout << "                  CRITICAL NOTICE\n";
//     std::cout << "************************************************\n";    
//     std::cout << "Your city has run out of electricty!\n";
//     std::cout << "Switching to nuclear power.\n";
//     std::cout << "Note: Not being careful will be the downfall of your city.\n";
//     powerCap += 17000;
//     std::cout << "Nuclear power capacity: " << powerCap << std::endl;
// }

// void PowerManager::endWorld(){
//     std::cout << "************************************************\n";
//     std::cout << "                  CRITICAL NOTICE\n";
//     std::cout << "************************************************\n";
//     std::cout << "      NUCLEAR CATASTROPHE IMMINENT!\n";
//     std::cout << "                  3...\n";
//     std::cout << "                     2...\n";
//     std::cout << "                        1...\n";
//     std::cout << "\n\n\n\n\n\n\n\n...\n";
//     std::cout << "                BOOOOOMMMMMM!!!\n";
//     std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
//     std::cout << "THE END OF EVERYTHING AS WE KNOW IT.\n";
//     std::cout << "************************************************\n";
//     exit(0); // program must lend here.
// }


// A little bit of a different idea in this case, this time the observer will not be connected to command in utilites as that just caused  a bunch of circular dependencies, UTILITIES will be used in another way
#include "ResourceManager.h"
/*************************************
RecourseManager
**************************************/
void ResourceManager::attach(ResourceObserver* observer) {
    observers.push_back(observer);
}

void ResourceManager::detach(ResourceObserver* observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break; 
        }
    }
}

ResourceManager::~ResourceManager() {
    observers.clear();
}


void ResourceManager::notifyObservers(const std::string& resourceType, double currentLevel) {
    for (auto observer : observers) {
        if (observer != nullptr) {  // Check if observer is not a nullptr
            observer->update(resourceType, currentLevel);
        }
    }

}


// all the warning of resources should be done through command, 
// make sure to change it up eventually
/*************************************
WoodManager
**************************************/

double WoodManager::woodCap = 10000;
double WoodManager::initialWoodCap = 10000;
bool WoodManager::isInitialized = false;

WoodManager::WoodManager(){
    if (!isInitialized) {
        std::cout << "Setting initial Wood Capacity to: " << initialWoodCap << std::endl;
        isInitialized = true;
    }
}

WoodManager::~WoodManager()=default;

double WoodManager::getResource() const{
    return woodCap;
}

void WoodManager::useResource(double amount){
    if(woodCap - amount >= 0){
        woodCap -= amount;
        std::cout << "Remaining Wood: " << woodCap << std::endl;
    }else{
        std::cout << "Not enough wood to build this item!\n";
        woodCap = 0;
    }


    if (woodCap < 3000){
        // std::cout << "WARNING! Running low on Wood!\n";
        notifyObservers("Wood",woodCap);
    }
}

void WoodManager::returnResource(double amount){
    woodCap += amount;
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
double SteelManager::steelCap = 8000;
double SteelManager::initialSteelCap = 8000;
bool SteelManager::isInitialized = false;

SteelManager::SteelManager() {
    if (!isInitialized) {
        std::cout << "Setting initial Steel Capacity to: " << initialSteelCap << std::endl;
        isInitialized = true;
    }
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

    std::cout << "Remaining Steel: " << steelCap << std::endl;

    if (steelCap < 2000) {
        std::cout << "WARNING! Running low on Steel!\n";
        notifyObservers("Steel",steelCap);
    }
}

void SteelManager::returnResource(double amount){
    steelCap += amount;
}

void SteelManager::incCapacityPerc(double perc) {
    steelCap += std::ceil(initialSteelCap * (perc / 100));
    std::cout << "Steel capacity has increased by " << perc << "% to " << steelCap << std::endl;
}

/*************************************
ConcreteManager
**************************************/
double ConcreteManager::concreteCap = 12000;
double ConcreteManager::initialConcreteCap = 12000;
bool ConcreteManager::isInitialized = false;

ConcreteManager::ConcreteManager() {
    if (!isInitialized) {
        std::cout << "Setting initial Concrete Capacity to: " << initialConcreteCap << std::endl;
        isInitialized = true;
    }
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

    std::cout << "Remaining Concrete: " << concreteCap << std::endl;

    if (concreteCap < 4000) {
        std::cout << "WARNING! Running low on Concrete!\n";
        notifyObservers("Concrete", concreteCap);
    }
}

void ConcreteManager::returnResource(double amount){
    concreteCap += amount;
}

void ConcreteManager::incCapacityPerc(double perc) {
    concreteCap += std::ceil(initialConcreteCap * (perc / 100));
    std::cout << "Concrete capacity has increased by " << perc << "% to " << concreteCap << std::endl;
}

/*************************************
WaterManager
**************************************/
double WaterManager::waterCap = 20000;
double WaterManager::initialWaterCap = 20000;
bool WaterManager::isInitialized = false;
bool WaterManager::reserve = true; 


WaterManager::WaterManager() {
    if (!isInitialized) {
        std::cout << "Setting initial Water Capacity to: " << initialWaterCap << std::endl;
        isInitialized = true;
    }
}

// WaterManager::WaterManager() : initialWaterCap(20000), waterCap(20000) {
//     std::cout << "Setting initial Water Capacity to: " << initialWaterCap << std::endl;
//     // invoker = new CommandInvoker();

//     // adding the command that could be used
//     // invoker->addCommand("emergencyRefill", new EmergencyRefillCommand());
//     // invoker->addCommand("enterDrought", new EnterDroughtCommand(this));

// }

WaterManager::~WaterManager(){
    // delete invoker;
};

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

    std::cout << "Remaining Water: " << waterCap << std::endl;

    if (waterCap < 5000) {
        std::cout << "WARNING! Running low on Water! A draught may be approuching!\n";
        notifyObservers("Water",waterCap);
    }

    //trigger command over here
    if (waterCap == 0) {
        if (reserve) {
            // invoker->update("emergencyRefill");
            EmergencyRefill();
            reserve = false;
        } else {
            enterDraught();
            // invoker->update("enterDrought");
        }
    }
}

void WaterManager::returnResource(double amount){
    waterCap += amount;
}

void WaterManager::incCapacityPerc(double perc) {
    waterCap += std::ceil(initialWaterCap * (perc / 100));
    std::cout << "Water capacity has increased by " << perc << "% to " << waterCap << std::endl;
}

void WaterManager::EmergencyRefill(){
    std::cout << "************************************************\n";
    std::cout << "                  CRITICAL NOTICE\n";
    std::cout << "************************************************\n";    
    std::cout << "Water reservoirs have been depleted.\n";
    std::cout << "Opening up damn walls with accumulated rain water over the year.\n";
    std::cout<< "This is a final warning!!! Without water your city cannot be maintained.\n";
    waterCap+=15000;
    std::cout << "Water capacity after refill: " << waterCap << std::endl;
}

void WaterManager::enterDraught(){
    std::cout << "************************************************\n";
    std::cout << "                  CRITICAL NOTICE\n";
    std::cout << "************************************************\n";
    std::cout << "      A WORLDWIDE WATER CRISIS HAS ERUPTED!\n";
    std::cout << "       DRAUGHT IS UPON US! Satisfaction Rates are PLUMMETING!\n";
    std::cout << "       CROPS WITHERING, BARREN FIELDS EVERYWHERE!\n";
    std::cout << "       PEOPLE SLOWLY FADING AWAY IN DESPAIR.\n";
    std::cout << "     ABSOLUTELY NOTHING CAN BE DONE. FAREWELL.\n";
    std::cout << "************************************************\n";
    exit(0); // program must end here
}

/*************************************
PowerManager
**************************************/
double PowerManager::powerCap = 25000;
double PowerManager::initialPowerCap = 25000;
bool PowerManager::isInitialized = false;
bool PowerManager::reserve = true; // initialize static variable


PowerManager::PowerManager() {
    if (!isInitialized) {
        std::cout << "Setting initial Power Capacity to: " << initialPowerCap << std::endl;
        isInitialized = true;
    }
}


PowerManager::~PowerManager(){
    // delete invoker;
};

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

    std::cout << "Remaining Power: " << powerCap << std::endl;

    if (powerCap < 6000) {
        std::cout << "WARNING! Running low on Power!Switching to Nuclear power soon!\n";
        notifyObservers("Power",powerCap);
    }

    // trigger the command
    if (powerCap == 0) {
        if (reserve) {
            // invoker->update("switchToNuclear");
            switchToNuclear();
            reserve=false;
        } else {
            // invoker->update("endWorld");
            endWorld();
        }
    }

}

void PowerManager::returnResource(double amount){
    powerCap += amount;
}

void PowerManager::incCapacityPerc(double perc) {
    powerCap += std::ceil(initialPowerCap * (perc / 100));
    std::cout << "Power capacity has increased by " << perc << "% to " << powerCap << std::endl;
}

void PowerManager::switchToNuclear(){
    std::cout << "************************************************\n";
    std::cout << "                  CRITICAL NOTICE\n";
    std::cout << "************************************************\n";    
    std::cout << "Your city has run out of electricty!\n";
    std::cout << "Switching to nuclear power.\n";
    std::cout << "Note: Not being careful will be the downfall of your city.\n";
    powerCap += 17000;
    std::cout << "Nuclear power capacity: " << powerCap << std::endl;
}

void PowerManager::endWorld(){
    std::cout << "************************************************\n";
    std::cout << "                  CRITICAL NOTICE\n";
    std::cout << "************************************************\n";
    std::cout << "      NUCLEAR CATASTROPHE IMMINENT!\n";
    std::cout << "                  3...\n";
    std::cout << "                     2...\n";
    std::cout << "                        1...\n";
    std::cout << "\n\n\n\n\n\n\n\n...\n";
    std::cout << "                BOOOOOMMMMMM!!!\n";
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "THE END OF EVERYTHING AS WE KNOW IT.\n";
    std::cout << "************************************************\n";
    exit(0); // program must lend here.
}

