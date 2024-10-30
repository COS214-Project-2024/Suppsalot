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


#include "ResourceManager.h"
#include <cassert>
#include <memory>

// Helper function to test resource usage
void testResourceUsage(const std::string& resourceName, ResourceManager* manager, double initialAmount) {
    std::cout << "\n=== Testing " << resourceName << " Manager ===\n";
    
    // Create and attach observer
    auto* observer = new LowResourceAlert();
    manager->attach(observer);
    
    // Test initial capacity
    assert(manager->getResource() == initialAmount);
    std::cout << "Initial " << resourceName << " capacity test passed\n";
    
    // Test normal resource usage
    double smallAmount = initialAmount * 0.1;  // 10% of initial
    manager->useResource(smallAmount);
    assert(manager->getResource() == (initialAmount - smallAmount));
    std::cout << "Normal resource usage test passed\n";
    
    // Test capacity increase
    double increasePercentage = 20.0;
    manager->incCapacityPerc(increasePercentage);
    std::cout << "Capacity increase test completed\n";
    
    // Test resource warning threshold
    double warningThresholdTest = manager->getResource() * 0.7;
    manager->useResource(warningThresholdTest);
    std::cout << "Warning threshold test completed\n";
    
    // Clean up
    manager->detach(observer);
    delete observer;
}

// Helper function to test resource depletion
void testResourceDepletion(const std::string& resourceName, ResourceManager* manager) {
    std::cout << "\n=== Testing " << resourceName << " Depletion ===\n";
    
    auto* observer = new LowResourceAlert();
    manager->attach(observer);
    
    // Use all remaining resources
    double currentAmount = manager->getResource();
    manager->useResource(currentAmount + 1000);  // Try to use more than available
    
    assert(manager->getResource() == 0);
    std::cout << "Resource depletion test completed\n";
    
    manager->detach(observer);
    delete observer;
}

int main() {
    std::cout << "Starting Resource Management System Tests\n";
    std::cout << "========================================\n\n";

    // Initialize all resource managers
    WoodManager woodManager;
    SteelManager steelManager;
    ConcreteManager concreteManager;
    WaterManager waterManager;
    PowerManager powerManager;

    // Test Wood Manager
    testResourceUsage("Wood", &woodManager, 10000);
    
    // Test Steel Manager
    testResourceUsage("Steel", &steelManager, 8000);
    
    // Test Concrete Manager
    testResourceUsage("Concrete", &concreteManager, 12000);
    
    // Special test for Water Manager (with emergency refill)
    std::cout << "\n=== Special Testing Water Manager ===\n";
    testResourceUsage("Water", &waterManager, 20000);
    // Test emergency refill
    double currentWater = waterManager.getResource();
    waterManager.useResource(currentWater);  // Deplete water to trigger emergency refill
    
    // Special test for Power Manager (with nuclear switch)
    std::cout << "\n=== Special Testing Power Manager ===\n";
    testResourceUsage("Power", &powerManager, 25000);
    // Test nuclear switch
    double currentPower = powerManager.getResource();
    powerManager.useResource(currentPower);  // Deplete power to trigger nuclear switch

    // Test multiple observers
    std::cout << "\n=== Testing Multiple Observers ===\n";
    auto* observer1 = new LowResourceAlert();
    auto* observer2 = new LowResourceAlert();
    auto* observer3 = new LowResourceAlert();
    
    concreteManager.attach(observer1);
    concreteManager.attach(observer2);
    concreteManager.attach(observer3);
    
    // Trigger notifications
    concreteManager.useResource(9000);  // Should trigger low resource warning
    
    // Clean up observers
    concreteManager.detach(observer1);
    concreteManager.detach(observer2);
    concreteManager.detach(observer3);
    delete observer1;
    delete observer2;
    delete observer3;

    // Test catastrophic scenarios (commented out to prevent program termination)
    std::cout << "\n=== Testing Catastrophic Scenarios ===\n";
    std::cout << "Note: Catastrophic tests are commented out as they would terminate the program\n";
    
    // Uncomment these to test end-game scenarios (will terminate program)
    
    // Test water drought
    // WaterManager catastrophicWater;
    // catastrophicWater.useResource(20000);  // Will trigger drought and end program
    
    
    
   powerManager.useResource(200000);
    

    std::cout << "\n========================================\n";
    std::cout << "All tests completed successfully!\n";
    
    return 0;
}
