/**
 * Manage panda database.
 *
 * Contains functions that helps managing the panda database.
 */

#ifndef PD_DATABASE_H
#define PD_DATABASE_H

#include <stdio.h>

/**
 * @brief Initialise database.
 * 
 * @param location  Database file location
 * @param name      Database name
 *
 * @return Whether the database successfully initialized. 0 for success, 1
 *             for failed.
 */
int db_initDatabase(const char *const name);

/**
 * @brief Create new entry in a table.
 *
 * @param table Table to create tables in
 * @return int Whether the table was successfully created. 0 for success,
 *             1 for failed.
 */
int db_createEntry(char *path, char **entries, int numCols);

/**
 * @brief Creates a new table within a database
 *
 * @param db Database to create the table in
 * @return int Whether table was created successfully
 */
int db_createTable(const char *const path, char **columns, const int numColumns);

#endif // "pd_database.h" included