#ifndef CITIZENSTATISTICS_H
#define CITIZENSTATISTICS_H
#include "PrototypeCitizen.h"
#include <cmath>
#include <memory>
#include <iostream>
class CitizenStatistics{
private:
    double citizenSatisfaction;
    PrototypeCitizen* citizen;
    static int totalCitizenCount;
    static int totalPopulation;
    static double birthRate;
    static double deathRate;
    static int highClassCount;
    static int midClassCount;
    static int lowClassCount;
    static int employedCount;
    static int unemployedCount;
public:
    CitizenStatistics(PrototypeCitizen* citizen);
    double getSatisfaction();
    static int calculatePopulationGrowth();
    void calculateBirthRate(int edu, int health);
    void calculateDeathRate(int hygiene, int security, int water);
    static void incrementCitizenCount() { ++totalCitizenCount; }
    static void decrementCitizenCount() { --totalCitizenCount; }
    static void incrementEmploymentCount() { ++employedCount; }
    static void decrementEmploymentCount() { --employedCount; }
    static void incrementUnemploymentCount() { ++unemployedCount; }
    static void decrementUnemploymentCount() { --unemployedCount; }
    static int getTotalCitizenCount() { return totalCitizenCount; }
    static int getEmployedCount() { return employedCount; }
    static int getUnemployedCount() { return unemployedCount; }
    static int YearPopulationIncrease();
    static int YearSatisfactionIncrease();
    static void YearEmploymentAdjustment();
    static void displayStatistics();
    static void setBirthRate(double br) { birthRate = br; }
    static void setDeathRate(double dr) { deathRate = dr; }
    static int getTotalPopulation() { return totalPopulation; }
    static double getBirthRate() { return birthRate; }
    static double getDeathRate() { return deathRate; }
    static float calculateAverageSatisfaction(const std::vector<std::unique_ptr<PrototypeCitizen>>& citizens) {
        float totalSatisfaction = 0.0f;
        for (const auto& citizen : citizens) {
            totalSatisfaction += citizen->getSatisfaction();
        }
        return citizens.empty() ? 0 : (totalSatisfaction / citizens.size());
    }
};

#endif

//create a citizen counter for each class and all combined