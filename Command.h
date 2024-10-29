#ifndef COMMAND_H
#define COMMAND_H


class Command{
    public:
        void execute();
        Command();
        ~Command();
};

class PowerShortageCommand:public Command{
    private:
        // PowerManager* power;
} ;
#endif