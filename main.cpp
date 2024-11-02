// #include <iostream>
// #include "ResourceManager.h"
// #include "ResourceObserver.h"

// int main() {
//     // Create resource managers using pointers
//     WoodManager* woodManager = new WoodManager();
//     SteelManager* steelManager = new SteelManager();
//     ConcreteManager* concreteManager = new ConcreteManager();
//     WaterManager* waterManager = new WaterManager();
//     PowerManager* powerManager = new PowerManager();

//     // Create an observer
//     LowResourceAlert* lowResourceAlert = new LowResourceAlert();

//     // Attach observer to each resource manager
//     woodManager->attach(lowResourceAlert);
//     steelManager->attach(lowResourceAlert);
//     concreteManager->attach(lowResourceAlert);
//     waterManager->attach(lowResourceAlert);
//     // powerManager->attach(lowResourceAlert);

//     // Test resource consumption to trigger warnings
//     std::cout << "\nUsing wood resources...\n";
//     woodManager->useResource(8000);  // Should be above warning level
//     woodManager->useResource(2500);  // Should trigger warning for low wood

//     std::cout << "\nUsing steel resources...\n";
//     steelManager->useResource(6000); // Should be above warning level
//     steelManager->useResource(3000); // Should trigger warning for low steel

//     std::cout << "\nUsing concrete resources...\n";
//     concreteManager->useResource(9000); // Should be above warning level
//     concreteManager->useResource(3500); // Should trigger warning for low concrete

//     std::cout << "\nUsing water resources...\n";
//     waterManager->useResource(18000); // Should be above warning level
//     waterManager->useResource(10000); // Should trigger emergency refill or drought

//     std::cout << "\nUsing power resources...\n";
//     powerManager->useResource(20000); // Should be above warning level
//     powerManager->useResource(10000); // Should trigger nuclear switch or end world



//     delete woodManager;
//     delete concreteManager;
//     delete steelManager;
//     delete waterManager;
//     delete powerManager;
//     delete lowResourceAlert;



//     return 0;
// }


// #include "ResourceManager.h"
// #include <cassert>
// #include <memory>

// // Helper function to test resource usage
// void testResourceUsage(const std::string& resourceName, ResourceManager* manager, double initialAmount) {
//     std::cout << "\n=== Testing " << resourceName << " Manager ===\n";
    
//     // Create and attach observer
//     auto* observer = new LowResourceAlert();
//     manager->attach(observer);
    
//     // Test initial capacity
//     assert(manager->getResource() == initialAmount);
//     std::cout << "Initial " << resourceName << " capacity test passed\n";
    
//     // Test normal resource usage
//     double smallAmount = initialAmount * 0.1;  // 10% of initial
//     manager->useResource(smallAmount);
//     assert(manager->getResource() == (initialAmount - smallAmount));
//     std::cout << "Normal resource usage test passed\n";
    
//     // Test capacity increase
//     double increasePercentage = 20.0;
//     manager->incCapacityPerc(increasePercentage);
//     std::cout << "Capacity increase test completed\n";
    
//     // Test resource warning threshold
//     double warningThresholdTest = manager->getResource() * 0.7;
//     manager->useResource(warningThresholdTest);
//     std::cout << "Warning threshold test completed\n";
    
//     // Clean up
//     manager->detach(observer);
//     delete observer;
// }

// // Helper function to test resource depletion
// void testResourceDepletion(const std::string& resourceName, ResourceManager* manager) {
//     std::cout << "\n=== Testing " << resourceName << " Depletion ===\n";
    
//     auto* observer = new LowResourceAlert();
//     manager->attach(observer);
    
//     // Use all remaining resources
//     double currentAmount = manager->getResource();
//     manager->useResource(currentAmount + 1000);  // Try to use more than available
    
//     assert(manager->getResource() == 0);
//     std::cout << "Resource depletion test completed\n";
    
//     manager->detach(observer);
//     delete observer;
// }

// int main() {
//     std::cout << "Starting Resource Management System Tests\n";
//     std::cout << "========================================\n\n";

//     // Initialize all resource managers
//     WoodManager woodManager;
//     SteelManager steelManager;
//     ConcreteManager concreteManager;
//     WaterManager waterManager;
//     PowerManager powerManager;

//     // Test Wood Manager
//     testResourceUsage("Wood", &woodManager, 10000);
    
//     // Test Steel Manager
//     testResourceUsage("Steel", &steelManager, 8000);
    
//     // Test Concrete Manager
//     testResourceUsage("Concrete", &concreteManager, 12000);
    
//     // Special test for Water Manager (with emergency refill)
//     std::cout << "\n=== Special Testing Water Manager ===\n";
//     testResourceUsage("Water", &waterManager, 20000);
//     // Test emergency refill
//     double currentWater = waterManager.getResource();
//     waterManager.useResource(currentWater);  // Deplete water to trigger emergency refill
    
