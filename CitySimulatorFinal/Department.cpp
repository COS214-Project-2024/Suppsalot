#include "Department.h"
#include "citymanager.h"

// Constructor (if necessary)
Department::Department(citymanager* mediator) : mediator(mediator) {}

// Notify the mediator of any changes in this department
void Department::changed() {
    if (mediator) {
        mediator->notify(this);
    }
}

// Getter for department funds or other relevant properties
double Department::get() const {
    return assignedFunds; // Assuming `assignedFunds` is a property in the department
}

// Setter for department funds or other relevant properties
void Department::set(double amount) {
    assignedFunds = amount;
    changed(); // Notify mediator of the change
}
