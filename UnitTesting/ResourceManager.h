#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

#include "ResourceObserver.h"
// the following class refers to the subject along with 
// its concrete subjects for the observer pattern
class ResourceManager{

  friend class TestableResourceManager;
    private:
        std::vector<ResourceObserver*> observers;
    public:
        void attach(ResourceObserver* observers);
        void detach (ResourceObserver* observers);
        virtual ~ResourceManager();
        virtual void notifyObservers(const std::string& resourceType, double currentLevel);
        
        // Concrete resources should implement their own capacity management
        virtual double getResource() const = 0;
        virtual void useResource(double amount) = 0;
        virtual void returnResource(double amount)= 0;
        virtual void incCapacityPerc(double perc) = 0;
};

class WoodManager:public ResourceManager{
    friend class TestableResourceManager;
    private:
        static double woodCap;
        static double initialWoodCap; 
        static bool isInitialized;

    public:
        WoodManager();
        ~WoodManager();         

        // double getWoodAmount() const;
        // void useWood(double amount);
        // void incWoodPerc(double perc);   
        // rather than doing it like this why not have a pure virtual function up top which is then 
        // implemented differentely for each of the derived classes

        double getResource() const override;
        void useResource(double amount) override;
        void returnResource(double amount) override;
        void incCapacityPerc(double perc) override;
};

class SteelManager:public ResourceManager{
    friend class TestableResourceManager;
    private:
        static double initialSteelCap; // again is this necessary
        static double steelCap;
        static bool isInitialized;

    public:
        SteelManager();
        ~SteelManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void returnResource(double amount) override;
        void incCapacityPerc(double perc) override;
};


class ConcreteManager:public ResourceManager{
    friend class TestableResourceManager;
    private:
        static double initialConcreteCap; // again is this necessary
        static double concreteCap;
        static bool isInitialized;
    public:
        ConcreteManager();
        ~ConcreteManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void returnResource(double amount) override;
        void incCapacityPerc(double perc) override;
        double getConcreteCap() const;
        double getInitialConcreteCap() const;
};

class WaterManager:public ResourceManager{
    friend class TestableResourceManager;
    private:
        static double initialWaterCap;
        static double waterCap;
        static bool isInitialized;
        // CommandInvoker* invoker; // check if this actuallyt works
        static bool reserve;
    public:
        WaterManager();
        ~WaterManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void returnResource(double amount) override;
        void incCapacityPerc(double perc) override;
        double getWaterCap() const;
        double getInitialWaterCap() const;
        bool getReserve() const;
        void setReserve(bool reserve);

        // added another 2 functions
        void EmergencyRefill();
        void enterDraught();
};

class PowerManager:public ResourceManager{
    friend class TestableResourceManager;
    private:
        static double initialPowerCap; 
        static double powerCap;
        static bool isInitialized;
        // CommandInvoker* invoker; // check if this actuallyt works
        static bool reserve; // means we still have reserve
    public:
        PowerManager();
        ~PowerManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void returnResource(double amount) override;
        void incCapacityPerc(double perc) override;
        double getPowerCap() const;
        double getInitialPowerCap() const;
        bool getReserve() const;
        void setReserve(bool reserve);

        // added another 2 functions
        void switchToNuclear();
        void endWorld();
};

#endif
