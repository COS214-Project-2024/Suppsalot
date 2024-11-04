#ifndef LOWCLASSCITIZEN_H
#define LOWCLASSCITIZEN_H
#include "PrototypeCitizen.h"
class LowClassCitizen : public PrototypeCitizen {
public:
	static int LCC;
    LowClassCitizen();
	PrototypeCitizen* clone() const override;
	void displayInfo() override;
protected:
	void baseSatisfaction() override;
	void adjustForEmployment() override;
	void adjustForServices() override;

	void adjustForPolicies() override;

	void toggleEmployment() override;
	static int getLowClassCount();
};

#endif