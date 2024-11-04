#include "LowClassCitizen.h"

int LowClassCitizen::LCC = 0;

LowClassCitizen::LowClassCitizen(){
    ++LCC;
std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(10, 30);
    std::uniform_int_distribution<> ageDist(18, 40);

    satisfaction = satisfactionDist(gen);
    age = ageDist(gen);
    isEmployed = false;
    name = "Low Class Citizen";
}

PrototypeCitizen* LowClassCitizen::clone() const {
return new LowClassCitizen(*this);

}

void LowClassCitizen::displayInfo() {
std::cout << "LowClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << ", Employed: " << (isEmployed ? "Yes" : "No") << "\n";;
}

void LowClassCitizen::baseSatisfaction() {
satisfaction = 30;
}

void LowClassCitizen::adjustForEmployment() {
satisfaction += (isEmployed ? 15 : -15);
}

void LowClassCitizen::adjustForServices() {
satisfaction += 5;
}

void LowClassCitizen::adjustForPolicies() {
satisfaction -= 5;
}

void LowClassCitizen::toggleEmployment() {
    isEmployed = !isEmployed;
}

int LowClassCitizen::getLowClassCount(){
    return LCC;
}