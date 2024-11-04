#ifndef CITIZENSTATISTICS_H
#define CITIZENSTATISTICS_H
#include "PrototypeCitizen.h"
#include "BuildingStatistics.h"
class CitizenStatistics{
private:
    double citizenSatisfaction;
    PrototypeCitizen* citizen;
    static int EmployedCitizens;
public:
    CitizenStatistics(PrototypeCitizen* citizen);
    double getSatisfaction();
    float getPopulationGrowth();
    void calculateBirthRate(int edu, int health);
    void calculateDeathRate(int hygiene, int security, int water);
    static int totalEmployed(std::vector<PrototypeCitizen*> citizens);
};

#endif