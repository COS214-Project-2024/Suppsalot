// CitizensManager.h
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
#include "BuildingStatistics.h" // Assuming this contains YearCitizenConsumer

class CitizensManager {
    friend class TestableCitizensManager;
public:
    CitizensManager();
    ~CitizensManager();

    void manageCitizens();
    void progressYear();

    float getAverageSatisfaction() const;

    float getTotalSatisfaction() ;

private:
    std::vector<std::unique_ptr<PrototypeCitizen>> citizens;
    float totalSatisfaction;

    // Helper function to validate user input
    int getValidatedChoice(int min, int max);
};

#endif // CITIZENSMANAGER_H
