#ifndef CITIZENCOLLECTION_H
#define CITIZENCOLLECTION_H
#include "CitizenIterator.h"
#include "PrototypeCitizen.h"
#include <vector>
class CitizenIterator;

class CitizenCollection{

private:
	std::vector<PrototypeCitizen*> citizens;

public:
	void addCitizen(PrototypeCitizen* citizen);

	CitizenIterator createIterator();

	PrototypeCitizen* getCitizenAt(int index) const;

    int getSize() const;
};

#endif
