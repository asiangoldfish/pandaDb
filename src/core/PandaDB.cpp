#include "PandaDB.h"

#include "header.hpp"
#include "core/Logger.h"
#include "../util/util.h"

/*

    PandaDB *db = new PandaDB();

    if (db->initDatabase(conf::databaseDirPath()))
    {
        Logger::info("Initializing database");
    }
    else
    {
        Logger::fatal("Failed to initialize the database");
        return 1;
    }
    
    int numCol = 3;

    std::string columns[3] = {
        "id",
        "name",
        "birthdate"
    };

    std::string entries1[2] = {
        "khai",
        "16101997"
    };

    std::string entries2[2] = {
        "boss",
        "187392"
    };
    */

/**
 * @brief Checks if the database exists
 *
 * @return 0 if exists, 1 if not
 */

bool PandaDB::initDatabase(std::string name)
{
    /*
    if (util::directoryCheck(conf::databaseDirPath()) == util::DIR_NO_ACCESS)
    {
        Logger::fatal("INITIATION FAILED: Cannot access database directory");
        return false;
    }
    */

    // Create directory.
    if (std::filesystem::create_directories(name))
    {
        Logger::info("Creating new database directory at " + name);
    }

    return true;
}

bool PandaDB::createEntry(std::string file, std::string *entries, int numCols)
{
    std::ofstream outfile;
    int bufferSize = 2048; // Max table file size
    char delimiter = ',';  // CSV delimiter

    outfile.open(conf::databaseDirPath() + file, std::ios::ate);
    if (outfile.fail())
    {
        Logger::warn("File \'" + file + "\' does not exist. Failed to create entry.");
        return false;
    }
    else
    {

        // Add new entry to the table CSV
        for (int i = 0; i < numCols; i++)
        {
            // Insert id
            if (i == 0)
            {
                outfile << "0\n";
            }

            outfile << entries[i] << "\n";

            // Delimiter
            if (i + 1 < numCols)
            {
                outfile << delimiter << "\n";
            }
            else
            {
                outfile << std::endl;
            }
        }
    }

    outfile.close();
    return 0;
}

bool PandaDB::checkFile(std::string tableName)
{
    return false;
}
