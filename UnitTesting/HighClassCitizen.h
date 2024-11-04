#ifndef HIGHCLASSCITIZEN_H
#define HIGHCLASSCITIZEN_H
#include "PrototypeCitizen.h"
class HighClassCitizen : public PrototypeCitizen
{

public:
    static int HCC;
    HighClassCitizen();

    PrototypeCitizen *clone() const override;

    void displayInfo() override;
    static int getHighClassCount();

protected:
    void baseSatisfaction() override;

    void adjustForEmployment() override;

    void adjustForServices() override;

    void adjustForPolicies() override;

    void toggleEmployment() override;
};

#endif