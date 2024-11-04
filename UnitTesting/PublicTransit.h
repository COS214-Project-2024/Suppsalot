#ifndef PUBLIC_TRANSIT_H
#define PUBLIC_TRANSIT_H

#include "PublicTransitState.h"
#include "Subject.h"
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>

class PublicTransit : public Subject {
public:
    PublicTransit(double& budget);
    ~PublicTransit();

    void buyUber();
    void buyBolt();
    void progressYear();
    
    std::string getCurrentStateName() const;
    double getProductivity() const;
    double getSatisfaction() const;
    double getCityBudget() const;
    
    void adjustCityBudget(double amount);
    void setState(std::unique_ptr<PublicTransitState> newState);

private:
    std::unique_ptr<PublicTransitState> currentState_;
    double& cityBudget_;

    std::string formatMoney(double amount) const;
};

#endif 
