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

float CitizenStatistics::getPopulationGrowth(){
    if (citizen) {
        return static_cast<float>(citizen->calculatePopulationGrowth());
    }
    return 0.0f;//no citizen
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
