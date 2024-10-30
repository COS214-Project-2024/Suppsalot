#ifndef CITYMANAGER_H
#define CITYMANAGER_H
#include "PrototypeCitizen.h"

class citymanager :public PrototypeCitizen {
public:
	virtual void notify() = 0;
};

#endif
