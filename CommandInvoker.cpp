#include "CommandInvoker.h"
#include <cmath>
#include <iostream>

CommandInvoker::CommandInvoker(){
    woodShortage = false;
    steelShortage = false;
    concreteShortage = false;
    powerShortage = false;
    waterShortage = false;
};


CommandInvoker::~CommandInvoker(){
    // Clean up commands
    for (auto& pair : commandMap) {
        delete pair.second;
    }
};

void CommandInvoker::update(const std::string& resourceType){
    if (resourceType == "wood") {
        woodShortage = true;
    } else if (resourceType == "steel") {
        steelShortage = true;
    } else if (resourceType == "concrete") {
        concreteShortage = true;
    } else if (resourceType == "power") {
        powerShortage = true;
    } else if (resourceType == "water") {
        waterShortage = true;
    }
    executeCommand(resourceType);
};

void CommandInvoker::setCommand(const std::string& resourceType, Command* command) {
    commandMap[resourceType] = command;
}

void CommandInvoker::executeCommand(const std::string& shortageType) {
    if(commandMap.count(shortageType)){
        commandMap[shortageType]->execute();
    }else{
        std::cout << "No command set for the following shortage.\n";
    }
};


void CommandInvoker::checkShortages() {
    if (woodShortage) executeCommand("wood");
    if (steelShortage) executeCommand("steel");
    if (concreteShortage) executeCommand("concrete");
    if (powerShortage) executeCommand("power");
    if (waterShortage) executeCommand("water");

    // Reset shortages after handling
    woodShortage = steelShortage = concreteShortage = powerShortage = waterShortage = false;
}; 





