#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include <map>
#include "Command.h"

class CommandInvoker{
    private:
        bool woodShortage;
        bool steelShortage;
        bool concreteShortage;
        bool powerShortage;
        bool waterShortage;
        std::map<std::string, Command*> commandMap;
    public:
        CommandInvoker();
        ~CommandInvoker();
        void update(std::string& resourceType);
        void setCommand(std::string& recourceType , Command* c);
        void update();
        void executeCommand(std::string shortageType);
};

#endif
