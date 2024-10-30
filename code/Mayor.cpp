#include "Mayor.h"

#include "Department.h"

Mayor::Mayor(PrototypeCitizen *c) {
        this->c = c;
        departmentList = new Department[4];
        this->instance = this;
}


bool Mayor::setFunds(Department* dept,double allocr) {

}

void Mayor::notify() {

}

Mayor* Mayor::instanc() {
    return this->instance;
}

void PrototypeCitizen::displayInfo() {
    std::cout << "Name: " << name << "\nAge: " << age << "\nSatisfaction: " << satisfaction
              << "\nEmployment Status: " << (isEmployed ? "Employed" : "Unemployed") << "\n";
}

void Mayor::calculateSatisfactory() {
    baseSatisfaction();
    adjustForEmployment();
    adjustForServices();
    adjustForPolicies();
}

void Mayor::asigningJob(bool jobAvailable){
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

double Mayor::calculatePopulationGrowth(){
    growth = currentPopulation * (birthRate - deathRate);
    currentPopulation += growth;
    return currentPopulation;
}

int Mayor::getCurrentPopulation(){
    return currentPopulation;
}

void Mayor::setBirthRate(double br){
    birthRate = br;
}

void Mayor::setDeathRate(double dr){
    deathRate = dr;
}

double Mayor::getBirthRate(){
    return birthRate;
}

double Mayor::getDeathRate(){
    return deathRate;
}

float Mayor::getSatisfaction(){
    return satisfaction;
}

void Mayor::displayInfo() {
    PrototypeCitizen::displayInfo();
    std::cout << "Class: High\n";
}

