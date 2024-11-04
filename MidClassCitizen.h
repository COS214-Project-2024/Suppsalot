#ifndef MIDCLASSCITIZEN_H
#define MIDCLASSCITIZEN_H
#include "PrototypeCitizen.h"

class MidClassCitizen : public PrototypeCitizen {


public:
static int MCC;

MidClassCitizen();

PrototypeCitizen* clone() const override;

void displayInfo() override;

protected:
void baseSatisfaction() override;

void adjustForEmployment() override;

void adjustForServices() override;

void adjustForPolicies() override;

void toggleEmployment() override;

static int getMidClassCount();

};

#endif