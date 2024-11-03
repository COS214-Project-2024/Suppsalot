#include "TransportObserver.h"

/**
 * @file TransportObserver.cpp
 * @brief Implements the TransportObserver class which monitors and calculates transport satisfaction and productivity based on road and train systems.
 */

/**
 * @class TransportObserver
 * @brief Observes and calculates combined transport metrics for road and train systems.
 * 
 * The TransportObserver calculates a weighted transport satisfaction score and combined transport productivity,
 * based on the individual metrics from the road and train systems.
 */

/**
 * @brief Constructs a TransportObserver with references to Road and TrainSystem objects.
 * @param road Reference to the Road object.
 * @param train Reference to the TrainSystem object.
 */
TransportObserver::TransportObserver(Road& road, TrainSystem& train)
    : road_(road), train_(train), transportSatisfaction_(0.0), transportProductivity_(0.0)
{}

/**
 * @brief Updates the transport satisfaction and productivity metrics.
 * 
 * Calculates transport satisfaction as a weighted average of road and train satisfaction,
 * and transport productivity as the product of road and train productivity.
 */
void TransportObserver::update() {
    transportSatisfaction_ = 0.6 * road_.getSatisfaction() + 0.4 * train_.getSatisfaction();
    transportProductivity_ = road_.getProductivity() * train_.getProductivity();
}

/**
 * @brief Gets the current transport satisfaction metric.
 * @return The transport satisfaction value.
 */
double TransportObserver::getTransportSatisfaction() const {
    return transportSatisfaction_;
}

/**
 * @brief Gets the current transport productivity metric.
 * @return The transport productivity value.
 */
double TransportObserver::getTransportProductivity() const {
    return transportProductivity_;
}
