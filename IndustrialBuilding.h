#ifndef INDUSTRIALBUILDING
#define INDUSTRIALBUILDING
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

#endif