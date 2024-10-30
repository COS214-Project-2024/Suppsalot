#include "securityDepartment.h"

securityDepartment::securityDepartment(double m) {
	this->money = m;
	this->uninstance =this;
}

void securityDepartment::get() {
	std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void securityDepartment::set(double m) {
	this->money = m;
}

void securityDepartment::arrest(PrototypeCitizen* criminal) {
	criminal->arrest();
}

securityDepartment* securityDepartment::instanc() {
	return this->uninstance;
}
