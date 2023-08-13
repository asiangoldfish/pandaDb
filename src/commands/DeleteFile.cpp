#include "commands/DeleteFile.h"
#include "core/Logger.h"
#include "core/PandaDB.h"

void
cmd::DeleteFile::execute(const std::vector<std::string>& args, PandaDB& db)
{
    if (args.size() == 1) {
        std::string fileName = args[0];
        deleteFile(fileName, db);
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
