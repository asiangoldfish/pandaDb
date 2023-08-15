#include "commands/DeleteFile.h"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"

std::string
toupper(std::string str)
{
    if (str == "") {
        return "";
    } else {
        std::string ret;

        for (auto s : str) {
            ret += std::toupper(s);
        }

        return ret;
    }
}

void
cmd::DeleteFile::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.size() == 1) {
        std::string fileName = args[0];

        if (util::fileExists(conf::databaseDirPath() + "/" + fileName)) {
            // Prompt for confirmation
            std::cout << "Are you sure you want to delete this file? This is "
                         "irreversable [yes/no]: ";
            std::string input;
            std::getline(std::cin, input);

            if (toupper(input) == "Y" || toupper(input) == "YES") {
                deleteFile(fileName, db);
            } else {
                Logger::info("No files were deleted");
            }
        } else {
            Logger::info('\'' + fileName + "\' does not exist");
        }
    } else {
        std::cout << "Usage: create file <filename>" << std::endl;
    }
}

void
cmd::DeleteFile::deleteFile(std::string filename, PandaDB& db)
{
    int result = db.deleteFile(filename);

    if (result == 0) {
        Logger::info("Successfully deleted \'" + filename + '\'');
    } else if (result == 1) {
        Logger::info('\'' + filename + "\' does not exist");
    } else {
        Logger::warn('\'' + filename +
                     "\' is a special file and cannot be deleted");
    }
}
