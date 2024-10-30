#include "EconomyDepartment.h"

EconomyDepartment::EconomyDepartment(double m) {
	this->money = m;
	this->instance = this;
}


void EconomyDepartment::get() {
	std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void EconomyDepartment::set(double m) {
	this->money = m;
}

bool EconomyDepartment::giveFinancialAid(PrototypeCitizen* c) {
	// TODO - implement EconomyDepartment::giveFinancialAid
	throw "Not yet implemented";
}

EconomyDepartment* EconomyDepartment::instanc() {
	return this->instance;
}
