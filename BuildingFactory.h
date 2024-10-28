#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

class BuildingFactory{
    BuildingFactory();
    ~BuildingFactory();
    ResidentialBuilding* BuildResidential();
    CommercialBuilding* BuildCommercial();
    IndustrialBuilding* BuildIndustrial();
    LandmarkBuilding* BuildLandmark();
};

class LandmarkFactory:public BuildingFactory{
    LandmarkFactory();
    ~LandmarkFactory();
    ResidentialBuilding* BuildResidential();
    CommercialBuilding* BuildCommercial();
    IndustrialBuilding* BuildIndustrial();
    LandmarkBuilding* BuildLandmark();
};

class ResidentialFactory:public BuildingFactory{
    ResidentialFactory();
    ~ResidentialFactory();
    ResidentialBuilding* BuildResidential();
    CommercialBuilding* BuildCommercial();
    IndustrialBuilding* BuildIndustrial();
    LandmarkBuilding* BuildLandmark();
};

class CommercialFactory:public BuildingFactory{
    CommercialFactory();
    ~CommercialFactory();
    ResidentialBuilding* BuildResidential();
    CommercialBuilding* BuildCommercial();
    IndustrialBuilding* BuildIndustrial();
    LandmarkBuilding* BuildLandmark();
};

class IndustrialFactory:public BuildingFactory{
    CommercialFactory();
    ~CommercialFactory();
    ResidentialBuilding* BuildResidential();
    CommercialBuilding* BuildCommercial();
    IndustrialBuilding* BuildIndustrial();
    LandmarkBuilding* BuildLandmark();
};

#endif