#include "CitizenIterator.h"

CitizenIterator::CitizenIterator(const CitizenCollection* collection){
	this->collection = collection;
	this->index = 0;
}

bool CitizenIterator::hasNext() {
	return index < collection->getSize();
}

PrototypeCitizen* CitizenIterator::next() {
	if (hasNext()) {
        return collection->getCitizenAt(index++);
    }
    return nullptr;
}


