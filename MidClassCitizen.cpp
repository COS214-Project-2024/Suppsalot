#include "MidClassCitizen.h"

MidClassCitizen::MidClassCitizen(): satisfaction(rand() % 21 + 70), employed(false){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(40, 60);
    std::uniform_int_distribution<> ageDist(20, 50);
    age = ageDist(gen);
	name = "Mid Class Citizen";
}

PrototypeCitizen* MidClassCitizen::clone() const{
	return new MidClassCitizen(*this);
}

void MidClassCitizen::displayInfo() const{
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

void MidClassCitizen::toggleEmployment(bool emp){
    if (employed != emp) {
        employed = emp;
        if (employed) CitizenStatistics::incrementEmploymentCount();
        else CitizenStatistics::decrementEmploymentCount();
    }
}

int MidClassCitizen::getSatisfaction() const{
    return satisfaction;
}