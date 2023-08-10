/**
 * PandaDB configuration file.
*/

#ifndef __PANDADB_CONFIG_H__
#define __PANDADB_CONFIG_H__

#include "header.hpp"

namespace conf
{
    // Directory where the database's file system is stored. This must be stored
    // at a secure location.
    inline std::string databaseDirPath()
    {
        std::stringstream ss;
        ss << std::getenv("HOME") << "/pandaDB";
        return ss.str();
    }     
}

#endif