//     // Special test for Power Manager (with nuclear switch)
//     std::cout << "\n=== Special Testing Power Manager ===\n";
//     testResourceUsage("Power", &powerManager, 25000);
//     // Test nuclear switch
//     double currentPower = powerManager.getResource();
//     powerManager.useResource(currentPower);  // Deplete power to trigger nuclear switch

//     // Test multiple observers
//     std::cout << "\n=== Testing Multiple Observers ===\n";
//     auto* observer1 = new LowResourceAlert();
//     auto* observer2 = new LowResourceAlert();
//     auto* observer3 = new LowResourceAlert();
    
//     concreteManager.attach(observer1);
//     concreteManager.attach(observer2);
//     concreteManager.attach(observer3);
    
//     // Trigger notifications
//     concreteManager.useResource(9000);  // Should trigger low resource warning
    
//     // Clean up observers
//     concreteManager.detach(observer1);
//     concreteManager.detach(observer2);
//     concreteManager.detach(observer3);
//     delete observer1;
//     delete observer2;
//     delete observer3;

//     // Test catastrophic scenarios (commented out to prevent program termination)
//     std::cout << "\n=== Testing Catastrophic Scenarios ===\n";
//     std::cout << "Note: Catastrophic tests are commented out as they would terminate the program\n";
    
//     // Uncomment these to test end-game scenarios (will terminate program)
    
//     // Test water drought
//     // WaterManager catastrophicWater;
//     // catastrophicWater.useResource(20000);  // Will trigger drought and end program
    
    
    
//    powerManager.useResource(200000);
    

//     std::cout << "\n========================================\n";
//     std::cout << "All tests completed successfully!\n";
    
//     return 0;
// }



// #include "BuildingFactory.h"
// #include "ResourceManager.h"
// #include "IndustrialBuilding.h"
// #include "CommercialBuilding.h"
// #include "BuildingStatistics.h"


// int main(){
//     // Do not ever use these in the main implementation OFFLIMIT just make sure you put these here before you start doing anythign
//     std::cout << "********************************************\n";
//     ResourceManager* rm = new WoodManager();
//     ResourceManager* rm1 = new SteelManager();
//     ResourceManager* rm2 = new ConcreteManager();
//     ResourceManager* rm3 = new PowerManager();
//     ResourceManager* rm4 = new WaterManager();
//     std::cout << "********************************************\n\n";

//     //===============================================================
    
//     //different types of factories
//     ResidentialFactory factory;
//     IndustrialFactory factory2;
//     LandmarkFactory factory3;
//     CommercialFactory factory4;

//     //creating buildings
//     ResidentialBuilding* house = factory.BuildResidential("house");
//     ResidentialBuilding* flat = factory.BuildResidential("house");
//     IndustrialBuilding* powerPlant = factory2.BuildIndustrial("factory");
//     IndustrialBuilding* dam = factory2.BuildIndustrial("dam");
//     IndustrialBuilding* dam2 = factory2.BuildIndustrial("powerplant");
//     LandmarkBuilding* park = factory3.BuildLandmark("Park");
//     CommercialBuilding* shop = factory4.BuildCommercial("Shop");
//     CommercialBuilding* mall = factory4.BuildCommercial("mall");


//     // When removing building
//     shop->removeBuilding();
//     park->removeBuilding();
//     flat->removeBuilding();
//     house->removeBuilding();

//     // moving to the next year
//     BuildingStatistics stats;
//     BuildingStatistics::YearResourceIncrease();

//     // Do not touch these deletes:
//     delete rm;
//     delete rm1;
//     delete rm2;
//     delete rm3;
//     delete rm4;
//     //*************************/

//     // these deletes are for all the buildings that were created
//     delete house; 
//     delete flat;
//     delete powerPlant;
//     delete dam;
//     delete dam2;
//     delete park;
//     delete shop;
//     delete mall;
//     return 0;
// }


#include "BuildingFactory.h"
#include "ResourceManager.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include "BuildingStatistics.h"

#include <iostream>
#include <memory>
#include <vector>

// Function to show the main menu
void showMainMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "       Building Management System        \n";
    std::cout << "=========================================\n";
    std::cout << "1. Build Industrial Building\n";
    std::cout << "2. Build Commercial Building\n";
    std::cout << "3. Build Residential Building\n";
    std::cout << "4. Build Landmark Building\n";
    std::cout << "5. Remove a Building\n";
    std::cout << "6. Progress Year (Increase Resources)\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to display specific building options
void showBuildingOptions(const std::string& buildingType) {
    if (buildingType == "Industrial") {
        std::cout << "Choose an Industrial Building:\n";
        std::cout << "1. Factory\n";
        std::cout << "2. Warehouse\n";
        std::cout << "3. PowerPlant\n";
        std::cout << "4. Dam\n";
    } else if (buildingType == "Commercial") {
        std::cout << "Choose a Commercial Building:\n";
        std::cout << "1. Shop\n";
        std::cout << "2. Mall\n";
        std::cout << "3. Office\n";
    } else if (buildingType == "Residential") {
        std::cout << "Choose a Residential Building:\n";
        std::cout << "1. House\n";
        std::cout << "2. Flat\n";
        std::cout << "3. Townhouse\n";
        std::cout << "4. Estate\n";
    } else if (buildingType == "Landmark") {
        std::cout << "Choose a Landmark Building:\n";
        std::cout << "1. Park\n";
        std::cout << "2. Monument\n";
        std::cout << "3. Cultural\n";
    }
    std::cout << "Enter your choice: ";
}

