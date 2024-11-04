#ifndef TRANSPORTATIONMANAGER_H
#define TRANSPORTATIONMANAGER_H

#include "Road.h"
#include "NotOperational.h"
#include "Bad.h"
#include "Okay.h"
#include "Good.h"
#include "Excellent.h"
#include "TrainSystem.h"
#include "Star1.h"
#include "Star2.h"
#include "Star3.h"
#include "Star4.h"
#include "Star5.h"
#include "PublicTransit.h" 
#include "TransportObserver.h"
#include "BuildingStatistics.h"
#include "ResourceManager.h"
#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
#include <sstream>

class TransportationManager {
public:
    TransportationManager(double& cityBudget, double& satisfaction, double& productivity)
        : budget(cityBudget), citySatisfaction(satisfaction), cityProductivity(productivity),
          road(cityBudget), train(cityBudget), transit(cityBudget),
          observer(road, train, transit) {
        road.attach(&observer);
        train.attach(&observer);
        transit.attach(&observer);
    }

    void manageTransport() {
        bool running = true;
        while (running) {
            std::cout << "============================\n";
            std::cout << "Transportation Management Menu\n";
            std::cout << "============================\n";
            std::cout << "Choose an action:\n";
            std::cout << "1. Manage Road\n";
            std::cout << "2. Manage Train\n";
            std::cout << "3. Manage Public Transit\n";
            std::cout << "4. Back to Main Menu\n";
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    roadM();
                    break;
                case 2:
                    trainM();
                    break;
                case 3:
                    publicTransitM();
                    break;
                case 4:
                    std::cout << "Returning to Main Menu.\n";
                    running = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\n";
        }
    }

    void progressYear() {
        std::cout << "Progressing to the next year in Transportation Sector...\n\n";

        road.progressYear();
        train.progressYear();
        transit.progressYear();

        observer.update();

        cityProductivity = observer.getTransportProductivity() * 100.0;

        citySatisfaction = observer.getTransportSatisfaction();

        //maybe we can add a maintanance cost which is deducted each year
        // double totalMaintenance = 0.0;
        // totalMaintenance += road.getMaintenanceCost();
        // totalMaintenance += train.getMaintenanceCost();
        // totalMaintenance += transit.getMaintenanceCost();

        // Deduct total maintenance costs from city budget
        // budget -= totalMaintenance;

        // std::cout << "Year progressed successfully.\n";
        // std::cout << "Total Maintenance Costs: " << formatMoney(totalMaintenance) << "\n";
        // std::cout << "Remaining City Budget: " << formatMoney(budget) << "\n\n";

        //could add some more functionality here
    }

    double getTransProductivity(){
        return observer.getTransportProductivity() * 100;
    }

private:
    double& budget;
    double& citySatisfaction;
    double& cityProductivity;

    Road road;
    TrainSystem train;
    PublicTransit transit;
    TransportObserver observer;

    std::string formatMoney(double amount) {
        std::ostringstream oss;
        if (amount < 1000.0) {
            oss << "$" << static_cast<long long>(amount);
        }
        else if (amount < 1000000.0) {
            double thousands = amount / 1000.0;
            oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
        }
        else {
            double millions = amount / 1000000.0;
            oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
        }
        return oss.str();
    }

    void trainM() {
        BuildingStatistics stats;
        bool runningT = true;
        while (runningT) {
            std::cout << "============================\n";
            std::cout << "Current Train System State: " << train.getCurrentStateName() << "\n";
            std::cout << "City Budget: " << formatMoney(budget) << "\n";
            std::cout << "Train Satisfaction: " << train.getSatisfaction() << "\n";
            std::cout << "============================\n";
            std::cout << "Choose an action:\n";
            std::cout << "1. Upgrade Train System\n";
            std::cout << "2. Exit Train Management\n";
            std::cout << "Enter your choice: ";
            int choiceT;
            std::cin >> choiceT;
            switch (choiceT) {
                case 1:
                    stats.useRoadResource("Train");
                    train.upgradeTrainSystem();
                    break;
                case 2:
                    std::cout << "Exiting Train Management.\n";
                    runningT = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\n";
        }
    }

    void roadM() {
        bool runningR = true;
        BuildingStatistics stat;
        while (runningR) {
            std::cout << "============================\n";
            std::cout << "Current Road State: " << road.getCurrentStateName() << "\n";
            std::cout << "City Budget: " << formatMoney(budget) << "\n";
            std::cout << "Road Satisfaction: " << road.getSatisfaction() << "\n";
            std::cout << "============================\n";

            std::cout << "Choose an action:\n";
            std::cout << "1. Upgrade Road\n";
            std::cout << "2. Exit Road Management\n";
            std::cout << "Enter your choice: ";

            int choiceR;
            std::cin >> choiceR;

            switch (choiceR) {
                case 1:
                    road.upgradeRoad();
                    stat.useRoadResource("Road");
                    break;
                case 2:
                    std::cout << "Exiting Road Management.\n";
                    runningR = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }

            std::cout << "\n";
        }
    }

    void publicTransitM() {
        bool runningP = true;
        while (runningP) {
            std::cout << "============================\n";
            std::cout << "Current Public Transit State: " << transit.getCurrentStateName() << "\n";
            std::cout << "City Budget: " << formatMoney(budget) << "\n";
            std::cout << "Public Transit Satisfaction: " << transit.getSatisfaction() << "\n";
            std::cout << "============================\n";
            std::cout << "Choose an action:\n";
            std::cout << "1. Buy Uber ($250k)\n";
            std::cout << "2. Buy Bolt ($150k)\n";
            std::cout << "3. Exit Public Transit Management\n";
            std::cout << "Enter your choice: ";
            int choiceP;
            std::cin >> choiceP;
            switch (choiceP) {
                case 1:
                    transit.buyUber();
                    break;
                case 2:
                    transit.buyBolt();
                    break;
                case 3:
                    std::cout << "Exiting Public Transit Management.\n";
                    runningP = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\n";
        }
    }
};

#endif 
