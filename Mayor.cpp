#include "Mayor.h"
#include <iostream>

Mayor::Mayor() {

    publicServices = new publicServicesDepartment(this, 0);
    infrastructure = new InfrastructureDepartment(this, 0);
    economy = new EconomyDepartment( this,0);
    security = new securityDepartment(this, 0);

    // Add all departments to the list for unified management
    departmentList.push_back(publicServices);
    departmentList.push_back(infrastructure);
    departmentList.push_back(economy);
    departmentList.push_back(security);

    std::cout << "Mayor created and linked to all departments." << std::endl;
}

// Notify implementation for handling department notifications
void Mayor::notify(Department* dept) {
    // Identify department type and respond to changes
    if (dept == publicServices) {
        std::cout << "Mayor: Public Services Department notified the mayor." << std::endl;
        // Additional logic for public services
    } else if (dept == infrastructure) {
        std::cout << "Mayor: Infrastructure Department notified the mayor." << std::endl;
        // Additional logic for infrastructure
    } else if (dept == economy) {
        std::cout << "Mayor: Economy Department notified the mayor." << std::endl;
        // Additional logic for economy
    } else if (dept == security) {
        std::cout << "Mayor: Security Department notified the mayor." << std::endl;
        // Additional logic for security
    }
}

// Set funds for a specific department
bool Mayor::setFunds(Department* dept, double amount) {
    if (dept) {
        dept->set(amount);
        std::cout << "Mayor set funds for a department." << std::endl;
        return true;
    }
    return false;
}

// Getters for each specific department
publicServicesDepartment* Mayor::getPublicServicesDepartment() const {
    return publicServices;
}

InfrastructureDepartment* Mayor::getInfrastructureDepartment() const {
    return infrastructure;
}

EconomyDepartment* Mayor::getEconomyDepartment() const {
    return economy;
}

securityDepartment* Mayor::getSecurityDepartment() const {
    return security;
}
