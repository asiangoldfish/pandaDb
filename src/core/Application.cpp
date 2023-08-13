#include "Application.h"

#include "config.hpp"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"
#include "util/util.h"
#include <memory>

#include "commands/cmd_header.h"

Application::Application()
  : appShouldClose(false)
{
}

Application::~Application()
{
    delete db;
    db = nullptr;
}

bool
Application::init()
{
    if (!db->initDatabase(conf::databaseDirPath())) {
        return false;
    }

    db = new PandaDB();
    registerCommands();

    return true;
}

void
Application::run()
{
    std::cout << "Welcome to PandaDB!\nEnter \'help\' command for commands.\n"
              << std::endl;

    while (!appShouldClose) {
        std::cout << "Command: ";

        std::string command;
        std::getline(std::cin, command);

        handleCommand(command);
    }
}

void
Application::handleCommand(std::string& commandStr)
{
    if (commandStr == "quit") {
        appShouldClose = true;
        return;
    }

    std::istringstream iss(commandStr);
    std::string commandName;
    iss >> commandName;

    std::vector<std::string> args;
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }

    // One word command
    auto it = commands.find(commandName);
    if (it != commands.end()) {
        if (it->first == "quit") {
            appShouldClose = true;
        } else {
            it->second->execute(args, *db);
        }
    } else {
        // Combine only the first argument with the command name
        std::string combinedCommand = commandName;
        if (!args.empty()) {
            combinedCommand += " " + args[0];
        }

        it = commands.find(combinedCommand);
        if (it != commands.end()) {
            args.erase(args.begin());       // Remove the first argument
            it->second->execute(args, *db); // Pass the remaining arguments
        } else {
            std::cout << "Unrecognized command" << std::endl;
        }
    }
}

void
Application::registerCommands()
{
    // Insert commands here
    commands["help"] = std::make_unique<cmd::Help>();
    commands["h"] = std::make_unique<cmd::Help>();

    commands["show files"] = std::make_unique<cmd::ShowFiles>();
    commands["ls"] = std::make_unique<cmd::ShowFiles>();

    commands["select file"] = std::make_unique<cmd::SelectFile>();

    commands["show data"] = std::make_unique<cmd::ShowData>();
    commands["cat"] = std::make_unique<cmd::ShowData>();

    commands["create file"] = std::make_unique<cmd::CreateFile>();
    commands["touch"] = std::make_unique<cmd::CreateFile>();

    commands["delete file"] = std::make_unique<cmd::DeleteFile>();
    commands["rm"] = std::make_unique<cmd::DeleteFile>();

    commands["create entry"] = std::make_unique<cmd::CreateEntry>();
}
