#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"
#include "LandmarkBuilding.h"


#include <string>



class BuildingFactory{
    public:
        BuildingFactory();
        virtual ~BuildingFactory();
        virtual ResidentialBuilding* BuildResidential(std::string r) = 0;
        virtual CommercialBuilding* BuildCommercial(std::string b) = 0;
        virtual IndustrialBuilding* BuildIndustrial(std::string i) = 0;
        virtual LandmarkBuilding* BuildLandmark(std::string l) = 0;
};

class LandmarkFactory:public BuildingFactory{
    public:
        LandmarkFactory();
        ~LandmarkFactory() override = default;
        ResidentialBuilding* BuildResidential(std::string r);
        CommercialBuilding* BuildCommercial(std::string c);
        IndustrialBuilding* BuildIndustrial(std::string i);
        LandmarkBuilding* BuildLandmark(std::string l);
};

class ResidentialFactory:public BuildingFactory{
    public:
        ResidentialFactory();
        ~ResidentialFactory() override = default;
        ResidentialBuilding* BuildResidential(std::string r);
        CommercialBuilding* BuildCommercial(std::string b);
        IndustrialBuilding* BuildIndustrial(std::string i);
        LandmarkBuilding* BuildLandmark(std::string l);
};

class CommercialFactory:public BuildingFactory{
    public:
        CommercialFactory();
        ~CommercialFactory() override = default;
        ResidentialBuilding* BuildResidential(std::string r);
        CommercialBuilding* BuildCommercial(std::string b);
        IndustrialBuilding* BuildIndustrial(std::string i);
        LandmarkBuilding* BuildLandmark(std::string l);
};

class IndustrialFactory:public BuildingFactory{
    public:
        IndustrialFactory();
        ~IndustrialFactory() override = default;
        ResidentialBuilding* BuildResidential(std::string r);
        CommercialBuilding* BuildCommercial(std::string l);
        IndustrialBuilding* BuildIndustrial(std::string i);
        LandmarkBuilding* BuildLandmark(std::string l);
};

#endif