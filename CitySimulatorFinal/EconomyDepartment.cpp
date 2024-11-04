#include "EconomyDepartment.h"

EconomyDepartment::EconomyDepartment(citymanager* mediator, double m)
    : Department(mediator), money(m) {
    this->instance = this;
    numOfFinancialAid=0;
}


void EconomyDepartment::get() {
    std::cout<<"currents funds of the department of economy: "<<this->money<<std::endl;
}

void EconomyDepartment::set(double m) {
    this->money = m;
}

std::string EconomyDepartment::giveFinancialAid() {
    std::cout<<"financial aid has been given";
    numOfFinancialAid++;
}

EconomyDepartment* EconomyDepartment::instanc() {
    return this->instance;
}
