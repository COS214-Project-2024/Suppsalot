#ifndef CITIZENSMANAGER_H
#define CITIZENSMANAGER_H

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include "CitizenStatistics.h"
#include "BuildingStatistics.h" 

class CitizensManager {
public:
    CitizensManager();
    ~CitizensManager();

    void manageCitizens();
    void progressYear();

    float getAverageSatisfaction() const;

    int getTotalPopulation() const;
    int getTotalEmployed() const;

private:
    std::vector<std::unique_ptr<PrototypeCitizen>> citizens;
    float totalSatisfaction;

    int getValidatedChoice(int min, int max);
};

#endif 
