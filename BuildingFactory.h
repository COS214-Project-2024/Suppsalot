#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "IndustrialBuilding.h";
#include "ResidentialBuilding.h";
#include "CommercialBuilding.h";
#include "LandmarkBuilding.h";



class BuildingFactory{
    public:
        BuildingFactory();
        virtual ~BuildingFactory();
        virtual ResidentialBuilding* BuildResidential() = 0;
        virtual CommercialBuilding* BuildCommercial() = 0;
        virtual IndustrialBuilding* BuildIndustrial() = 0;
        virtual LandmarkBuilding* BuildLandmark() = 0;
};

class LandmarkFactory:public BuildingFactory{
    public:
        LandmarkFactory();
        ~LandmarkFactory();
        ResidentialBuilding* BuildResidential();
        CommercialBuilding* BuildCommercial();
        IndustrialBuilding* BuildIndustrial();
        LandmarkBuilding* BuildLandmark();
};

class ResidentialFactory:public BuildingFactory{
    public:
        ResidentialFactory();
        ~ResidentialFactory();
        ResidentialBuilding* BuildResidential();
        CommercialBuilding* BuildCommercial();
        IndustrialBuilding* BuildIndustrial();
        LandmarkBuilding* BuildLandmark();
};

class CommercialFactory:public BuildingFactory{
    public:
        CommercialFactory();
        ~CommercialFactory();
        ResidentialBuilding* BuildResidential();
        CommercialBuilding* BuildCommercial();
        IndustrialBuilding* BuildIndustrial();
        LandmarkBuilding* BuildLandmark();
};

class IndustrialFactory:public BuildingFactory{
    public:
        IndustrialFactory();
        ~IndustrialFactory();
        ResidentialBuilding* BuildResidential();
        CommercialBuilding* BuildCommercial();
        IndustrialBuilding* BuildIndustrial();
        LandmarkBuilding* BuildLandmark();
};

#endif