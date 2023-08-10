#include "util/util.h"
#include "header.hpp"

// #include "core/Logger.cpp"

util::DIR_RESPONSE util::directoryCheck(std::string _path)
{
    /*
    DIR_NO_ACCESS,
    DIR_HAS_ACCESS,
    DIR_NOT_EXISTS,
    DIR_EXISTS
    */

   // TODO - Implement check for directory exists and access right

    const char *const path = _path.c_str();

    struct stat info;
    stat(path, &info);

    if (info.st_mode & S_IRWXU)
    {
        // Logger::fatal("Unable to access directory");
        return DIR_HAS_ACCESS;
    }

    return DIR_NO_ACCESS;
}
