/**
 * Manage database accounts
 */

#ifndef PD_ACCOUNTS_H
#define PD_ACCOUNTS_H 1

#include "PandaDB.h"

/**
 * @brief Create a new account
 *
 * @param db Database to store the account in
 * @param username Account username
 * @param password Account password in plaintext2
 * @return int Account ID
 */
int pd_createAccount(pd_Database *db, const char *username, const char *password);

/**
 * @brief Create a new group
 * 
 * @param db Database to create the group in
 * @param groupName Group name
 * @return int Group ID
 */
int pd_createGroup(pd_Database *db, const char *groupName);

/**
 * @brief Delete account
 * 
 * @param db Database to delete account from
 * @param id Account id
 * @return int 0: success, 1: fail
 */
int pd_deleteAccount(pd_Database *db, int id);

/**
 * @brief Delete group
 * 
 * @param db Database to delete group from
 * @param id Group id
 * @return int 0: success, 1: fail
 */
int pd_deleteGroup(pd_Database *db, int id);

/**
 * @brief Get account id
 * 
 * @param db Database whose account belongs to
 * @param username Account username
 * @return int Account id
 */
int pd_getAccountId(pd_Database *db, const char *username);

/**
 * @brief Get group id.
 * 
 * @param db Database whose group belongs to.
 * @param groupName Group name.
 * @return int Group id.
 */
int pd_getGroupId(pd_Database *db, const char *groupName);

/**
 * Removes group from the database.
 * 
 * When a group is removed, accounts that belong to no groups will automatically
 * be assigned to the default group.
 * 
 * @param db Database to remove group from 
 * @param id Group id
 * @return int 0: success, 1: fail
 */
int pd_removeFromGroup(pd_Database *db, int id);

#endif // "pd_accounts.c" included
