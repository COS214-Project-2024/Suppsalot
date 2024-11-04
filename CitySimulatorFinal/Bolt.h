#ifndef BOLT_H
#define BOLT_H

#include "PublicTransitState.h"
#include <string>

class Bolt : public PublicTransitState {
public:
    Bolt();
    virtual ~Bolt();

    virtual bool buyUber(PublicTransit* transit) override;
    virtual bool buyBolt(PublicTransit* transit) override;

    virtual std::string getStateName() const override;
    virtual double getProductivity() const override;
    virtual double getSatisfaction() const override;
};

#endif
