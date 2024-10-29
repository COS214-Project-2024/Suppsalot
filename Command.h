#ifndef COMMAND_H
#define COMMAND_H

#include "ResourceManager.h"


class Command {
public:
    // i dont think there is a need for a constructor
    virtual ~Command() = default;
    virtual void execute() = 0; 
};

class EmergencyRefillCommand : public Command {
    WaterManager* waterManager;
public:
    EmergencyRefillCommand(WaterManager* wm) : waterManager(wm) {}
    void execute() override {
        waterManager->EmergencyRefill();
    }
};

class EnterDroughtCommand : public Command {
    WaterManager* waterManager;
public:
    EnterDroughtCommand(WaterManager* wm) : waterManager(wm) {}
    void execute() override {
        waterManager->enterDraught();
    }
};

class SwitchToNuclearCommand : public Command {
    PowerManager* powerManager;
public:
    SwitchToNuclearCommand(PowerManager* pm) : powerManager(pm) {}
    void execute() override {
        powerManager->switchToNuclear();
    }
};

class EndWorldCommand : public Command {
    PowerManager* powerManager;
public:
    EndWorldCommand(PowerManager* pm) : powerManager(pm) {}
    void execute() override {
        powerManager->endWorld();
    }
};

#endif