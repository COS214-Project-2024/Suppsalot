#ifndef BUILDINGSTATISTICS_H
#define BUILDINGSTATISTICS_H

#include  <cmath>
#include <memory>

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

        static void YearResourceIncrease(){
            std::cout << "\n\n***************************************\nTallying up resources accumulated over the year!\n***************************************\n";
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
        }

};

#endif