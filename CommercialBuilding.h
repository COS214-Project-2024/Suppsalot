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
        void returnResources();
    public:
        CommercialBuilding();
        virtual ~CommercialBuilding() = default;
        virtual void removeBuilding() = 0;
};

class Shop:public CommercialBuilding{
    public:
        Shop();
        ~Shop() override = default;
        void removeBuilding() override;
};

class Mall:public CommercialBuilding{
    public:
        Mall();
        ~Mall() override = default;
        void removeBuilding() override;
};

class Office:public CommercialBuilding{
    public:
        Office();
        ~Office() override = default;
        void removeBuilding() override;
};

#endif