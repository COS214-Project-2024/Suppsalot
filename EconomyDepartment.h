#ifndef ECONOMYDEPARTMENT_H
#define ECONOMYDEPARTMENT_H
#include "Department.h"

#include <iostream>

class EconomyDepartment : public Department {

private:
    double money;
    EconomyDepartment* instance;
    int numOfFinancialAid;

public:
    EconomyDepartment(citymanager* mediator, double m);
    void get();

    void set(double m);

    std::string giveFinancialAid();

    EconomyDepartment* instanc();
};

#endif
