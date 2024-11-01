#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "CityStats.h"
#include "StatsMemento.h"
#include "CityGrowthOg.h"
#include "StatsCaretaker.h"

void displayStatistics(const CityStats& s) {
    std::cout << "Population: " << s.population << "\n"
              << "Housing Needs: " << s.housingNeeds << "\n"
              << "Citizen Satisfaction: " << s.citizenSatisfaction << "\n"
              << "Hygiene: " << s.hygiene << "\n"
              << "Productivity: " << s.productivity << "\n"
              << "Employment Rate: " << s.employmentRate << "%\n";
}

void displayPercentageChange(const CityStats& prev, const CityStats& current) {
    auto percentChange = [&](int prevVal, int currVal) -> double {
        if(prevVal == 0) return 0.0;
        return ((double)(currVal - prevVal) / prevVal) * 100.0;
    };
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Population Change: " << percentChange(prev.population, current.population) << "%\n"
              << "Housing Needs Change: " << percentChange(prev.housingNeeds, current.housingNeeds) << "%\n"
              << "Citizen Satisfaction Change: " << percentChange(prev.citizenSatisfaction, current.citizenSatisfaction) << "%\n"
              << "Hygiene Change: " << percentChange(prev.hygiene, current.hygiene) << "%\n"
              << "Productivity Change: " << percentChange(prev.productivity, current.productivity) << "%\n"
              << "Employment Rate Change: " << percentChange(prev.employmentRate, current.employmentRate) << "%\n";
}

int main() {
    CityGrowthOg originator;
    StatsCaretaker caretaker;
    int year = 1;
    while(true){
        std::cout << "Year " << year << " - Enter statistics:\n";
        CityStats current;
        std::cout << "Population: ";
        std::cin >> current.population;
        std::cout << "Housing Needs: ";
        std::cin >> current.housingNeeds;
        std::cout << "Citizen Satisfaction: ";
        std::cin >> current.citizenSatisfaction;
        std::cout << "Hygiene: ";
        std::cin >> current.hygiene;
        std::cout << "Productivity: ";
        std::cin >> current.productivity;
        std::cout << "Employment Rate (%): ";
        std::cin >> current.employmentRate;
        originator.setState(current);
        caretaker.addMemento(originator.saveStateToMemento());
        if(year > 1){
            CityStats prev = caretaker.getMemento(year-2)->getState();
            displayPercentageChange(prev, current);
        }
        std::cout << "Options:\n1. Progress to next year\n2. View previous year's statistics\n3. Exit\nChoose an option: ";
        int option;
        std::cin >> option;
        if(option == 1){
            year++;
            continue;
        }
        else if(option == 2){
            if(year == 1){
                std::cout << "No previous year data.\n";
            }
            else{
                CityStats prev = caretaker.getMemento(year-2)->getState();
                std::cout << "Year " << year-1 << " Statistics:\n";
                displayStatistics(prev);
            }
        }
        else if(option == 3){
            std::cout << "All Years Statistics:\n";
            for(int i=0;i<caretaker.getSize();i++){
                CityStats s = caretaker.getMemento(i)->getState();
                std::cout << "Year " << i+1 << ":\n";
                displayStatistics(s);
            }
            break;
        }
        else{
            std::cout << "Invalid option.\n";
        }
    }
}
