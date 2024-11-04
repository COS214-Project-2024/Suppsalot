#include <iostream>
#include "Mayor.h"
#include "PublicServicesDepartment.h"
#include "InfrastructureDepartment.h"
#include "EconomyDepartment.h"
#include "SecurityDepartment.h"

int main() {
    // Create the Mayor (mediator)
    Mayor* mayor = new Mayor();

    // Create departments and pass the mayor as the mediator
    publicServicesDepartment* publicServices = new publicServicesDepartment(mayor, 50000.0); // initial funds
    InfrastructureDepartment* infrastructure = new InfrastructureDepartment(mayor, 100000.0);
    EconomyDepartment* economy = new EconomyDepartment(mayor, 75000.0);
    securityDepartment* security = new securityDepartment(mayor, 60000.0);

    // Add departments to the mayor (optional if `Mayor` has methods to add departments)
    // This step is not necessary if the Mayor already stores references to these specific departments

    std::cout << "\n--- Testing Department Fund Setup ---" << std::endl;
    publicServices->get(); // Check initial funds
    infrastructure->get();  // Check initial funds

    std::cout << "\n--- Modifying Department Funds Through Mayor ---" << std::endl;
    // Set funds for the public services department
    mayor->setFunds(publicServices, 55000.0);
    publicServices->get(); // Check updated funds

    // Set funds for the infrastructure department
    mayor->setFunds(infrastructure, 120000.0);
    infrastructure->get(); // Check updated funds

    std::cout << "\n--- Testing Notify Functionality ---" << std::endl;
    // Simulate changes in departments
    publicServices->changed(); // Notify mayor of a change in Public Services
    infrastructure->changed();  // Notify mayor of a change in Infrastructure
    economy->changed();         // Notify mayor of a change in Economy
    security->changed();        // Notify mayor of a change in Security

    // Optional cleanup
    delete mayor;

    return 0;
}
