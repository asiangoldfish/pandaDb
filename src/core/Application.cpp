#include "Application.h"

#include "core/PandaDB.h"
#include "config.h"

Application::Application()
    : appShouldClose(false)
{
    db = new PandaDB();
}

bool Application::init()
{
    if (!db->initDatabase(conf::databaseDirPath()))
    {
        return false;
    }

    return true;
}

void Application::run()
{
    while (!appShouldClose)
    {
        printCommands();
        std::string a;
        getline(std::cin, a);
    }
}

void Application::printMenu()
{
}

void Application::printCommands()
{
    constructCommand("print", "Print all commands");
    constructCommand("quit" , "Quit this application");
}

void Application::printPrompt()
{
    std::cout << "Command: ";
}

void Application::constructCommand(std::string command, std::string description)
{
    std::cout << command << "\t\t" << description << std::endl;
}
