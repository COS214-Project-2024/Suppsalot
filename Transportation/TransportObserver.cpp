#include "TransportObserver.h"

TransportObserver::TransportObserver(Road& road, TrainSystem& train, PublicTransit& transit)
    : road_(road), train_(train), transit_(transit),
      transportSatisfaction_(0.0), transportProductivity_(0.0)
{}

void TransportObserver::update() {
    transportSatisfaction_ = 0.4 * road_.getSatisfaction() +
                             0.3 * train_.getSatisfaction() +
                             0.3 * transit_.getSatisfaction();
    
    transportProductivity_ = (road_.getProductivity() * 0.4) +
                             (train_.getProductivity() * 0.3) +
                             (transit_.getProductivity() * 0.3);
}

double TransportObserver::getTransportSatisfaction() const {
    return transportSatisfaction_;
}

double TransportObserver::getTransportProductivity() const {
    return transportProductivity_;
}
