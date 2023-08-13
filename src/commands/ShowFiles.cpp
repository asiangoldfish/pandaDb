#include "commands/ShowFiles.h"
#include "config.hpp"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"
#include "util/util.h"

void
cmd::ShowFiles::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.empty()) {
        this->showAllFiles(db);
    } else {
        Logger::info("Command \'show files\' does not accept arguments");
    }
}

void
cmd::ShowFiles::showAllFiles(PandaDB& db)
{
    bool fileExists = false;

    for (const auto& entry :
         std::filesystem::directory_iterator(conf::databaseDirPath())) {
        fileExists = true;

        if (entry.path() == db.getSelectedFile()) {
            std::cout << util::green << entry.path().filename().string()
                      << util::colorReset << std::endl;

        } else {
            std::cout << entry.path().filename().string() << std::endl;
        }
    }

    if (!fileExists) {
        Logger::info("No files exist");
    }
}