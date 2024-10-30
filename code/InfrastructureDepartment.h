#ifndef INFRASTRUCTUREDEPARTMENT_H
#define INFRASTRUCTUREDEPARTMENT_H
#include <vector>
#include 'Building,h'
#include "Department.h"

class InfrastructureDepartment :public Department {

private:
	double money;
	std::vector<Building*> Permts;
	InfrastructureDepartment* instance;

public:
	InfrastructureDepartment(double m);

	void get();

	void set(double m);

	bool requestPermit(Building* b);

	void allowPermit();

	InfrastructureDepartment* instanc();
};

#endif
