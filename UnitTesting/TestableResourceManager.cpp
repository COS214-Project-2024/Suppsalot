// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//
// #include "doctest.h"
// #include "ResourceManager.h"
// #include <cmath>
// #include <iostream>
//
// // Test helper class that inherits from ConcreteManager to expose protected members
// class TestableConcreteManager : public ConcreteManager {
// public:
//
//     using ConcreteManager::concreteCap;
//     using ConcreteManager::initialConcreteCap;
// };
//
// // Test helper class that inherits from WaterManager to expose protected members
// class TestableWaterManager : public WaterManager {
// public:
//     using WaterManager::waterCap;
//     using WaterManager::initialWaterCap;
//     using WaterManager::reserve;
// };
//
// // Test helper class that inherits from PowerManager to expose protected members
// class TestablePowerManager : public PowerManager {
// public:
//     using PowerManager::powerCap;
//     using PowerManager::initialPowerCap;
//     using PowerManager::reserve;
// };
//
// TEST_CASE("ResourceManager - Basic Initialization") {
//     TestableConcreteManager concreteManager;
//     TestableWaterManager waterManager;
//     TestablePowerManager powerManager;
//
//     CHECK(concreteManager.concreteCap == 0);
//     CHECK(concreteManager.initialConcreteCap == 0);
//     CHECK(waterManager.waterCap == 20000);
//     CHECK(waterManager.initialWaterCap == 20000);
//     CHECK(powerManager.powerCap == 25000);
//     CHECK(powerManager.initialPowerCap == 25000);
// }
//
// TEST_CASE("ResourceManager - Concrete Management") {
//     TestableConcreteManager manager;
//
//     SUBCASE("Return Concrete Resource") {
//         manager.returnResource(1000);
//         CHECK(manager.concreteCap == 1000);
//     }
//
//     SUBCASE("Increase Concrete Capacity") {
//         manager.initialConcreteCap = 10000;
//         manager.incCapacityPerc(10);
//         CHECK(manager.concreteCap == 11000);
//     }
// }
//
// TEST_CASE("ResourceManager - Water Management") {
//     TestableWaterManager manager;
//
//     SUBCASE("Use Water Resource") {
//         manager.useResource(5000);
//         CHECK(manager.waterCap == 15000);
//     }
//
//     SUBCASE("Return Water Resource") {
//         manager.returnResource(5000);
//         CHECK(manager.waterCap == 25000);
//     }
//
//     SUBCASE("Increase Water Capacity") {
//         manager.incCapacityPerc(10);
//         CHECK(manager.waterCap == 22000);
//     }
//
//     SUBCASE("Emergency Refill") {
//         manager.waterCap = 0;
//         manager.EmergencyRefill();
//         CHECK(manager.waterCap == 15000);
//     }
//
//     SUBCASE("Enter Drought") {
//         manager.waterCap = 0;
//         manager.reserve = false;
//         CHECK_THROWS_AS(manager.enterDraught(), std::runtime_error);
//     }
// }
//
// TEST_CASE("ResourceManager - Power Management") {
//     TestablePowerManager manager;
//
//     SUBCASE("Use Power Resource") {
//         manager.useResource(5000);
//         CHECK(manager.powerCap == 20000);
//     }
//
//     SUBCASE("Return Power Resource") {
//         manager.returnResource(5000);
//         CHECK(manager.powerCap == 30000);
//     }
//
//     SUBCASE("Increase Power Capacity") {
//         manager.incCapacityPerc(10);
//         CHECK(manager.powerCap == 27500);
//     }
//
//     SUBCASE("Switch to Nuclear Power") {
//         manager.powerCap = 0;
//         manager.switchToNuclear();
//         CHECK(manager.powerCap == 17000);
//     }
//
//     SUBCASE("End World") {
//         manager.powerCap = 0;
//         manager.reserve = false;
//         CHECK_THROWS_AS(manager.endWorld(), std::runtime_error);
//     }
// }

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "ResourceManager.h"
#include <cmath>
#include <iostream>

TEST_CASE("ResourceManager - Basic Initialization") {
    ConcreteManager concreteManager;
    WaterManager waterManager;
    PowerManager powerManager;

    CHECK(concreteManager.getConcreteCap() == 0);
    CHECK(concreteManager.getInitialConcreteCap() == 0);
    CHECK(waterManager.getWaterCap() == 20000);
    CHECK(waterManager.getInitialWaterCap() == 20000);
    CHECK(powerManager.getPowerCap() == 25000);
    CHECK(powerManager.getInitialPowerCap() == 25000);
}

TEST_CASE("ResourceManager - Concrete Management") {
    ConcreteManager manager;

    SUBCASE("Return Concrete Resource") {
        manager.returnResource(1000);
        CHECK(manager.getConcreteCap() == 1000);
    }

    SUBCASE("Increase Concrete Capacity") {
        manager.incCapacityPerc(10);
        CHECK(manager.getConcreteCap() == 11000);
    }
}

TEST_CASE("ResourceManager - Water Management") {
    WaterManager manager;

    SUBCASE("Use Water Resource") {
        manager.useResource(5000);
        CHECK(manager.getWaterCap() == 15000);
    }

    SUBCASE("Return Water Resource") {
        manager.returnResource(5000);
        CHECK(manager.getWaterCap() == 25000);
    }

    SUBCASE("Increase Water Capacity") {
        manager.incCapacityPerc(10);
        CHECK(manager.getWaterCap() == 22000);
    }

    SUBCASE("Emergency Refill") {
        manager.EmergencyRefill();
        CHECK(manager.getWaterCap() == 15000);
    }

    SUBCASE("Enter Drought") {
        manager.setReserve(false);
        CHECK_THROWS_AS(manager.enterDraught(), std::runtime_error);
    }
}

TEST_CASE("ResourceManager - Power Management") {
    PowerManager manager;

    SUBCASE("Use Power Resource") {
        manager.useResource(5000);
        CHECK(manager.getPowerCap() == 20000);
    }

    SUBCASE("Return Power Resource") {
        manager.returnResource(5000);
        CHECK(manager.getPowerCap() == 30000);
    }

    SUBCASE("Increase Power Capacity") {
        manager.incCapacityPerc(10);
        CHECK(manager.getPowerCap() == 27500);
    }

    SUBCASE("Switch to Nuclear Power") {
        manager.switchToNuclear();
        CHECK(manager.getPowerCap() == 17000);
    }

    SUBCASE("End World") {
        manager.setReserve(false);
        CHECK_THROWS_AS(manager.endWorld(), std::runtime_error);
    }
}