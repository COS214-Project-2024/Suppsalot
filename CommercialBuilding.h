#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
class CommercialBuilding{
    protected:
        double steel;
        double wood;
        double concrete;
        // ResourceManager* rm;
        // BuildingStatics* stats;
    public:
        CommercialBuilding();
        ~CommercialBuilding();
};

class Shop:public CommercialBuilding{
    Shop();
    ~Shop();
};

class Mall:public CommercialBuilding{
    Mall();
    ~Mall();
};

class Office:public CommercialBuilding{
    Office();
    ~Office();
};

#endif