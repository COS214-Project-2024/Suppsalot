#include "LowClassCitizen.h"

LowClassCitizen::LowClassCitizen(): satisfaction(rand() % 21 + 10), employed(false){
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> satisfactionDist(10, 30);
    std::uniform_int_distribution<> ageDist(18, 40);
    age = ageDist(gen);
    name = "Low Class Citizen";
}

PrototypeCitizen* LowClassCitizen::clone() const {
	return new LowClassCitizen(*this);

}

void LowClassCitizen::displayInfo() const{
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

void LowClassCitizen::toggleEmployment(bool emp){
    if (employed != emp) {
        employed = emp;
        if (employed) CitizenStatistics::incrementEmploymentCount();
        else CitizenStatistics::decrementEmploymentCount();
    }
}

int LowClassCitizen::getSatisfaction() const{
    return satisfaction;
}