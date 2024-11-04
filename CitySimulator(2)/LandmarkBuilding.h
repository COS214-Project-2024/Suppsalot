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
        void returnResources();
    public:
        LandmarkBuilding();
        virtual ~LandmarkBuilding() = default;
        virtual void removeBuilding() = 0;
};

class Park:public LandmarkBuilding{
    public:
        Park();
        ~Park() override = default;
        void removeBuilding() override;
};

class Monument:public LandmarkBuilding{
    public:
        Monument();
        ~Monument() override = default;
        void removeBuilding() override;
};

class Cultural:public LandmarkBuilding{
    public:     
        Cultural();
        ~Cultural() override = default;
        void removeBuilding() override;
};



#endif