#include "MidClassCitizen.h"

MidClassCitizen::MidClassCitizen(){
	name = "Mid Class Citizen";
    satisfaction = 50;
}

PrototypeCitizen* MidClassCitizen::clone() const{
	return new MidClassCitizen(*this);
}

void MidClassCitizen::displayInfo() {
	std::cout << "MidClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << "\n";
}

void MidClassCitizen::baseSatisfaction() {
	satisfaction = 50;
}

void MidClassCitizen::adjustForEmployment() {
	satisfaction += (isEmployed ? 20 : -10);
}

void MidClassCitizen::adjustForServices() {
	satisfaction += 10;
}

void MidClassCitizen::adjustForPolicies() {
	satisfaction -= 2;
}