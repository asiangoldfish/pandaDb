#include "commands/CreateEntry.h"
#include "CreateEntry.h"
#include "core/PandaDB.h"
#include "header.hpp"

void
cmd::CreateEntry::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.size() == 1) {
        createEntry(args[0], db);
    } else if (args.size() > 1) {
        std::vector<std::string> parsedArgs = parseValues(args);

        if (parsedArgs.empty()) {
            Logger::debug("No args were passed. Is this a bug?");
        } else {
            createEntry(parsedArgs, db);
        }
    } else {
        Logger::info("Usage: create entry {column data}");
    }
}

void
cmd::CreateEntry::createEntry(std::vector<std::string> values, PandaDB& db)
{
    db.createEntry(values);
}

void
cmd::CreateEntry::createEntry(std::string values, PandaDB& db)
{
    std::vector<std::string> parsedValues;
    std::istringstream iss(values);
    std::string value;

    while (std::getline(iss, value, ',')) {
        parsedValues.push_back(value);
    }

    // Now 'parsedValues' contains individual values separated by commas
    // You can pass it to the database function or use it as needed
    db.createEntry(parsedValues);
}

std::vector<std::string>
cmd::CreateEntry::parseValues(std::vector<std::string> args)
{
    // Strings may contain whitespaces. We handle this here
    std::vector<std::string> reconstructedArgs;
    std::string currentArg;
    bool inQuotes = false;

    for (const std::string& arg : args) {
        if (!inQuotes && arg.front() == '"') {
            inQuotes = true;
            currentArg = arg.substr(1); // Remove opening quote
        } else if (inQuotes && arg.back() == '"') {
            inQuotes = false;
            currentArg +=
              " " + arg.substr(0, arg.size() - 1); // Remove closing quote
            reconstructedArgs.push_back(currentArg);
        } else if (inQuotes) {
            currentArg += " " + arg;
        } else {
            reconstructedArgs.push_back(arg);
        }
    }

    if (inQuotes) {
        Logger::info("Missing closing double-quote for string argument");
        return std::vector<std::string>(); // Handle this error case
    } else {
        return reconstructedArgs;
    }
}