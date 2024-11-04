// #include "TransportationManager.h"
// #include "TaxManager.h"
// //include other section headers here (e.g., BuildingManager.h, UtilitiesManager.h, etc.)
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <sstream>

// std::string formatMoney(double amount) {
//     std::ostringstream oss;
//     if (amount < 1000.0) {
//         oss << "$" << static_cast<long long>(amount);
//     }
//     else if (amount < 1000000.0) {
//         double thousands = amount / 1000.0;
//         oss << "$" << std::fixed << std::setprecision(1) << thousands << "k";
//     }
//     else {
//         double millions = amount / 1000000.0;
//         oss << "$" << std::fixed << std::setprecision(1) << millions << "m";
//     }
//     return oss.str();
// }

// int main() {
//     // Initialize city statistics
//     double cityBudget = 2000000.00;
//     double taxSatisfaction = 0.0;
//     double transportSatisfaction = 0.0;
//     double productivity = 0.0;             //productivity influenced by transportation
//     double overallSatisfaction = 0.0;       //will be calculated

//     // Initialize Managers
//     TransportationManager transportationManager(cityBudget, transportSatisfaction, productivity);
//     TaxManager taxManager(cityBudget, taxSatisfaction);

//     // Placeholder for other managers (e.g., BuildingManager buildingManager(cityBudget, ...);)

//     bool running = true;
//     while (running){
//         std::cout << "============================\n";
//         std::cout << "City Simulation Main Menu\n";
//         std::cout << "============================\n";
//         std::cout << "Choose an action:\n";
//         std::cout << "1. Manage Transport\n";
//         std::cout << "2. Manage Tax\n";
//         std::cout << "3. Manage Buildings\n";
//         std::cout << "4. Manage Utilities\n";
//         std::cout << "5. Manage Citizens\n";
//         std::cout << "6. Manage Government\n";
//         std::cout << "7. View Resources\n";
//         std::cout << "8. View Statistics\n";
//         std::cout << "9. Progress Year\n";
//         std::cout << "10. Quit\n";
//         std::cout << "Enter your choice: ";

//         int choice;
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 transportationManager.manageTransport();
//                 break;
//             case 2:
//                 taxManager.manageTax();
//                 break;
//             case 3:
//                 // buildingManager.manageBuildings();
//                 std::cout << "Building Management is under construction.\n";
//                 break;
//             case 4:
//                 // utilitiesManager.manageUtilities();
//                 std::cout << "Utilities Management is under construction.\n";
//                 break;
//             case 5:
//                 // citizensManager.manageCitizens();
//                 std::cout << "Citizens Management is under construction.\n";
//                 break;
//             case 6:
//                 // governmentManager.manageGovernment();
//                 std::cout << "Government Management is under construction.\n";
//                 break;
//             case 7:
//                 // viewResources();
//                 std::cout << "View Resources is under construction.\n";
//                 break;
//             case 8:
//                 std::cout << "============================\n";
//                 std::cout << "City Statistics:\n";
//                 std::cout << "============================\n";
//                 std::cout << "Satisfaction: " << std::fixed << std::setprecision(1) 
//                         //   << overallSatisfaction << "%\n";
//                           << (0.5 * taxSatisfaction + 0.5 * transportSatisfaction) << "%\n";
//                 std::cout << "\tTax Satisfaction: " << std::fixed << std::setprecision(1) 
//                           << taxSatisfaction << "%\n";
//                 std::cout << "\tTransport Satisfaction: " << std::fixed << std::setprecision(1) 
//                           << transportSatisfaction << "%\n";
//                 std::cout << "Productivity: " << std::fixed << std::setprecision(1) 
//                           << productivity << "%\n"; 
//                 std::cout << "City Budget: " << formatMoney(cityBudget) << "\n";
//                 std::cout << "============================\n\n";
//                 break;
//             case 9:
//                 std::cout << "Progressing to the next year...\n\n";
//                 transportationManager.progressYear();
//                 taxManager.progressYear();
//                 // buildingManager.progressYear();
//                 // utilitiesManager.progressYear();
//                 // citizensManager.progressYear();
//                 // governmentManager.progressYear();

//                 // Calculate Overall Satisfaction
//                 overallSatisfaction = 0.5 * taxSatisfaction + 0.5 * transportSatisfaction;

