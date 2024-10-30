// #ifndef COMMAND_H
// #define COMMAND_H

// #include "ResourceManager.h"



// class Command {
// public:
//     // i dont think there is a need for a constructor
//     virtual ~Command() = default;
//     virtual void execute() = 0; 
// };

// // class EmergencyRefillCommand : public Command {
// //     ResourceManager* rm;
// //     // WaterManager* waterManager;
// // public:
// //     EmergencyRefillCommand(){
// //         rm = new WaterManager();
// //     }
// //     void execute() override {
// //         dynamic_cast<WaterManager*>(rm)->EmergencyRefill();
// //     }
// // };

// // class EnterDroughtCommand : public Command {
// //     WaterManager* waterManager;
// // public:
// //     EnterDroughtCommand(WaterManager* wm) : waterManager(wm) {}
// //     void execute() override {
// //         waterManager->enterDraught();
// //     }
// // };

// // class SwitchToNuclearCommand : public Command {
// //     PowerManager* powerManager;
// // public:
// //     SwitchToNuclearCommand(PowerManager* pm) : powerManager(pm) {}
// //     void execute() override {
// //         powerManager->switchToNuclear();
// //     }
// // };

// // class EndWorldCommand : public Command {
// //     PowerManager* powerManager;
// // public:
// //     EndWorldCommand(PowerManager* pm) : powerManager(pm) {}
// //     void execute() override {
// //         powerManager->endWorld();
// //     }
// // };


// class EnterDroughtCommand : public Command {
//     ResourceManager* rm;  // Use ResourceManager pointer

// public:
//     EnterDroughtCommand() {
//         rm = new WaterManager();  // Dynamically allocate WaterManager
//     }

//     void execute() override {
//         auto waterManager = dynamic_cast<WaterManager*>(rm);
//         if (waterManager) {
//             waterManager->enterDraught();
//         } else {
//             std::cerr << "Failed to cast ResourceManager to WaterManager.\n";
//         }
//     }

//     ~EnterDroughtCommand() {
//         delete rm;  // Properly deallocate memory to avoid memory leaks
//     }
// };

// class SwitchToNuclearCommand : public Command {
//     ResourceManager* rm;  // Use ResourceManager pointer

// public:
//     SwitchToNuclearCommand() {
//         rm = new PowerManager();  // Dynamically allocate PowerManager
//     }

//     void execute() override {
//         auto powerManager = dynamic_cast<PowerManager*>(rm);
//         if (powerManager) {
//             powerManager->switchToNuclear();
//         } else {
//             std::cerr << "Failed to cast ResourceManager to PowerManager.\n";
//         }
//     }
// // 
//     ~SwitchToNuclearCommand() {
//         delete rm;  // Properly deallocate memory to avoid memory leaks
//     }
// };

// class EndWorldCommand : public Command {
//     ResourceManager* rm;  // Use ResourceManager pointer

// public:
//     EndWorldCommand() {
//         rm = new PowerManager();  // Dynamically allocate PowerManager
//     }

//     void execute() override {
//         auto powerManager = dynamic_cast<PowerManager*>(rm);
//         if (powerManager) {
//             powerManager->endWorld();
//         } else {
//             std::cerr << "Failed to cast ResourceManager to PowerManager.\n";
//         }
//     }

//     ~EndWorldCommand() {
//         delete rm;  // Properly deallocate memory to avoid memory leaks
//     }
// };


// #endif