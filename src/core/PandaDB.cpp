#include "PandaDB.h"

#include "config.hpp"
#include "core/Logger.h"
#include "header.hpp"
#include "util/util.h"

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

PandaDB::PandaDB()
{
    // Insert special files here. These will never be deleted!
    specialFiles.push_back("users");
    specialFiles.push_back(".metadata");

    // Legal data types
    legalTypes.push_back("int8");
    legalTypes.push_back("int32");
    legalTypes.push_back("int64");
    legalTypes.push_back("float32");
    legalTypes.push_back("float64");
    legalTypes.push_back("bool");
    legalTypes.push_back("datetime");
    legalTypes.push_back("varchar");
}

bool
PandaDB::initDatabase(std::string name)
{
    // Create directory.
    if (std::filesystem::create_directories(name)) {
        Logger::info("Creating new database directory at " + name);
    }

    return true;
}

void
PandaDB::createEntry(std::vector<std::string> values)
{
    std::ofstream outfile;
    outfile.open(selectedFile, std::ios_base::app);

    std::string newValue;

    for (auto value : values) {
        newValue.append(value);
        newValue.append(",");
    }

    if (newValue != "") {
        newValue.pop_back();
    }

    outfile << newValue;
}

bool
PandaDB::checkFile(std::string tableName)
{
    return false;
}

int
PandaDB::createFile(std::string filename, std::vector<std::string> argStr)
{
    std::ofstream output;

    if (util::fileExists(conf::databaseDirPath() + "/" + filename)) {
        return 1;
    } else {
        output.open(conf::databaseDirPath() + "/" + filename);
        if (!output) {
            return 2;
        }
    }

    for (auto iter = argStr.begin(); iter != argStr.end(); iter++) {
        output << *(iter);

        // Set delimiter
        if (iter + 1 != argStr.end()) {
            output << ",";
        }
    }

    output << "\n";

    return 0;
}

int
PandaDB::deleteFile(std::string filename)
{
    for (auto file : specialFiles) {
        if (filename == file) {
            return 2;
        }
    }

    if (conf::databaseDirPath() + "/" + filename == selectedFile) {
        selectedFile = "";
    }

    return !std::filesystem::remove(conf::databaseDirPath() + "/" + filename);
}

bool
PandaDB::showData()
{
    using namespace std;

    if (selectedFile == "") {
        return false;
    }

    ifstream infile(selectedFile);

    string line;

    int colwidth = 0;

    // Discard first line. That's only columns
    {
        getline(infile, line);
        istringstream iss(line);
        string columnData;
        vector<string> columns;

        while (getline(iss, columnData, ',')) {
            columns.push_back(columnData);
            colwidth =
              conf::columnWidth * columns.size() + (columns.size() * 3) + 1;
        }

        printSeperator('-', colwidth);

        cout << "| ";

        for (auto iter = columns.begin(); iter != columns.end(); iter++) {
            cout << left << setw(conf::columnWidth) << *iter;
            cout << " | ";
        }

        cout << std::endl;
        printSeperator('-', colwidth);
    }

    while (getline(infile, line)) {
        istringstream iss(line);
        string columnData;
        vector<string> columns;

        while (getline(iss, columnData, ',')) {
            columns.push_back(columnData);
            colwidth =
              conf::columnWidth * columns.size() + (columns.size() * 3) + 1;
        }

        cout << "| ";

        for (auto iter = columns.begin(); iter != columns.end(); iter++) {
            cout << left << setw(conf::columnWidth) << *iter;
            cout << " | ";
        }

        cout << std::endl;
    }

    printSeperator('-', colwidth);

    return true;
}

void
PandaDB::printSeperator(char divider, int repetitions)
{
    for (int i = 0; i < repetitions; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
