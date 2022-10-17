/**
 * Manage server
 * 
 * @author your name (you@domain.com)
 */

#ifndef DB_SERVER_H
#define DB_SERVER_H 1

/**
 * Required server information
 * 
 * Network related data required upon startup.
 */
typedef struct serverInfo
{
    char hostname[64];
    char portnumber[6];
    char fileLocation[128];
} serverInfo;


/**
 * Initiates the database server
 * 
 * @param host Server hostname or ip address
 * @param port Server port number
 * 
 * @return 0 if server successfully initiated, 1 if not
 */
int initServer(serverInfo *server);

#endif