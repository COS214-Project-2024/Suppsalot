#ifndef PUBLIC_TRANSIT_STATE_H
#define PUBLIC_TRANSIT_STATE_H

#include <string>

class PublicTransit;

class PublicTransitState {
public:
    virtual ~PublicTransitState() {}

    virtual bool buyUber(PublicTransit* transit) = 0;
    virtual bool buyBolt(PublicTransit* transit) = 0;

    virtual std::string getStateName() const = 0;
    virtual double getProductivity() const = 0;
    virtual double getSatisfaction() const = 0;
};

#endif 
