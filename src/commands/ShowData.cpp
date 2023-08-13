#include "commands/ShowData.h"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"

void
cmd::ShowData::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.size() == 0) {
        this->showData(db);
    } else {
        std::cout << "Usage: show data <filename>" << std::endl;
    }
}

void
cmd::ShowData::showData(PandaDB& db)
{
    if (!db.showData()) {
        Logger::info("No file is selected");
    }
}