#include "MidClassCitizen.h"

MidClassCitizen::MidClassCitizen(){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(40, 60);
    std::uniform_int_distribution<> ageDist(20, 50);

    satisfaction = satisfactionDist(gen);
    age = ageDist(gen);
    isEmployed = true;
	name = "Mid Class Citizen";
}

PrototypeCitizen* MidClassCitizen::clone() const{
	return new MidClassCitizen(*this);
}

void MidClassCitizen::displayInfo() {
	std::cout << "MidClassCitizen - Age: " << age << ", Satisfaction: " << satisfaction << ", Employed: " << (isEmployed ? "Yes" : "No") << "\n";
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

void MidClassCitizen::toggleEmployment() {
    isEmployed = !isEmployed;
}