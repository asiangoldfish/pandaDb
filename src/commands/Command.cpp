#include "commands/Command.h"

#include "header.hpp"
#include "core/Logger.h"
#include "Command.h"
#include "util/util.h"
#include "core/PandaDB.h"

HelpCommand::HelpCommand()
{
    commands["help"] = "Print all commands";
    commands["quit"] = "Quit this application";
    commands["show files"] = "Show all files";
    commands["select file"] = "Select a file. Its data can then be displayed.";
    commands["show data"] = "Display a selected file's data";
    commands["create file"] = "Create a new file";
}

void HelpCommand::printCommands()
{
    std::cout << std::endl;

    for (auto command : commands)
    {
        constructCommand(command.first, command.second);
    }
}
void HelpCommand::constructCommand(std::string command, std::string description)
{
    std::cout << command << "\t\t" << description << std::endl;
}

void ShowFilesCommand::showAllFiles()
{
    bool fileExists = false;

    for (const auto & entry : std::filesystem::directory_iterator(conf::databaseDirPath()))
    {
        fileExists = true;
        std::cout << entry.path().filename().string() << std::endl;
    }

    if (!fileExists)
    {
        Logger::info("No files exist");
    }
}
void SelectFileCommand::selectFile(std::string filename, PandaDB &db)
{
    if (util::fileExists(filename))
    {
        db.setSelectedFile(filename);
    }
    else
    {
        Logger::info("File does not exist");
    }
}

void CreateFileCommand::createFile(std::string filename, PandaDB &db)
{
    int result = db.createFile(filename);

    switch(result)
    {
        case 1: Logger::info("This file already exists"); break;
        case 2: Logger::info("Unable to create file"); break;
        default: Logger::info("Successfully created file"); break;
    }
}


void DeleteFileCommand::deleteFile(std::string filename, PandaDB &db)
{
    int result = db.deleteFile(filename);

    if (result == 0)
    {
        Logger::info("Successfully deleted \'" + filename + '\'');
    }
    else if (result == 1)
    {
        Logger::info('\'' + filename + "\' does not exist");
    }
    else
    {
        Logger::warn('\'' + filename + "\' is a special file and cannot be deleted");
    }
}
