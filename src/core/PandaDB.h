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
    std::string getSelectedFile() { return selectedFile; }
    bool showData();

    std::vector<std::string> getLegalTypes() const { return legalTypes; }

  private:
    void printSeperator(char divider, int repetitions);

  private:
    std::string selectedFile;
    std::vector<std::string> specialFiles;

    std::vector<std::string> legalTypes;
};

#endif // "pd_database.h" included
