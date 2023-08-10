#ifndef __PD_DATABASE_H__
#define __PD_DATABASE_H__

#include <header.hpp>

class PandaDB
{
public:
    /**
     * @brief Initialise database.
     *
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
    bool createEntry(std::string file, std::string* entries, int numCols);
    bool checkFile(std::string tableName);
};

#endif // "pd_database.h" included