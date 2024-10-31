#ifndef CITIZENSTATISTICS_H
#define CITIZENSTATISTICS_H
#include "PrototypeCitizen.h"
class CitizenStatistics{
private:
    double citizenSatisfaction;
    PrototypeCitizen* citizen;
public:
    CitizenStatistics(PrototypeCitizen* citizen);
    double getSatisfaction();
    float getPopulationGrowth();
    void calculateBirthRate(int edu, int health);
    void calculateDeathRate(int hygiene, int security, int water);
};

#endif

//create a citizen counter for each class and all combined