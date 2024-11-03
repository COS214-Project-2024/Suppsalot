#ifndef PROTOTYPECITIZEN_H
#define PROTOTYPECITIZEN_H
#include <string>
#include <cstdlib>
#include <random>
#include <iostream>
#include "CitizenStatistics.h"
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
    static int citizenCount;
public:
    PrototypeCitizen() { CitizenStatistics::incrementCitizenCount(); }

    virtual ~PrototypeCitizen() { CitizenStatistics::decrementCitizenCount(); }

	virtual PrototypeCitizen* clone() const = 0;

	virtual void displayInfo() const = 0;

	virtual void calculateSatisfactory();

    virtual double calculatePopulationGrowth();

    virtual bool isEmployed() const;

    int getCurrentPopulation();

    void setBirthRate(double br);

    void setDeathRate(double dr);
    
    double getBirthRate();

    double getDeathRate();

    float getSatisfaction() const;

    virtual void toggleEmployment(bool employed) = 0;

    static int getCitizenCount();

protected:
	virtual void baseSatisfaction() = 0;

	virtual void adjustForEmployment() = 0;

	virtual void adjustForServices() = 0;

	virtual void adjustForPolicies() = 0;
};

#endif