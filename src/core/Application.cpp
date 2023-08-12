#include "Application.h"

#include "commands/Command.h"
#include "core/PandaDB.h"
#include "config.h"
#include "header.hpp"
#include "util/util.h"
#include "core/Logger.h"
#include <memory>

Application::Application()
    : appShouldClose(false)
{
}

Application::~Application()
{
    delete db;
    db = nullptr;
}

bool Application::init()
{
    if (!db->initDatabase(conf::databaseDirPath()))
    {
        return false;
    }

    db = new PandaDB();
    registerCommands();

    return true;
}

void Application::run()
{
    std::cout << "Welcome to PandaDB!\nEnter \'help\' command for commands.\n" << std::endl;

    while (!appShouldClose)
    {
        std::cout << "Command: ";

        std::string command;
        std::getline(std::cin, command);

        handleCommand(command);
    }
}

void Application::handleCommand(std::string& commandStr)
{
    std::istringstream iss(commandStr);
    std::string commandName;
    iss >> commandName;

    std::vector<std::string> args;
    std::string arg;
    while (iss >> arg) 
    {
        args.push_back(arg);
    }

    auto it = commands.find(commandName);
    if (it != commands.end())
    {
        it->second->execute(args, *db);
    }
    else
    {
        // Combine only the first argument with the command name
        std::string combinedCommand = commandName;
        if (!args.empty())
        {
            combinedCommand += " " + args[0];
        }

        it = commands.find(combinedCommand);
        if (it != commands.end())
        {
            args.erase(args.begin()); // Remove the first argument
            it->second->execute(args, *db); // Pass the remaining arguments
        }
        else
        {
            std::cout << "Unrecognized command" << std::endl;
        }
    }
}

void Application::registerCommands()
{
    // Insert commands here
    commands["help"] = std::make_unique<HelpCommand>();
    commands["h"] = std::make_unique<HelpCommand>();

    //commands["quit"] = "Quit this application";

    commands["show files"] = std::make_unique<ShowFilesCommand>();
    commands["ls"] = std::make_unique<ShowFilesCommand>();

    commands["select file"] = std::make_unique<SelectFileCommand>();

    //commands["show data"] = "Display a selected file's data";
    
    commands["create file"] = std::make_unique<CreateFileCommand>();
    commands["touch"] = std::make_unique<CreateFileCommand>();

    commands["delete file"] = std::make_unique<DeleteFileCommand>();
    commands["rm"] = std::make_unique<DeleteFileCommand>();
}
