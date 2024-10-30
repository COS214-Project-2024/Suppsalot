#ifndef CITIZENITERATOR_H
#define CITIZENITERATOR_H
#include "PrototypeCitizen.h"
#include "CitizenCollection.h"
#include <vector>

class PrototypeCitizen;
class CitizenCollection;

class CitizenIterator {

private:
	const CitizenCollection* collection;
	int index;

public:
	CitizenIterator(const CitizenCollection* collection);
	
	bool hasNext();

	PrototypeCitizen* next();
};

#endif
