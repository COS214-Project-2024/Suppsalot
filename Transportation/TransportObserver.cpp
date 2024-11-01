#include "TransportObserver.h"

TransportObserver::TransportObserver(Road& road, TrainSystem& train)
    : road_(road), train_(train), transportSatisfaction_(0.0), transportProductivity_(0.0)
{}

void TransportObserver::update() {
    transportSatisfaction_ = 0.6 * road_.getSatisfaction() + 0.4 * train_.getSatisfaction();
    transportProductivity_ = road_.getProductivity() * train_.getProductivity();
}

double TransportObserver::getTransportSatisfaction() const {
    return transportSatisfaction_;
}

double TransportObserver::getTransportProductivity() const {
    return transportProductivity_;
}
