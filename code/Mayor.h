#ifndef MAYOR_H
#define MAYOR_H
#include "citymanager.h"
#include "Department.h"
#include "EconomyDepartment.h"
#include "InfrastructureDepartment.h"
#include "publicServicesDepartment.h"
#include "securityDepartment.h"

class Mayor :public citymanager {

private:
	Department* departmentList;
	PrototypeCitizen* c;
	static Mayor* instance;

public:
	Mayor(PrototypeCitizen* c);

	void notify();

	bool setFunds(Department* dept, double allocr);

	Mayor* instanc();

	void displayInfo();

	void calculateSatisfactory();

	double calculatePopulationGrowth();

	int getCurrentPopulation();

	void setBirthRate(double br);

	void setDeathRate(double dr);

	double getBirthRate();

	double getDeathRate();

	float getSatisfaction();

	void asigningJob(bool jobAvailable);

	bool notif(InfrastructureDepartment* i);

	bool notif(EconomyDepartment* e);

	bool notif(publicServicesDepartment* p);

	bool notif(securityDepartment* s);
};

#endif
