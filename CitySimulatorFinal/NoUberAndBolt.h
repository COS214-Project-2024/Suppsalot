#ifndef NO_UBER_AND_BOLT_H
#define NO_UBER_AND_BOLT_H

#include "PublicTransitState.h"
#include <string>

class NoUberAndBolt : public PublicTransitState {
public:
    NoUberAndBolt();
    virtual ~NoUberAndBolt();

    virtual bool buyUber(PublicTransit* transit) override;
    virtual bool buyBolt(PublicTransit* transit) override;

    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
};

#endif 
