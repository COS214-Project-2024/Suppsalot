#include "HighClassCitizen.h"

HighClassCitizen::HighClassCitizen(){
	name = "High Class Citizen";
    satisfaction = 80;
}

PrototypeCitizen* HighClassCitizen::clone() const {
    return new HighClassCitizen(*this);
}

void HighClassCitizen::displayInfo() {
	std::cout << "HighClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << "\n";
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