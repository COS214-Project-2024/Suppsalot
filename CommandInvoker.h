// #ifndef COMMANDINVOKER_H
// #define COMMANDINVOKER_H

// #include <map>
// #include "Command.h"

// class CommandInvoker{
//     private:
//         bool woodShortage;
//         bool steelShortage;
//         bool concreteShortage;
//         bool powerShortage;
//         bool waterShortage;
//         std::map<std::string, Command*> commandMap;
//     public:
//         CommandInvoker();
//         ~CommandInvoker();
//         void update(const std::string& resourceType);
//         void setCommand(const std::string& recourceType , Command* c);
//         void executeCommand(const std::string& shortageType);
//         void checkShortages();
//     };

// #endif

// new plan!
#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include <unordered_map> // apparently faster lookup times
#include "Command.h"

class CommandInvoker{
    private:
        std::unordered_map<std::string, Command*> commands;
    public:
        void addCommand(const std::string& commandName, Command* command);
        void update(const std::string& commandName);
        ~CommandInvoker();
};

#endif
