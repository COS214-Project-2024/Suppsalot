#ifndef PUBLICSERVICESDEPARTMENT_H
#define PUBLICSERVICESDEPARTMENT_H
#include "Department.h"

class publicServicesDepartment :public Department {

private:
	double money;
	publicServicesDepartment* instance;

public:
	publicServicesDepartment(double m);

	void get();

	void set(double m);

	void BuildUtility(Utility* u);

	publicServicesDepartment* instanc();
};

#endif
