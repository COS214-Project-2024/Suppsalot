//done 

//check up
#include "PrototypeCitizen.h"

int PrototypeCitizen::citizenCount = 0;


void PrototypeCitizen::calculateSatisfactory() {
	baseSatisfaction();
    adjustForEmployment();
    adjustForServices();
    adjustForPolicies();
}

double PrototypeCitizen::calculatePopulationGrowth(){
    growth = currentPopulation * (birthRate - deathRate);
    currentPopulation += growth;
    return currentPopulation;
}

int PrototypeCitizen::getCurrentPopulation(){
    return currentPopulation;
}

void PrototypeCitizen::setBirthRate(double br){
    birthRate = br;
}

void PrototypeCitizen::setDeathRate(double dr){
    deathRate = dr;
}

double PrototypeCitizen::getBirthRate(){
    return birthRate;
}

double PrototypeCitizen::getDeathRate(){
    return deathRate;
}

float PrototypeCitizen::getSatisfaction() const{
    return satisfaction;
}

int PrototypeCitizen::getCitizenCount() {
        return citizenCount;
}