#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "header.hpp"
#include "commands/Command.h"

class PandaDB;

class Application
{
public:
    Application();
    virtual ~Application();

    bool init();
    void run();

private:
    void printMenu();
    void printPrompt(std::string msg);
    void handleCommand(std::string &commandStr);

    // Commands
    void printCommands();
    void showFiles();
    bool selectFile();
    void showData();

    void registerCommands();

private:
    bool appShouldClose;
    PandaDB *db;
    std::string selectedFile;
    std::string databasePath;

    std::unordered_map<std::string, std::unique_ptr<Command>> commands;
};

#endif