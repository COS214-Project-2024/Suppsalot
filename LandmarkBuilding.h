#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H
class LandmarkBuilding{
    protected:
        double steel;
        double wood;
        double concrete;
        // ResourceManager* rm;
        // BuildingStatistics* satisfaction; // will use this object to call a function that is stored in building stats.
    public:
        LandmarkBuilding();
        ~LandmarkBuilding();
};

class Park:public LandmarkBuilding{
    Park();
    ~Park();
};

class Monument:public LandmarkBuilding{
    Monument();
    ~Monument();
};

class Cultural:public LandmarkBuilding{
    Cultural();
    ~Cultural();
};



#endif