#include "LowClassCitizen.h"

LowClassCitizen::LowClassCitizen(){
    name = "Low Class Citizen";
    satisfaction = 30;
}

PrototypeCitizen* LowClassCitizen::clone() const {
	return new LowClassCitizen(*this);

}

void LowClassCitizen::displayInfo() {
	std::cout << "LowClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << "\n";
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