#include "publicServicesDepartment.h"
#include <iostream>
#include <string>

publicServicesDepartment::publicServicesDepartment(citymanager* mediator, double m)
    : Department(mediator), money(m) {
    this->instance = this;
    numOfUtilities=0;
}

void publicServicesDepartment::get() {
    std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void publicServicesDepartment::set(double m) {
    this->money = m;
}

std::string publicServicesDepartment::requestUtility() {

    std::cout<<"You're utility has been requested and is on the way!";
    numOfUtilities++;

}

publicServicesDepartment* publicServicesDepartment::instanc() {
    return this->instance;
}
