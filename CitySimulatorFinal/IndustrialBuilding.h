#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "ResourceManager.h"
// changed the following to a struct 
class IndustrialBuilding{
    protected:
        struct Resources {
                double steel;
                double wood;
                double concrete;
            };
            
        Resources resources;
        void allocateResources();
        void returnResources();
    public:
        IndustrialBuilding();
        virtual ~IndustrialBuilding() = default;
        virtual void removeBuilding() = 0;

};

// for every factory built, it will increase the metalperc capacity in resources by 0.15%  
// This will be done in the constructor 
class Factories:public IndustrialBuilding{
    private:
        double metalPerc;
    public:
        Factories();
        ~Factories() override = default;
        void removeBuilding() override;
};

// Same concept will be applied over here.
class WareHouses:public IndustrialBuilding{
    private: 
        double woodPerc;
        double concretePerc;
    public:
        WareHouses();
        ~WareHouses() override = default;
        void removeBuilding() override;
};

// in resources (or stats) have number of plants and dams as a static int which increase 
// everytime one of these is createed 
class Plants: public IndustrialBuilding{
    private: 
        double elecCap;
    public:
        Plants();
        ~Plants() override = default;
        void removeBuilding() override;

};

class Dams:public IndustrialBuilding{
    private:
        double waterCap;
    public:
        Dams();
        ~Dams() override = default;
        void removeBuilding() override;
};

#endif