// CitizensManager.cpp
#include "CitizensManager.h"

// Constructor
CitizensManager::CitizensManager() : totalSatisfaction(0.0f)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Destructor
CitizensManager::~CitizensManager()
{
    // No manual deletion needed due to smart pointers
}

// Helper function to get validated user choice
int CitizensManager::getValidatedChoice(int min, int max)
{
    int choice;
    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail() || choice < min || choice > max)
        {
            std::cin.clear();                                                   // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard remaining input
            return choice;
        }
    }
}

float CitizensManager::getAverageSatisfaction() const {
    return citizens.empty() ? 0.0f : totalSatisfaction / citizens.size();
}

// Manage Citizens
void CitizensManager::manageCitizens()
{
    bool running = true;
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
        std::cout << "7. Exit to Main Menu\n";
        std::cout << "Enter your choice: ";
        choice = getValidatedChoice(1, 7);

        switch (choice)
        {
        case 1:
        { // Create High Class Citizens
            int num;
            std::cout << "Enter the number of High Class Citizens to create: ";
            std::cin >> num;
            if (std::cin.fail() || num < 1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid number. Please enter a positive integer.\n";
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 0; i < num; ++i)
            {
                std::unique_ptr<PrototypeCitizen> highCitizen = std::make_unique<HighClassCitizen>();
                totalSatisfaction += highCitizen->getSatisfaction();
                citizens.push_back(std::move(highCitizen));
            }
            std::cout << num << " High Class Citizens created.\n";
            break;
        }
        case 2:
        { // Create Mid Class Citizens
            int num;
            std::cout << "Enter the number of Mid Class Citizens to create: ";
            std::cin >> num;
            if (std::cin.fail() || num < 1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid number. Please enter a positive integer.\n";
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 0; i < num; ++i)
            {
                std::unique_ptr<PrototypeCitizen> midCitizen = std::make_unique<MidClassCitizen>();
                totalSatisfaction += midCitizen->getSatisfaction();
                citizens.push_back(std::move(midCitizen));
            }
            std::cout << num << " Mid Class Citizens created.\n";
            break;
        }
        case 3:
        { // Create Low Class Citizens
            int num;
            std::cout << "Enter the number of Low Class Citizens to create: ";
            std::cin >> num;
            if (std::cin.fail() || num < 1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid number. Please enter a positive integer.\n";
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 0; i < num; ++i)
            {
                std::unique_ptr<PrototypeCitizen> lowCitizen = std::make_unique<LowClassCitizen>();
                totalSatisfaction += lowCitizen->getSatisfaction();
                citizens.push_back(std::move(lowCitizen));
            }
            std::cout << num << " Low Class Citizens created.\n";
            break;
        }
        case 4:
        { // Toggle Employment Status
            int employmentChoice;
            std::cout << "Choose Citizen Class to Toggle Employment Status:\n";
            std::cout << "1. High Class\n";
            std::cout << "2. Mid Class\n";
            std::cout << "3. Low Class\n";
            std::cout << "Enter your choice: ";
            employmentChoice = getValidatedChoice(1, 3);

            bool anyToggled = false;
            for (auto &citizen : citizens)
            {
                if ((employmentChoice == 1 && dynamic_cast<HighClassCitizen *>(citizen.get())) ||
                    (employmentChoice == 2 && dynamic_cast<MidClassCitizen *>(citizen.get())) ||
                    (employmentChoice == 3 && dynamic_cast<LowClassCitizen *>(citizen.get())))
                {
                    citizen->toggleEmployment();
                    anyToggled = true;
                }
            }
            if (anyToggled)
                std::cout << "Employment status toggled for citizens of chosen class.\n";
            else
                std::cout << "No citizens of the chosen class to toggle.\n";
            break;
        }
        case 5:
        { // Display Citizen Info & Average Satisfaction
            std::cout << "\n--- Citizen Information ---\n";
                for (const auto& citizen : citizens) {
                    citizen->displayInfo();
                }

                // Display total count and counts per class
                std::cout << "\nTotal Citizens: " << citizens.size();
                std::cout << "\nHigh Class Citizens: " << HighClassCitizen::getHighClassCount();
                std::cout << "\nMid Class Citizens: " << MidClassCitizen::getMidClassCount();
                std::cout << "\nLow Class Citizens: " << LowClassCitizen::getLowClassCount();
                std::cout << "\nTotal Employed Citizens: ";

                // Convert unique_ptr vector to raw pointer vector
                std::vector<PrototypeCitizen*> rawCitizens;
                rawCitizens.reserve(citizens.size());
                for (const auto& citizen : citizens) {
                    rawCitizens.push_back(citizen.get());
                }

                std::cout << CitizenStatistics::totalEmployed(rawCitizens) << "\n";

                float avgSatisfaction = citizens.empty() ? 0.0f : totalSatisfaction / citizens.size();
                std::cout << "\nAverage Satisfaction: " << avgSatisfaction << "\n";
                break;
        }
        case 6:
        { // Kill Citizens
            int numToKill;
            std::cout << "Enter the number of citizens to kill: ";
            std::cin >> numToKill;
            if (std::cin.fail() || numToKill < 1)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid number. Please enter a positive integer.\n";
                break;
            }
            if (numToKill > static_cast<int>(citizens.size()))
            {
                std::cout << "Not enough citizens to kill. Currently, there are only " << citizens.size() << " citizens.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for (int i = 0; i < numToKill; ++i)
            {
                int index = std::rand() % citizens.size();
                totalSatisfaction -= citizens[index]->getSatisfaction();
                citizens.erase(citizens.begin() + index); // unique_ptr handles deletion
            }
            std::cout << numToKill << " citizens have been killed.\n";
            break;
        }
        case 7:
        { // Exit to Main Menu
            running = false;
            std::cout << "Exiting Citizens Management.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Progress Year
void CitizensManager::progressYear()
{
    BuildingStatistics::YearCitizenConsumer(citizens.size());
    std::cout << "Citizens have been updated for the year.\n";
}
