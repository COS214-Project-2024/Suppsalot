#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
class IndustrialBuilding{
    protected:
        double steel;
        double wood;
        double concrete;
        // ResourceManager* rm;
    public:
        IndustrialBuilding();
        ~IndustrialBuilding();
};

// for every factory built, it will increase the metalperc capacity in resources by 0.15%  
// This will be done in the constructor 
class Factories:public IndustrialBuilding{
    private:
        double metalPerc;
    public:
        Factories();
        ~Factories();
};

// Same concept will be applied over here.
class WareHouses:public IndustrialBuilding{
    private: 
        double woodPerc;
        double concretePerc;
    public:
        WareHouses();
        ~WareHouses();
};

// in resources (or stats) have number of plants and dams as a static int which increase 
// everytime one of these is createed 
class Plants: public IndustrialBuilding{
    private: 
        double elecCap;
    public:
        Plants();
        ~Plants();
};

class Dams:public IndustrialBuilding{
    private:
        double waterCap;
    public:
        Dams();
        ~Dams();
};

#endif