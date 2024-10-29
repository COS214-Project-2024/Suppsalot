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
        void update(const std::string& resourceType);
        void setCommand(const std::string& recourceType , Command* c);
        void executeCommand(const std::string& shortageType);
        void checkShortages();
    };

#endif
