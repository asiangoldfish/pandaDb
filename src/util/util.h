#ifndef __UTIL_H__
#define __UTIL_H__

#include "header.hpp"

namespace util
{
    enum FILE_RESPONSE
    {
        FILE_NO_ACCESS,
        FILE_HAS_ACCESS,
        FILE_NOT_EXISTS,
        FILE_EXISTS
    };

    enum DIR_RESPONSE
    {
        DIR_NO_ACCESS,
        DIR_HAS_ACCESS,
        DIR_NOT_EXISTS,
        DIR_EXISTS
    };

    DIR_RESPONSE directoryExists(std::string path);
    DIR_RESPONSE directoryHasAccess(std::string path);
    FILE_RESPONSE fileExists(std::string path);
}

#endif