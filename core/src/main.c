#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "db_database.h"

#define BUFFERSIZE 2048   ///< Pager buffer size
#define DBLOCATION "data" ///< Database file location

char *gJsonFile = "data/json_test.json"; // JSON file name

void fileExists(FILE *file);

int main(void) // int argv, char **argc)
{
    /*
    // Initiate server
    serverInfo *server;
    initServer(server);

    printf("Hostname: %s\n", server->hostname);
    printf("Port: %s\n", server->portnumber);
    printf("File location: %s\n", server->fileLocation);
    */

    // writeJSON();
    // readJSON();

    db_initDatabase(DBLOCATION);
    int numCol = 3;

    char *columns[3] = {
        "id",
        "name",
        "birthdate"};

    char *entries1[2] = {
        "khai",
        "16101997"};
    char *entries2[2] = {
        "boss",
        "187392"};

    db_createTable("data/persons", columns, numCol);
    db_createEntry("data/persons", entries1, 2);
    db_createEntry("data/persons", entries2, 2);

    return 0;
}

void fileExists(FILE *file)
{
    if (!file)
    {
        fprintf(stderr, "Error while opening the file\n");
        exit(EXIT_FAILURE);
    }
}
