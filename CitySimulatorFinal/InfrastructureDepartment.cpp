#include "InfrastructureDepartment.h"
#include <vector>
#include <iostream>
#include <algorithm>

InfrastructureDepartment::InfrastructureDepartment(citymanager* mediator, double m)
    : Department(mediator), money(m) {
    this->money = m;
    this->instance = this;
}

void InfrastructureDepartment::get() {
    std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void InfrastructureDepartment::set(double m) {
    this->money = m;
}

bool InfrastructureDepartment::requestPermit(const std::string& buildingName) {
    // Check if a building with the same name already exists in the permits list
    auto it = std::find(Permits.begin(), Permits.end(), buildingName);

    if (it == Permits.end()) {
        // If no such building exists, permit it by adding the name to the list
        Permits.push_back(buildingName);
        std::cout << "Permit granted for building: " << buildingName << std::endl;
        return true;
    } else {
        // If the building already exists, deny the permit
        std::cout << "Permit denied for building: " << buildingName << " (already exists)" << std::endl;
        return false;
    }
}






InfrastructureDepartment* InfrastructureDepartment::instanc() {
    return this->instance;
}
