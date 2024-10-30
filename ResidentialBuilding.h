// #ifndef RESIDENTIALBUILDING_H
// #define RESIDENTIALBUILDING_H

// #include "ResourceManager.h"

// class ResidentialBuilding{
//     protected:
//         double steel;
//         double wood;
//         double concrete;
//         ResourceManager* rm;
//     public:
//         ResidentialBuilding();
//         virtual ~ResidentialBuilding();
// };

// class House:public ResidentialBuilding{
//     House();
//     ~House();
// };

// class Flat:public ResidentialBuilding{
//     Flat();
//     ~Flat();
// };

// class TownHouse:public ResidentialBuilding{
//     TownHouse();
//     ~TownHouse();
// };

// class Estate:public ResidentialBuilding{
//     Estate();
//     ~Estate();
// };

// #endif



#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include <memory>
#include "ResourceManager.h"

class ResidentialBuilding {
protected:
    struct Resources {
        double steel;
        double wood;
        double concrete;
    };
    
    Resources resources;
    void allocateResources();

public:
    ResidentialBuilding();
    virtual ~ResidentialBuilding() = default;
};

class House : public ResidentialBuilding {
public:
    House();
    ~House() override = default;
};

class Flat : public ResidentialBuilding {
public:
    Flat();
    ~Flat() override = default;
};

class TownHouse : public ResidentialBuilding {
public:
    TownHouse();
    ~TownHouse() override = default;
};

class Estate : public ResidentialBuilding {
public:
    Estate();
    ~Estate() override = default;
};

#endif
