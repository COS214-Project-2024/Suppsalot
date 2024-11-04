#include "securityDepartment.h"
#include <iostream>

securityDepartment::securityDepartment(citymanager* mediator, double m)
    : Department(mediator), money(m) {
    this->uninstance = this;
}

void securityDepartment::get() {
    std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void securityDepartment::set(double m) {
    this->money = m;
}

void securityDepartment::arrest() {
	std::cout<<"arrest has been made";
    numOfcriminals++;
}

securityDepartment* securityDepartment::instanc() {
    return this->uninstance;
}
