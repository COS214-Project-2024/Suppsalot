#ifndef INFRASTRUCTUREDEPARTMENT_H
#define INFRASTRUCTUREDEPARTMENT_H
#include <vector>
#include<string>

#include "Department.h"

class InfrastructureDepartment :public Department {

private:
    double money;
    std::vector<std::string> Permits;
    InfrastructureDepartment* instance;

public:
    InfrastructureDepartment(citymanager* mediator, double m);

    void get();

    void set(double m);

    bool requestPermit(const std::string& buildingName);



    InfrastructureDepartment* instanc();
};

#endif
