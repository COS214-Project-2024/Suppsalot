#ifndef PUBLICSERVICESDEPARTMENT_H
#define PUBLICSERVICESDEPARTMENT_H
#include "Department.h"
#include <string>

class publicServicesDepartment :public Department {

private:
    double money;
    publicServicesDepartment* instance;
    int numOfUtilities;

public:
    publicServicesDepartment(citymanager* mediator, double m);


    void get();

    void set(double m);

    std::string requestUtility();

    publicServicesDepartment* instanc();
};

#endif
