#ifndef CITYSTATS_H
#define CITYSTATS_H

class CityStats {
public:
    int population;
    int housingNeeds;
    int citizenSatisfaction;
    int hygiene;
    int productivity;
    int employmentRate;

    CityStats(int pop = 0, int housing = 0, int satisfaction = 0, int hyge = 0, int prod = 0, int employment = 0);
};

#endif
