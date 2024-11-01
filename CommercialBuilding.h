#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

class CommercialBuilding{
    protected:
        struct Resources {
                double steel;
                double wood;
                double concrete;
            };
            
        Resources resources;
        void allocateResources();
    public:
        CommercialBuilding();
        virtual ~CommercialBuilding() = default;
};

class Shop:public CommercialBuilding{
    public:
        Shop();
        ~Shop() override = default;
};

class Mall:public CommercialBuilding{
    public:
        Mall();
        ~Mall() override = default;
};

class Office:public CommercialBuilding{
    public:
        Office();
        ~Office() override = default;
};

#endif