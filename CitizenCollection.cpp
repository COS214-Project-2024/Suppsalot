#include "CitizenCollection.h"

void CitizenCollection::addCitizen(PrototypeCitizen* citizen) {
	citizens.push_back(citizen);
}

CitizenIterator CitizenCollection::createIterator() {
	return CitizenIterator(this);
}

PrototypeCitizen* CitizenCollection::getCitizenAt(int index) const {
    if (index >= 0 && index < static_cast<int>(citizens.size())) {
        return citizens[index];
    }
    return nullptr;
}

int CitizenCollection::getSize() const {
    return citizens.size();
}
