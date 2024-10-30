#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "ResourceManager.h"

class ResidentialBuilding{
    protected:
        double steel;
        double wood;
        double concrete;
        // ResourceManager* rm;
    public:
        ResidentialBuilding();
        virtual ~ResidentialBuilding();
};

class House:public ResidentialBuilding{
    House();
    ~House();
};

class Flat:public ResidentialBuilding{
    Flat();
    ~Flat();
};

class TownHouse:public ResidentialBuilding{
    TownHouse();
    ~TownHouse();
};

class Estate:public ResidentialBuilding{
    Estate();
    ~Estate();
};

#endif