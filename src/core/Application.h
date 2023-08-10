#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "header.hpp"

class PandaDB;

class Application
{
public:
    Application();
    virtual ~Application() = default;

    bool init();
    void run();

    // Commands
    void printMenu();
    void printCommands();
    void printPrompt();

private:
    void constructCommand(std::string command, std::string description);

private:
    bool appShouldClose;
    PandaDB *db;
};

#endif