#ifndef TRANSPORTOBSERVER_H
#define TRANSPORTOBSERVER_H

#include "Observer.h"
#include "Road.h"
#include "TrainSystem.h"

class TransportObserver : public Observer {
public:
    TransportObserver(Road& road, TrainSystem& train);
    void update() override;
    double getTransportSatisfaction() const;
    double getTransportProductivity() const;
private:
    Road& road_;
    TrainSystem& train_;
    double transportSatisfaction_;
    double transportProductivity_;
};

#endif
