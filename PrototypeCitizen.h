#ifndef PROTOTYPECITIZEN_H
#define PROTOTYPECITIZEN_H
#include <string>
#include <cstdlib>
#include <random>
#include <iostream>
class PrototypeCitizen {

protected:
	std::string name;
	int age;
	float satisfaction;
	bool isEmployed;
    int growth;
    int currentPopulation;
    double birthRate;
    double deathRate;
public:
    virtual ~PrototypeCitizen() = default;

	virtual PrototypeCitizen* clone() const = 0;

	virtual void displayInfo();

	virtual void calculateSatisfactory();

    virtual void asigningJob(bool jobAvailable);

    virtual double calculatePopulationGrowth();

    int getCurrentPopulation();

    void setBirthRate(double br);

    void setDeathRate(double dr);
    
    double getBirthRate();

    double getDeathRate();

    float getSatisfaction() const;
    virtual void toggleEmployment();

protected:
	virtual void baseSatisfaction() = 0;

	virtual void adjustForEmployment() = 0;

	virtual void adjustForServices() = 0;

	virtual void adjustForPolicies() = 0;
};

#endif