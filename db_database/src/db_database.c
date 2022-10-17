#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include "db_database.h"

/**
 * @brief Checks if the database exists
 *
 * @return 0 if exists, 1 if not
 */
int verifyDatabase();

int db_createEntry(char *path, char **entries, int numCols)
{
    FILE *fp;                     // Table file
    int bufferSize = 2048;        // Max table file size
    char delimiter = ',';         // CSV delimiter

    // Does table exist
    fp = fopen(path, "a");

    // Add new entry to the table CSV
    for (int i = 0; i < numCols; i++)
    {
        // Insert id
        if (i == 0)
            fprintf(fp, "0,");

        fprintf(fp, "%s", entries[i]);

        // Delimiter
        if (i + 1 < numCols)
            fprintf(fp, "%c", delimiter);
        else
            fprintf(fp, "\n");
    }

    fclose(fp);
    return 0;
}

int db_createTable(const char *const path, char **columns, const int numColumns)
{
    FILE *fp;             // Database file
    char delimiter = ','; // CSV delimiter

    // Check if database exists
    if (verifyDatabase())
    {
        printf("No database exists\n");
        return 1;
    }

    // Craft table name
    fp = fopen(path, "w");
    if (!fp)
    {
        printf("Table \'%s\' already exists.\n", path);
        return 1;
    }

    // Write columns to file
    for (int i = 0; i < numColumns; i++)
    {
        fprintf(fp, "%s", columns[i]);

        // Delimiter
        if (i + 1 < numColumns)
            fprintf(fp, "%c", delimiter);
        else
            fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}

int db_initDatabase(const char *const name)
{
    // Create directory.
    if (mkdir(name, 0777) == -1)
    {
        // printf("Database already exists\n");
        return 1;
    }
    else
        printf("Created new database \'%s\'\n", name);

    return 0;
}

int verifyDatabase()
{
    DIR *dir = opendir("data");
    if (dir)
    {
        // Directory exists
        closedir(dir);
        return 0;
    }
    else if (ENOENT == errno)
    {
        // Directory does not exist
        return 1;
    }
    else
    {
        // opendir() failed for some other reason
        return 2;
    }
}
