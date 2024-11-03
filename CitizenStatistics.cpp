#include "CitizenStatistics.h"

CitizenStatistics::CitizenStatistics(PrototypeCitizen* citizen){
    this->citizen = citizen;
    this->citizenSatisfaction = 0.0;
}

double CitizenStatistics::getSatisfaction(){
    if (citizen) {
        citizen->calculateSatisfactory();  // Recalculate satisfaction for the citizen
        citizenSatisfaction = citizen->getSatisfaction();
    }
    return citizenSatisfaction;
}

int CitizenStatistics::calculatePopulationGrowth() {
        int growth = static_cast<int>(totalPopulation * (birthRate - deathRate));
        totalPopulation += growth;
        return totalPopulation;
    }

void CitizenStatistics::calculateBirthRate(int edu, int health){
    double birthRate = 0.02 + (health * 0.001) - (edu * 0.0005);
    birthRate = birthRate > 0 ? birthRate : 0; //no negative
    citizen->setBirthRate(birthRate);
}

void CitizenStatistics::calculateDeathRate(int hygiene, int security, int water){
    double deathRate = 0.01 + (0.02 - (hygiene * 0.001)) + (0.02 - (security * 0.001)) + (0.02 - (water * 0.001));
    deathRate = deathRate > 0 ? deathRate : 0; // no negative
    citizen->setDeathRate(deathRate);
}

int CitizenStatistics::YearPopulationIncrease(){
    int increase = static_cast<int>(totalCitizenCount * 0.02 + sqrt(totalCitizenCount) * 5);
    totalCitizenCount += increase;
    return increase;
}

int CitizenStatistics::YearSatisfactionIncrease(){
    return static_cast<int>((highClassCount * 2 + midClassCount + lowClassCount * 0.5) * 1.5);
}
void CitizenStatistics::displayStatistics() {
    std::cout << "Total Citizens: " << totalCitizenCount << "\n"
              << "Employed Citizens: " << employedCount << "\n"
              << "Unemployed Citizens: " << unemployedCount << "\n";
}
int CitizenStatistics::totalPopulation = 0;
double CitizenStatistics::birthRate = 0.02;
double CitizenStatistics::deathRate = 0.01;