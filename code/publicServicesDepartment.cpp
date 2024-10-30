#include "publicServicesDepartment.h"
#include <iostream>

publicServicesDepartment::publicServicesDepartment(double m) {
	this->money = m;
	this->instance = this;
}

void publicServicesDepartment::get() {
	std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void publicServicesDepartment::set(double m) {
	this->money = m;
}

void publicServicesDepartment::BuildUtility(Utility* u) {
	u->buildUtility();
}

publicServicesDepartment* publicServicesDepartment::instanc() {
	return this->instance;
}
