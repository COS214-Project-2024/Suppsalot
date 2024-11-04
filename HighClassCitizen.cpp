#include "HighClassCitizen.h"
int HighClassCitizen::HCC = 0;

HighClassCitizen::HighClassCitizen(){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(70, 90);
    std::uniform_int_distribution<> ageDist(25, 60);

    satisfaction = satisfactionDist(gen);
    age = ageDist(gen);
    isEmployed = true;
	name = "High Class Citizen";
}

PrototypeCitizen* HighClassCitizen::clone() const {
    return new HighClassCitizen(*this);
}

void HighClassCitizen::displayInfo() {
	std::cout << "HighClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << ", Employed: " << (isEmployed ? "Yes" : "No") << "\n";;
}

void HighClassCitizen::baseSatisfaction() {
	satisfaction = 80;
}
void HighClassCitizen::adjustForEmployment() {
	satisfaction += (isEmployed ? 25 : -5);
}
void HighClassCitizen::adjustForServices() {
	satisfaction += 15;
}

void HighClassCitizen::adjustForPolicies() {
	satisfaction += 5;
}

void HighClassCitizen::toggleEmployment() {
    isEmployed = !isEmployed;
}

int HighClassCitizen::getHighClassCount(){
    return HCC;
}