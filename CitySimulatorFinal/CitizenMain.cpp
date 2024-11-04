#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "HighClassCitizen.h"
#include "MidClassCitizen.h"
#include "LowClassCitizen.h"
#include "CitizenStatistics.h"
#include "ResourceManager.h"
#include "ResourceObserver.h"
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<PrototypeCitizen *> citizens;
    bool running = true;
    float totalSatisfaction = 0.0;
    while (running)
    {
        int choice;
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Create High Class Citizens\n";
        std::cout << "2. Create Mid Class Citizens\n";
        std::cout << "3. Create Low Class Citizens\n";
        std::cout << "4. Toggle Employment Status\n";
        std::cout << "5. Display Citizen Info & Average Satisfaction\n";
        std::cout << "6. Kill Citizens\n";
        std::cout << "7. Progress year\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            std::cout << "Enter the number of High Class Citizens to create: ";
            std::cin >> num;
            for (int i = 0; i < num; ++i)
            {
                PrototypeCitizen *highCitizen = new HighClassCitizen();
                citizens.push_back(highCitizen);
                totalSatisfaction += highCitizen->getSatisfaction();
            }
            std::cout << num << " High Class Citizens created.\n";
            break;
        }
        case 2:
        {
            int num;
            std::cout << "Enter the number of Mid Class Citizens to create: ";
            std::cin >> num;
            for (int i = 0; i < num; ++i)
            {
                PrototypeCitizen *midCitizen = new MidClassCitizen();
                citizens.push_back(midCitizen);
                totalSatisfaction += midCitizen->getSatisfaction();
            }
            std::cout << num << " Mid Class Citizens created.\n";
            break;
        }
        case 3:
        {
            int num;
            std::cout << "Enter the number of Low Class Citizens to create: ";
            std::cin >> num;
            for (int i = 0; i < num; ++i)
            {
                PrototypeCitizen *lowCitizen = new LowClassCitizen();
                citizens.push_back(lowCitizen);
                totalSatisfaction += lowCitizen->getSatisfaction();
            }
            std::cout << num << " Low Class Citizens created.\n";
            break;
        }
        case 4:
        {
            int employmentChoice;
            std::cout << "Choose Citizen Class to Toggle Employment Status:\n";
            std::cout << "1. High Class\n";
            std::cout << "2. Mid Class\n";
            std::cout << "3. Low Class\n";
            std::cout << "Enter your choice: ";
            std::cin >> employmentChoice;
            for (PrototypeCitizen *citizen : citizens)
            {
                if ((employmentChoice == 1 && dynamic_cast<HighClassCitizen *>(citizen)) ||
                    (employmentChoice == 2 && dynamic_cast<MidClassCitizen *>(citizen)) ||
                    (employmentChoice == 3 && dynamic_cast<LowClassCitizen *>(citizen)))
                {
                    citizen->toggleEmployment();
                    std::cout << "Employment status toggled for a citizen of chosen class.\n";
                }
            }
            break;
        }
        case 5:
        {
            float avgSatisfaction = citizens.empty() ? 0.0 : totalSatisfaction / citizens.size();
            std::cout << "\n--- Citizen Information ---\n";
            for (PrototypeCitizen *citizen : citizens)
            {
                citizen->displayInfo();
            }

            // Display total count and counts per class
            std::cout << "\nTotal Citizens: " << citizens.size();
            std::cout << "\nHigh Class Citizens: " << HighClassCitizen::getHighClassCount();
            std::cout << "\nMid Class Citizens: " << MidClassCitizen::getMidClassCount();
            std::cout << "\nLow Class Citizens: " << LowClassCitizen::getLowClassCount();
            std::cout << "\nTotal Employed Citizens " << CitizenStatistics::totalEmployed(citizens) << "\n";

            std::cout << "\nAverage Satisfaction: " << avgSatisfaction << "\n";
            break;
        }
        case 6:
        {
            int numToKill;
            std::cout << "Enter the number of citizens to kill: ";
            std::cin >> numToKill;

            if (numToKill > static_cast<int>(citizens.size()))
            {
                std::cout << "Not enough citizens to kill. Currently, there are only " << citizens.size() << " citizens.\n";
                break;
            }

            for (int i = 0; i < numToKill; ++i)
            {
                int index = std::rand() % citizens.size();
                totalSatisfaction -= citizens[index]->getSatisfaction();
                delete citizens[index];
                citizens.erase(citizens.begin() + index);
            }

            std::cout << numToKill << " citizens have been killed.\n";
            break;
        }
        case 7:
        {
            BuildingStatistics::YearCitizenConsumer(citizens.size());
        }
        case 8:
        {
            running = false;
            std::cout << "Citizen Test Ended.\n";
            std::cout << "Exiting program.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    for (PrototypeCitizen *citizen : citizens)
    {
        delete citizen;
    }

    return 0;
}
