#include "CommandInvoker.h"

void CommandInvoker::addCommand(const std::string& commandName, Command* command){
    commands[commandName] = command;
}

void CommandInvoker::update(const std::string& commandName) {
    for (auto it = commands.begin(); it != commands.end(); ++it) {
        if (it->first == commandName) {
            it->second->execute();
            break;  // Exit the loop once the command is found and executed
        }
    }
}

CommandInvoker::~CommandInvoker() {
    for (auto& pair : commands) {
        delete pair.second;  
    }
    commands.clear();  // make sure this deallocates the memory createed in ResrouceManager
}
