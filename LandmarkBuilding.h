#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H


class LandmarkBuilding{
    protected:
        struct Resources {
                double steel;
                double wood;
                double concrete;
            };
            
        Resources resources;
        void allocateResources();
    public:
        LandmarkBuilding();
        virtual ~LandmarkBuilding() = default;
};

class Park:public LandmarkBuilding{
    public:
        Park();
        ~Park() override = default;
};

class Monument:public LandmarkBuilding{
    public:
        Monument();
        ~Monument() override = default;
};

class Cultural:public LandmarkBuilding{
    public:     
        Cultural();
        ~Cultural() override = default;
};



#endif