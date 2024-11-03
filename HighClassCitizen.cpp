#include "HighClassCitizen.h"

HighClassCitizen::HighClassCitizen(): satisfaction(rand() % 21 + 70), employed(false){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(70, 90);
    std::uniform_int_distribution<> ageDist(25, 60);
    age = ageDist(gen);
	name = "High Class Citizen";
}

void HighClassCitizen::displayInfo() const {
	std::cout << "HighClassCitizen - Age: " << age << ", Satisfaction: " << ", Employed: " << (isEmployed ? "Yes" : "No") << "\n";;
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

void HighClassCitizen::toggleEmployment(bool emp){
    if (employed != emp) {
        employed = emp;
        if (employed) CitizenStatistics::incrementEmploymentCount();
        else CitizenStatistics::decrementEmploymentCount();
    }
}

int HighClassCitizen::getSatisfaction() const{
    return satisfaction;
}