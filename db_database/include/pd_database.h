/**
 * Manage panda database.
 * 
 * Contains functions that helps managing the panda database.
 */

/**
 * @brief Database table
 * 
 */
typedef struct pd_Table
{
    int *rows;
    int *columns;
} pd_Table;

/**
 * @brief Database
 * 
 */
typedef struct pd_Database
{
    pd_Table *table;
} pd_Database;


/**
 * @brief Initialise database.
 * 
 * @return int Whether the database successfully initialized. 0 for success, 1
 *             for failed.
 */
int pd_initDatabase();
/**
 * @brief Create new entry in a table.
 * 
 * @param table Table to create tables in
 * @return int Whether the table was successfully created. 0 for success,
 *             1 for failed.
 */
int db_createEntry(pd_Table *table);
/**
 * @brief Creates a new table within a database
 * 
 * @param db Database to create the table in
 * @return int Whether table was created successfully
 */
int db_createTable(pd_Database *db);