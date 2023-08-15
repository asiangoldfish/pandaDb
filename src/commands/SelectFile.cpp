#include "commands/SelectFile.h"

#include "core/Logger.h"
#include "core/PandaDB.h"
#include "util/util.h"

namespace cmd {

void
SelectFile::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.size() == 1) {
        std::string fileName = args[0];
        this->select(fileName, db);
    } else {
        std::cout << "Usage: select <filename>" << std::endl;
    }
}

void
SelectFile::select(std::string filename, PandaDB& db)
{
    if (util::fileExists(conf::databaseDirPath() + "/" + filename)) {
        db.setSelectedFile(filename);
    } else {
        Logger::info("File does not exist");
    }
}

}