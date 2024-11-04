#include "PrototypeCitizen.h"
#include "ResourceManager.h"
#include "BuildingStatistics.h"

int PrototypeCitizen::citizenCount = 0;

void PrototypeCitizen::displayInfo() {
	std::cout << "Name: " << name << "\nAge: " << age << "\nSatisfaction: " << satisfaction 
              << "\nEmployment Status: " << (isEmployed ? "Employed" : "Unemployed") << "\n";
}
void PrototypeCitizen::calculateSatisfactory() {
	baseSatisfaction();
    adjustForEmployment();
    adjustForServices();
    adjustForPolicies();
}
void PrototypeCitizen::asigningJob(bool jobAvailable){
    isEmployed = jobAvailable;
    if (!jobAvailable){
        satisfaction -= 10;
        std::cout << "Job not assigned to Citizen :C";
    }
    else{
        std::cout << "HOORAY!!!";
        satisfaction += 10;
    }
    
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

void PrototypeCitizen::toggleEmployment() {
    isEmployed = !isEmployed;
}

int PrototypeCitizen::getCitizenCount() {
        return citizenCount;
}

bool PrototypeCitizen::getEmployment(){
    return isEmployed;
}
void PrototypeCitizen::citizenCapcity(){
    BuildingStatistics::YearCitizenConsumer(getCitizenCount());
}

