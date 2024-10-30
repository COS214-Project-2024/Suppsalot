#include "InfrastructureDepartment.h"

#include <iostream>

InfrastructureDepartment::InfrastructureDepartment(double m) {
	this->money = m;
	this->instance = this;
}

void InfrastructureDepartment::get() {
	std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void InfrastructureDepartment::set(double m) {
	this->money = m;
}

bool InfrastructureDepartment::requestPermit(Building* b) {

	this->Permts.push_back(b);

}

void InfrastructureDepartment::allowPermit() {

	Building* b = this->Permts.front;
	this->Permts.erase(this->Permts.begin());
	b->createBuilding();

}

InfrastructureDepartment* InfrastructureDepartment::instanc() {
	return this->instance;
}
