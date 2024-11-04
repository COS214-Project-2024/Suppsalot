#ifndef MAYOR_H
#define MAYOR_H

#include <vector>
#include "citymanager.h"
#include "Department.h"
#include "PublicServicesDepartment.h"
#include "InfrastructureDepartment.h"
#include "EconomyDepartment.h"
#include "SecurityDepartment.h"

class Mayor : public citymanager {
public:
    // Constructor
    Mayor();

    // Notify function to handle department updates
    void notify(Department* dept) override;

    // Set funds for a specific department
    bool setFunds(Department* dept, double amount);

    // Optional: methods to get specific departments
    publicServicesDepartment* getPublicServicesDepartment() const;
    InfrastructureDepartment* getInfrastructureDepartment() const;
    EconomyDepartment* getEconomyDepartment() const;
    securityDepartment* getSecurityDepartment() const;

private:
    std::vector<Department*> departmentList;

    // Specific departments for easier access
    publicServicesDepartment* publicServices;
    InfrastructureDepartment* infrastructure;
    EconomyDepartment* economy;
    securityDepartment* security;
};

#endif // MAYOR_H
