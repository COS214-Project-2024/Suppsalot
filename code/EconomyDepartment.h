#ifndef ECONOMYDEPARTMENT_H
#define ECONOMYDEPARTMENT_H
#include "Department.h"
#include "PrototypeCitizen.h"
#include <iostream>

class EconomyDepartment : public Department {

private:
	double money;
	EconomyDepartment* instance;

public:
	EconomyDepartment(double m);

	void get();

	void set(double m);

	bool giveFinancialAid(PrototypeCitizen* c);

	EconomyDepartment* instanc();
};

#endif
