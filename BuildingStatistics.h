#ifndef BUILDINGSTATISTICS_H
#define BUILDINGSTATISTICS_H

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


        static int SatisfactionIncrease() {
            return static_cast<int>(LandmarkCounter * 0.16);
        }





};






#endif