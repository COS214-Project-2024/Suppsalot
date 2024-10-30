#ifndef HIGHCLASSCITIZEN_H
#define HIGHCLASSCITIZEN_H
#include "PrototypeCitizen.h"
class HighClassCitizen : public PrototypeCitizen {


public:
	HighClassCitizen();

	PrototypeCitizen* clone() const override;

	void displayInfo() override;

protected:
	void baseSatisfaction() override;

	void adjustForEmployment() override;

	void adjustForServices() override;

	void adjustForPolicies() override;
};

#endif
