#include <iostream>
#include <vector>
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include "CitizenCollection.h"
#include "CitizenIterator.h"

int main() {
    CitizenCollection citizenCollection;
    char continueChoice = 'y';

    while (continueChoice == 'y' || continueChoice == 'Y') {
        int citizenType;
        std::cout << "Choose the type of citizen to create:\n";
        std::cout << "1. High Class Citizen\n";
        std::cout << "2. Mid Class Citizen\n";
        std::cout << "3. Low Class Citizen\n";
        std::cout << "Enter choice: ";
        std::cin >> citizenType;

        PrototypeCitizen* newCitizen = nullptr;

        switch (citizenType) {
            case 1:
                newCitizen = new HighClassCitizen();
                break;
            case 2:
                newCitizen = new MidClassCitizen();
                break;
            case 3:
                newCitizen = new LowClassCitizen();
                break;
            default:
                std::cout << "Invalid choice. Please select a valid citizen type.\n";
                continue;
        }

        int numClones;
        std::cout << "Enter the number of clones to create for this citizen: ";
        std::cin >> numClones;

        for (int i = 0; i < numClones; ++i) {
            PrototypeCitizen* cloneCitizen = newCitizen->clone();
            citizenCollection.addCitizen(cloneCitizen);
        }
        CitizenIterator iterator = citizenCollection.createIterator();
        float totalSatisfaction = 0.0;
        int citizenCount = 0;

        std::cout << "\nCitizens in collection:\n";
        while (iterator.hasNext()) {
            PrototypeCitizen* citizen = iterator.next();
            citizen->displayInfo();
            totalSatisfaction += citizen->getSatisfaction();
            citizenCount++;
        }
        if (citizenCount > 0) {
            std::cout << "\nTotal citizens created: " << citizenCount << "\n";
            std::cout << "Average satisfaction: " << (totalSatisfaction / citizenCount) << "\n";
        } else {
            std::cout << "No citizens created yet.\n";
        }
        std::cout << "\nWould you like to create more citizens? (y/n): ";
        std::cin >> continueChoice;
        delete newCitizen;
    }

    std::cout << "Citizen Duplication and count ended.\n";
    return 0;
}
