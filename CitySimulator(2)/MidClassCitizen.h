#ifndef MIDCLASSCITIZEN_H
#define MIDCLASSCITIZEN_H
#include "PrototypeCitizen.h"

class MidClassCitizen : public PrototypeCitizen {


public:
static int MCC;

MidClassCitizen();

PrototypeCitizen* clone() const override;

void displayInfo() override;

static int getMidClassCount();
protected:
void baseSatisfaction() override;

void adjustForEmployment() override;

void adjustForServices() override;

void adjustForPolicies() override;

void toggleEmployment() override;



};

#endif