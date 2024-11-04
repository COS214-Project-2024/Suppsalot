#include "CityStats.h"

CityStats::CityStats(int pop, int housing, int satisfaction, int hyge, int prod, int employment)
    : population(pop), housingNeeds(housing), citizenSatisfaction(satisfaction),
      hygiene(hyge), productivity(prod), employmentRate(employment) {}
