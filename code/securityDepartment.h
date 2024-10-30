#ifndef SECURITYDEPARTMENT_H
#define SECURITYDEPARTMENT_H
#include "Department.h"
#include "PrototypeCitizen.h"

class securityDepartment :public Department {

private:
	double money;
	securityDepartment* uninstance;

public:
	securityDepartment(double m);

	void get();

	void set(double m);

	void arrest(PrototypeCitizen* criminal);

	securityDepartment* instanc();
};

#endif
