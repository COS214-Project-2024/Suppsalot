#include "TransportationManager.h"
#include "TaxManager.h"
#include "BuildingsManager.h"
#include "CitizensManager.h"

// Include other section headers here if needed

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

// Function to format money
std::string formatMoney(double amount)
{
    std::ostringstream oss;
    if (amount < 1000.0)
    {
        oss << "$" << static_cast<long long>(amount);
    }
    else if (amount < 1000000.0)
    {
        double thousands = amount / 1000.0;
        oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
    }
    else
    {
        double millions = amount / 1000000.0;
        oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
    }
    return oss.str();
}

//int main()
//{
//    // Initialize city statistics
//    double cityBudget = 2000000.00;
//    double taxSatisfaction = 0.0;       // Initial tax satisfaction percentage
//    double transportSatisfaction = 0.0; // Initial transportation satisfaction percentage
//    double citizenSatisfaction = 0.0;
//    double productivity = 0.0;        // Productivity influenced by transportation
//    double overallSatisfaction = 0.0; // Will be calculated
//
//    // Initialize Managers
//    TransportationManager transportationManager(cityBudget, transportSatisfaction, productivity);
//    TaxManager taxManager(cityBudget, taxSatisfaction);
//    BuildingsManager buildingsManager(cityBudget); // Initialize BuildingsManager with cityBudget
//    CitizensManager citizensManager;
//
//    bool running = true;
//    while (running)
//    {
//        std::cout << "============================\n";
//        std::cout << "City Simulation Main Menu\n";
//        std::cout << "============================\n";
//        std::cout << "Choose an action:\n";
//        std::cout << "1. Manage Transport\n";
//        std::cout << "2. Manage Tax\n";
//        std::cout << "3. Manage Buildings\n"; // Changed from "Manage Buildings" to include BuildingsManager
//        std::cout << "4. Manage Citizens\n";
//        std::cout << "5. Manage Government\n";
//        std::cout << "6. View Resources\n";
//        std::cout << "7. View Statistics\n";
//        std::cout << "8. Progress Year\n";
//        std::cout << "9. Quit\n";
//        std::cout << "Enter your choice: ";
//
//        int choice;
//        std::cin >> choice;
//
//        // Check if input is invalid
//        if (std::cin.fail())
//        {
//            std::cin.clear();                                                   // Clear the error flag
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
//            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
//            continue; // Restart the loop
//        }
//
//        switch (choice)
//        {
//        case 1:
//            transportationManager.manageTransport();
//            break;
//        case 2:
//            taxManager.manageTax();
//            break;
//        case 3:
//            buildingsManager.manageBuildings();
//            break;
//        case 4:
//            citizensManager.manageCitizens();
//            break;
//        case 5:
//            std::cout << "Government Management is under construction.\n";
//            break;
//        case 6:
//            std::cout << "------------------------\n";
//            std::cout << "Resources for the city:\n";
//            std::cout << "Materials:\n";
//            std::cout << "   Remaining Wood: " << buildingsManager.getRemainingWood() << "\n";
//            std::cout << "   Remaining Steel: " << buildingsManager.getRemainingSteel() << "\n";
//            std::cout << "   Remaining Concrete: " << buildingsManager.getRemainingConcrete() << "\n";
//            std::cout << "Utilities:\n";
//            std::cout << "   Remaining Power: " << buildingsManager.getRemainingPower() << "\n";
//            std::cout << "   Remaining Water: " << buildingsManager.getRemainingWater() << "\n";
//            std::cout << "------------------------\n\n";
//            break;
//        case 7:
//            std::cout << "============================\n";
//            std::cout << "City Statistics:\n";
//            std::cout << "============================\n";
//            std::cout << "Satisfaction: " << std::fixed << std::setprecision(1)
//                      << (0.3 * taxSatisfaction + 0.3 * transportSatisfaction + 0.4 * citizenSatisfaction) << "%\n";
//            std::cout << "\tTax Satisfaction: " << std::fixed << std::setprecision(1)
//                      << taxSatisfaction << "%\n";
//            std::cout << "\tTransport Satisfaction: " << std::fixed << std::setprecision(1)
//                      << transportSatisfaction << "%\n";
//            std::cout << "\tCitizen Satisfaction: " << std::fixed << std::setprecision(1)
//                      << citizenSatisfaction << "%\n";
//            std::cout << "Productivity: " << std::fixed << std::setprecision(1)
//                      << productivity << "%\n";
//            std::cout << "City Budget: " << formatMoney(cityBudget) << "\n";
//            std::cout << "============================\n\n";
//            break;
//            break;
//        case 8:
//            std::cout << "Progressing to the next year...\n\n";
//            transportationManager.progressYear();
//            taxManager.progressYear();
//            buildingsManager.progressYear();
//            citizensManager.progressYear();
//            citizenSatisfaction = citizensManager.getAverageSatisfaction();
//            overallSatisfaction = 0.3 * taxSatisfaction + 0.3 * transportSatisfaction + 0.4 * citizenSatisfaction;
//            std::cout << "Overall Satisfaction for the city: " << std::fixed << std::setprecision(1)
//                      << overallSatisfaction << "%\n\n";
//            break;
//        case 9:
//            std::cout << "Exiting simulation.\n";
//            running = false;
//            break;
//        default:
//            std::cout << "Invalid choice. Please try again.\n";
//            break;
//        }
//    }
//    return 0;
//}
