// #ifndef RESOURCEMANAGER_H
// #define RESOURCEMANAGER_H

// #include <vector>
// #include <string>
// #include <iostream>
// #include <cmath>

// #include "CommandInvoker.h"
// // the following class refers to the subject along with 
// // its concrete subjects for the observer pattern
// class ResourceManager{
//     private:
//         std::vector<CommandInvoker*> observers; 
//     public:
//         void attach(CommandInvoker* observers);
//         void detach (CommandInvoker* observers);
//         void notify(const std::string& recourceType);
//         virtual ~ResourceManager();
        
//         // Concrete resources should implement their own capacity management
//         virtual double getResource() const = 0;
//         virtual void useResource(double amount) = 0;
//         virtual void incCapacityPerc(double perc) = 0;
// };

// class WoodManager:public ResourceManager{
//     private:
//         double woodCap;
//         double initialWoodCap; // will this actually be needed
//     public:
//         WoodManager();
//         ~WoodManager();         

//         // double getWoodAmount() const;
//         // void useWood(double amount);
//         // void incWoodPerc(double perc);   
//         // rather than doing it like this why not have a pure virtual function up top which is then 
//         // implemented differentely for each of the derived classes

//         double getResource() const override;
//         void useResource(double amount) override;
//         void incCapacityPerc(double perc) override;
// };

// class SteelManager:public ResourceManager{
//     private:
//         double steelCap;
//         double initialSteelCap; // again is this necessary
//     public:
//         SteelManager();
//         ~SteelManager();   
//         double getResource() const override;
//         void useResource(double amount) override;
//         void incCapacityPerc(double perc) override;
// };


// class ConcreteManager:public ResourceManager{
//     private:
//         double concreteCap;
//         double initialConcreteCap; // again is this necessary
//     public:
//         ConcreteManager();
//         ~ConcreteManager();   
//         double getResource() const override;
//         void useResource(double amount) override;
//         void incCapacityPerc(double perc) override;
// };

// class WaterManager:public ResourceManager{
//     private:
//         double waterCap;
//         double initialWaterCap;
//         CommandInvoker* invoker; // check if this actuallyt works
//         bool reserve = true; // means we still have reserve
//     public:
//         WaterManager();
//         ~WaterManager();   
//         double getResource() const override;
//         void useResource(double amount) override;
//         void incCapacityPerc(double perc) override;

//         // added another 2 functions
//         void EmergencyRefill();
//         void enterDraught();
// };

// class PowerManager:public ResourceManager{
//     private:
//         double powerCap;
//         double initialPowerCap; 
//         CommandInvoker* invoker; // check if this actuallyt works
//         bool reserve = true; // means we still have reserve
//     public:
//         PowerManager();
//         ~PowerManager();   
//         double getResource() const override;
//         void useResource(double amount) override;
//         void incCapacityPerc(double perc) override;

//         // added another 2 functions
//         void switchToNuclear();
//         void endWorld();
// };

// #endif




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
        virtual void incCapacityPerc(double perc) = 0;
};

class WoodManager:public ResourceManager{
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
        void incCapacityPerc(double perc) override;
};

class SteelManager:public ResourceManager{
    private:
        static double initialSteelCap; // again is this necessary
        static double steelCap;
        static bool isInitialized;

    public:
        SteelManager();
        ~SteelManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void incCapacityPerc(double perc) override;
};


class ConcreteManager:public ResourceManager{
    private:
        static double initialConcreteCap; // again is this necessary
        static double concreteCap;
        static bool isInitialized;
    public:
        ConcreteManager();
        ~ConcreteManager();   
        double getResource() const override;
        void useResource(double amount) override;
        void incCapacityPerc(double perc) override;
};

class WaterManager:public ResourceManager{
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
        void incCapacityPerc(double perc) override;

        // added another 2 functions
        void EmergencyRefill();
        void enterDraught();
};

class PowerManager:public ResourceManager{
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
        void incCapacityPerc(double perc) override;

        // added another 2 functions
        void switchToNuclear();
        void endWorld();
};

#endif