//                 std::cout << "Overall Satisfaction for the city: " << std::fixed << std::setprecision(1)
//                           << overallSatisfaction << "%\n\n";
//                 break;
//             case 10:
//                 std::cout << "Exiting simulation.\n";
//                 running = false;
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please try again.\n";
//         }
//     }
//     return 0;
// }


// main.cpp
#include "TransportationManager.h"
#include "TaxManager.h"
#include "BuildingsManager.h" // Include the new BuildingsManager
// Include other section headers here if needed

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Function to format money
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

int main() {
    // Initialize city statistics
    double cityBudget = 2000000.00;
    double taxSatisfaction = 0.0;          // Initial tax satisfaction percentage
    double transportSatisfaction = 0.0;    // Initial transportation satisfaction percentage
    double productivity = 0.0;             // Productivity influenced by transportation
    double overallSatisfaction = 0.0;       // Will be calculated

    // Initialize Managers
    TransportationManager transportationManager(cityBudget, transportSatisfaction, productivity);
    TaxManager taxManager(cityBudget, taxSatisfaction);
    BuildingsManager buildingsManager(cityBudget); // Initialize BuildingsManager with cityBudget

    // Placeholder for other managers (e.g., BuildingManager buildingManager(cityBudget, ...);)

    bool running = true;
    while (running){
        std::cout << "============================\n";
        std::cout << "City Simulation Main Menu\n";
        std::cout << "============================\n";
        std::cout << "Choose an action:\n";
        std::cout << "1. Manage Transport\n";
        std::cout << "2. Manage Tax\n";
        std::cout << "3. Manage Buildings\n"; // Changed from "Manage Buildings" to include BuildingsManager
        // Removed "4. Manage Utilities" as it's now handled within BuildingsManager
        std::cout << "4. Manage Citizens\n";
        std::cout << "5. Manage Government\n";
        std::cout << "6. View Resources\n";
        std::cout << "7. View Statistics\n";
        std::cout << "8. Progress Year\n";
        std::cout << "9. Quit\n"; // Adjusted numbering due to removal of "Manage Utilities"
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                transportationManager.manageTransport();
                break;
            case 2:
                taxManager.manageTax();
                break;
            case 3:
                buildingsManager.manageBuildings(); // Handle Buildings Management
                break;
            case 4:
                // citizensManager.manageCitizens();
                std::cout << "Citizens Management is under construction.\n";
                break;
            case 5:
                // governmentManager.manageGovernment();
                std::cout << "Government Management is under construction.\n";
                break;
            case 6:
                // viewResources();
                std::cout << "View Resources is under construction.\n";
                break;
            case 7:
                // View Statistics
                std::cout << "============================\n";
                std::cout << "City Statistics:\n";
                std::cout << "============================\n";
                std::cout << "Satisfaction: " << std::fixed << std::setprecision(1) 
                          << (0.5 * taxSatisfaction + 0.5 * transportSatisfaction) << "%\n";
                std::cout << "\tTax Satisfaction: " << std::fixed << std::setprecision(1) 
                          << taxSatisfaction << "%\n";
                std::cout << "\tTransport Satisfaction: " << std::fixed << std::setprecision(1) 
                          << transportSatisfaction << "%\n";
                std::cout << "Productivity: " << std::fixed << std::setprecision(1) 
                          << productivity << "%\n"; 
                std::cout << "City Budget: " << formatMoney(cityBudget) << "\n";
                std::cout << "============================\n\n";
                break;
            case 8:
                std::cout << "Progressing to the next year...\n\n";
                // Progress Year for all managers
                transportationManager.progressYear();
                taxManager.progressYear();
                buildingsManager.progressYear(); // Progress Year for BuildingsManager
                // buildingManager.progressYear();
                // utilitiesManager.progressYear();
                // citizensManager.progressYear();
                // governmentManager.progressYear();

                // Calculate Overall Satisfaction
                overallSatisfaction = 0.5 * taxSatisfaction + 0.5 * transportSatisfaction;

                std::cout << "Overall Satisfaction for the city: " << std::fixed << std::setprecision(1)
                          << overallSatisfaction << "%\n\n";
                break;
            case 9:
                std::cout << "Exiting simulation.\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
