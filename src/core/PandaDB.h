#ifndef __PD_DATABASE_H__
#define __PD_DATABASE_H__

#include "config.hpp"
#include "util/util.h"
#include <header.hpp>

class PandaDB
{
  public:
    PandaDB();
    virtual ~PandaDB() = default;

    /**
     * @brief Initialise database.

     * @param location  Database file location
     * @param name      Database name
     *
     * @return Whether the database successfully initialized. 0 for success, 1
     *             for failed.
     */
    bool initDatabase(std::string name);

    /**
     * @brief Create new entry in a table.
     *
     * @param table Table to create tables in
     * @return int Whether the table was successfully created. 0 for success,
     *             1 for failed.
     */
    void createEntry(std::vector<std::string> values);
    bool checkFile(std::string tableName);
    int createFile(std::string filename, std::vector<std::string> argStr);
    int deleteFile(std::string filename);
    void setSelectedFile(std::string selectedFile)
    {
        this->selectedFile = conf::databaseDirPath() + "/" + selectedFile;
    }
    bool showData();

    std::string getSelectedFile() { return selectedFile; }
    std::vector<std::string> getLegalTypes() const { return legalTypes; }
    std::vector<std::string> getCompatibleSizeTypes() const
    {
        return compatibleSizeTypes;
    }

  private:
    void printSeperator(char divider, int repetitions);

  private:
    std::string selectedFile;
    std::vector<std::string> specialFiles;

    std::vector<std::string> legalTypes;

    // Types whose size is expressed with paranthesis. Example: varchar(64)
    std::vector<std::string> compatibleSizeTypes;
};

#endif // "pd_database.h" included
