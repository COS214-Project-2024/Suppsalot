#ifndef HIGHCLASSCITIZEN_H
#define HIGHCLASSCITIZEN_H
#include "PrototypeCitizen.h"
class HighClassCitizen : public PrototypeCitizen {
	int satisfaction;
    bool employed;

public:
	HighClassCitizen();

	PrototypeCitizen* clone() const override { return new HighClassCitizen(*this); }

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
