#include "commands/Help.h"
#include "core/Logger.h"

cmd::Help::Help()
{
    commands["help"] = "Print all commands";
    commands["quit"] = "Quit this application";
    commands["show files"] = "Show all files";
    commands["select"] = "Select a file. Its data can then be displayed.";
    commands["show data"] = "Display a selected file's data";
    commands["create file"] = "Create a new file";
    commands["create entry"] = "Create a new entry in the selected file";
}

void
cmd::Help::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.empty()) {
        printCommands();
    } else {
        Logger::info("Command \'help\' does not accept arguments");
    }
}

void
cmd::Help::printCommands()
{
    using namespace std;

    cout << endl;

    for (auto command : commands) {
        cout << left << setw(25) << command.first << command.second << endl;
    }
}
