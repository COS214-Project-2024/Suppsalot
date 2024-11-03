#ifndef LOWCLASSCITIZEN_H
#define LOWCLASSCITIZEN_H
#include "PrototypeCitizen.h"
class LowClassCitizen : public PrototypeCitizen {
	int satisfaction;
    bool employed;

public:
    LowClassCitizen();

	PrototypeCitizen* clone() const override;

	void displayInfo() const override;

	bool isEmployed() const { return employed; }


protected:
	void baseSatisfaction() override;

	void adjustForEmployment() override;

	void adjustForServices() override;

	void adjustForPolicies() override;

	void toggleEmployment(bool emp) override;

	int getSatisfaction() const;
};

#endif