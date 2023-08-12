#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h> // mkdir
#include <unistd.h>

#include "server.h"

int initServer(serverInfo *server)
{
    // Initialie server parameters
    strcpy(server->hostname, "localhost");
    strcpy(server->portnumber, "13131");
    strcpy(server->fileLocation, "data");

    /*
     * Database location
     * For now, the location is within the project directory
     */
    // TODO - Allow the admin to change the database location
    struct stat st = {0};
    if (stat(server->fileLocation, &st) == -1)
    {
        printf("Creating database directory at %s\n", server->fileLocation);
        mkdir(server->fileLocation, 0755);
    }

    return 0;
}