int main() {
    // Initial setup (as specified)
    std::cout << "********************************************\n";
    ResourceManager* rm = new WoodManager();
    ResourceManager* rm1 = new SteelManager();
    ResourceManager* rm2 = new ConcreteManager();
    ResourceManager* rm3 = new PowerManager();
    ResourceManager* rm4 = new WaterManager();
    std::cout << "********************************************\n\n";

    // Factories for creating buildings
    ResidentialFactory residentialFactory;
    IndustrialFactory industrialFactory;
    LandmarkFactory landmarkFactory;
    CommercialFactory commercialFactory;

    // Storage for created buildings
    std::vector<std::unique_ptr<ResidentialBuilding>> residentialBuildings;
    std::vector<std::unique_ptr<IndustrialBuilding>> industrialBuildings;
    std::vector<std::unique_ptr<LandmarkBuilding>> landmarkBuildings;
    std::vector<std::unique_ptr<CommercialBuilding>> commercialBuildings;

    bool running = true;
    while (running) {
        showMainMenu();
        int mainChoice;
        std::cin >> mainChoice;

        switch (mainChoice) {
            case 1: { // Build Industrial Building
                showBuildingOptions("Industrial");
                int industrialChoice;
                std::cin >> industrialChoice;
                switch (industrialChoice) {
                    case 1: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("factory"))); break;
                    case 2: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("warehouse"))); break;
                    case 3: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("plant"))); break;
                    case 4: industrialBuildings.push_back(std::unique_ptr<IndustrialBuilding>(industrialFactory.BuildIndustrial("dam"))); break;
                    default: std::cout << "Invalid choice!\n"; break;
                }
                break;
            }
            case 2: { // Build Commercial Building
                showBuildingOptions("Commercial");
                int commercialChoice;
                std::cin >> commercialChoice;
                switch (commercialChoice) {
                    case 1: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("shop"))); break;
                    case 2: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("mall"))); break;
                    case 3: commercialBuildings.push_back(std::unique_ptr<CommercialBuilding>(commercialFactory.BuildCommercial("office"))); break;
                    default: std::cout << "Invalid choice!\n"; break;
                }
                break;
            }
            case 3: { // Build Residential Building
                showBuildingOptions("Residential");
                int residentialChoice;
                std::cin >> residentialChoice;
                switch (residentialChoice) {
                    case 1: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("house"))); break;
                    case 2: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("flat"))); break;
                    case 3: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("townhouse"))); break;
                    case 4: residentialBuildings.push_back(std::unique_ptr<ResidentialBuilding>(residentialFactory.BuildResidential("estate"))); break;
                    default: std::cout << "Invalid choice!\n"; break;
                }
                break;
            }
            case 4: { // Build Landmark Building
                showBuildingOptions("Landmark");
                int landmarkChoice;
                std::cin >> landmarkChoice;
                switch (landmarkChoice) {
                    case 1: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Park"))); break;
                    case 2: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Monument"))); break;
                    case 3: landmarkBuildings.push_back(std::unique_ptr<LandmarkBuilding>(landmarkFactory.BuildLandmark("Cultural"))); break;
                    default: std::cout << "Invalid choice!\n"; break;
                }
                break;
            }
            case 5: { // Remove Building
                std::cout << "Choose a type of building to remove:\n";
                std::cout << "1. Residential\n";
                std::cout << "2. Industrial\n";
                std::cout << "3. Landmark\n";
                std::cout << "4. Commercial\n";
                int buildingType;
                std::cin >> buildingType;
                
                if (buildingType == 1 && !residentialBuildings.empty()) {
                    residentialBuildings.back()->removeBuilding();
                    residentialBuildings.pop_back();
                } else if (buildingType == 2 && !industrialBuildings.empty()) {
                    industrialBuildings.back()->removeBuilding();
                    industrialBuildings.pop_back();
                } else if (buildingType == 3 && !landmarkBuildings.empty()) {
                    landmarkBuildings.back()->removeBuilding();
                    landmarkBuildings.pop_back();
                } else if (buildingType == 4 && !commercialBuildings.empty()) {
                    commercialBuildings.back()->removeBuilding();
                    commercialBuildings.pop_back();
                } else {
                    std::cout << "No building of the selected type to remove!\n";
                }
                break;
            }
            case 6: { // Progress Year
                BuildingStatistics::YearResourceIncrease();
                break;
            }
            case 7: { // Exit
                running = false;
                break;
            }
            default: {
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    }

    // Cleanup resources
    delete rm;
    delete rm1;
    delete rm2;
    delete rm3;
    delete rm4;

    std::cout << "Exiting program. All resources and buildings have been cleaned up.\n";
    return 0;
}
