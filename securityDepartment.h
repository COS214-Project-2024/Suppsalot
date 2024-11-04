#ifndef SECURITYDEPARTMENT_H
#define SECURITYDEPARTMENT_H
#include "Department.h"


class securityDepartment :public Department {

private:
    double money;
    securityDepartment* uninstance;
    int numOfcriminals;

public:
    securityDepartment(citymanager* mediator, double m);

    void get();

    void set(double m);

    void arrest();

    securityDepartment* instanc();
};

#endif
