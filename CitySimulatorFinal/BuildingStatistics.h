#ifndef BUILDINGSTATISTICS_H
#define BUILDINGSTATISTICS_H

#include  <cmath>
#include <iostream>
#include <memory>

#include "ResourceManager.h"

class BuildingStatistics{
    public:
        //counters for landmark (just going to have 1 for all the landmarks)
        static int LandmarkCounter;
        //counters for commercial
        static int ShopCounter;
        static int MallCounter;
        static int OfficeCounter;
        // counters for Residential
        static int HouseCounter;
        static int FlatCounter;
        static int TownhouseCounter;
        static int EstateCounter;
        // a counter for Industrial
        static int FactoryCounter;
        static int WarehouseCounter;
        static int PlantCounter;
        static int DamCounter;

        static int getLandmarkCounter() { return LandmarkCounter; }
        static int getShopCounter() { return ShopCounter; }
        static int getMallCounter() { return MallCounter; }
        static int getOfficeCounter() { return OfficeCounter; }
        static int getHouseCounter() { return HouseCounter; }
        static int getFlatCounter() { return FlatCounter; }
        static int getTownhouseCounter() { return TownhouseCounter; }
        static int getEstateCounter() { return EstateCounter; }
        static int getFactoryCounter() { return FactoryCounter; }
        static int getWarehouseCounter() { return WarehouseCounter; }
        static int getPlantCounter() { return PlantCounter; }
        static int getDamCounter() { return DamCounter; }


        static int YearSatisfactionIncrease() {
            // increases satisfaction level percentage
            return static_cast<int>(LandmarkCounter * 12 + sqrt(LandmarkCounter) * 3);
        }

        static int YearIncomeIncrease(){
            // increases city budget
            int sum = static_cast<int>(
            ShopCounter * (40 + log(ShopCounter + 1) * 10) + 
            MallCounter * (180 + sqrt(MallCounter) * 20) + 
            OfficeCounter * (220 + log(OfficeCounter + 1) * 15));
            return sum;
        }

        static int YearCapacityIncrease(){
            // incerases number of citizens in city
            int sum = static_cast<int>(
            HouseCounter * (1 + log(HouseCounter + 1) * 1) + 
            FlatCounter * (25 + sqrt(FlatCounter) * 5) + 
            TownhouseCounter * (3 + log(TownhouseCounter + 1) * 2) + 
            EstateCounter * (90 + sqrt(EstateCounter) * 10));
            return sum;
        }

        // static void YearResourceIncrease(){
        //     std::cout << "\n\n***************************************\nTallying up resources accumulated over the year!\n***************************************\n";
        //     std::unique_ptr<ResourceManager> woodManager(new WoodManager());
        //     woodManager->incCapacityPerc(WarehouseCounter * 2 + log(WarehouseCounter + 1) * 5); 
        //     std::unique_ptr<ResourceManager> steelManager(new SteelManager());
        //     steelManager->incCapacityPerc(FactoryCounter * 3 + sqrt(FactoryCounter) * 5);
        //     std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
        //     concreteManager->incCapacityPerc(WarehouseCounter * 3 + log(WarehouseCounter + 1) * 4);
        //     std::unique_ptr<ResourceManager> waterManager(new WaterManager());
        //     waterManager->incCapacityPerc(DamCounter * 8 + sqrt(DamCounter) * 7);
        //     std::unique_ptr<ResourceManager> powerManager(new PowerManager());
        //     powerManager->incCapacityPerc(PlantCounter * 10 + log(PlantCounter + 1) * 8);

        //     // while some resources increase, buildings will also use up electricity and water

        // }
    static void YearResourceIncrease() {
        std::cout << "\n\n***************************************\n";
        std::cout << "Tallying up resources accumulated over the year!\n";
        std::cout << "***************************************\n";

        std::unique_ptr<ResourceManager> woodManager(new WoodManager());
        woodManager->incCapacityPerc(WarehouseCounter * 2 + log(WarehouseCounter + 1) * 5);

        std::unique_ptr<ResourceManager> steelManager(new SteelManager());
        steelManager->incCapacityPerc(FactoryCounter * 3 + sqrt(FactoryCounter) * 5);

        std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
        concreteManager->incCapacityPerc(WarehouseCounter * 3 + log(WarehouseCounter + 1) * 4);

        std::unique_ptr<ResourceManager> waterManager(new WaterManager());
        waterManager->incCapacityPerc(DamCounter * 8 + sqrt(DamCounter) * 7);

        std::unique_ptr<ResourceManager> powerManager(new PowerManager());
        powerManager->incCapacityPerc(PlantCounter * 10 + log(PlantCounter + 1) * 8);

        // while some resources increase, buildings will also use up electricity and water
        double powerConsumption = static_cast<int>(
            ((HouseCounter * 30.5 + FlatCounter * 32.0 + TownhouseCounter * 4.5 + EstateCounter * 5.5) +
            (ShopCounter * 70.5 + MallCounter * 120.0 + OfficeCounter * 8.5) +
            (LandmarkCounter * 60.0))*12
        );
        powerManager->useResource(powerConsumption);

        double waterConsumption = static_cast<int>(
            ((HouseCounter * 40.0 + FlatCounter * 30.8 + TownhouseCounter * 5.0 + EstateCounter * 16.0) +
            (FactoryCounter * 18.0 + PlantCounter * 7.5) +
            (LandmarkCounter * 5.0))*12
        );
        waterManager->useResource(waterConsumption);

        std::cout << "Power consumption for the year: " << powerConsumption << " units.\n";
        std::cout << "Water consumption for the year: " << waterConsumption << " units.\n";
    }

    static void YearCitizenConsumer(int n){
        std::cout << "*****************************************\nAfter a year, consumers have used up the following:\n*****************************************\n";
        std::unique_ptr<ResourceManager> waterManager(new WaterManager());
        std::unique_ptr<ResourceManager> powerManager(new PowerManager());
        
        double waterConsumption = static_cast<int>(n * (5.0 + log(n + 1) * 1.5));
        double powerConsumption = static_cast<int>(n * (4.0 + sqrt(n) * 1.2));

        waterManager->useResource(waterConsumption);
        powerManager->useResource(powerConsumption);

        std::cout << "Water consumption for the citizens: " << waterConsumption << " units.\n";
        std::cout << "Power consumption for the citizens: " << powerConsumption << " units.\n";
    }

    static void useRoadResource(std::string type){
        if (type == "Road"){
            std::unique_ptr<ResourceManager> concreteManager(new ConcreteManager());
            std::cout << "Concrete used for the road: 400\n";
            concreteManager->useResource(400);
            
        }else if (type=="Train"){
            std::unique_ptr<ResourceManager> steelManager(new SteelManager());
            std::unique_ptr<ResourceManager> woodManager(new WoodManager());
            std::cout << "Steel used for the trainTrack: 300\n";
            std::cout << "Wood used for the trainTrack: 300\n";
            steelManager->useResource(300);
            woodManager->useResource(300);
        }else{
            std::cout << "Invalid\n";
        }
    }

};

#endif