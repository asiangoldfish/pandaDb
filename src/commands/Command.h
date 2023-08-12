#ifndef __COMMANDS__H__
#define __COMMANDS__H__

#include "header.hpp"
#include "core/Logger.h"
#include "config.h"

class PandaDB;

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) = 0; 
};

class HelpCommand : public Command
{
public:
    HelpCommand();
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) override
    {
        if (args.empty())
        {
            printCommands();
        }
        else
        {
            Logger::info("Command \'help\' does not accept arguments");
        }
    };

private:
    void printCommands();
    void constructCommand(std::string command, std::string description);

private:
    std::map<std::string, std::string> commands;
};

class ShowFilesCommand : public Command
{
public:
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) override
    {
        if (args.empty())
        {
            showAllFiles();
        }
        else
        {
            Logger::info("Command \'show files\' does not accept arguments");
        }
    }

private:
    void showAllFiles();
};

class SelectFileCommand : public Command
{
public:
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) override
    {
        if (args.size() == 1) {
            std::string fileName = args[0];
            selectFile(fileName, db);
        } else {
            std::cout << "Usage: select file <filename>" << std::endl;
        }
    }

private:
    void selectFile(std::string filename, PandaDB &db);
};

class CreateFileCommand : public Command
{
public:
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) override
    {
        if (args.size() == 1) {
            std::string fileName = args[0];
            createFile(fileName, db);
        } else {
            std::cout << "Usage: create file <filename>" << std::endl;
        }
    }

private:
    void createFile(std::string filename, PandaDB &db);
};

class DeleteFileCommand : public Command
{
public:
    virtual void execute(const std::vector<std::string>& args, PandaDB &db) override
    {
        if (args.size() == 1) {
            std::string fileName = args[0];
            deleteFile(fileName, db);
        } else {
            std::cout << "Usage: create file <filename>" << std::endl;
        }
    }

private:
    void deleteFile(std::string filename, PandaDB &db);
};

#endif
