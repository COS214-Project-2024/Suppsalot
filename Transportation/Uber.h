#ifndef UBER_H
#define UBER_H

#include "PublicTransitState.h"
#include <string>

class Uber : public PublicTransitState {
public:
    Uber();
    virtual ~Uber();

    virtual bool buyUber(PublicTransit* transit) override;
    virtual bool buyBolt(PublicTransit* transit) override;

    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
};

#endif 
