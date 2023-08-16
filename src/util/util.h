#ifndef __UTIL_H__
#define __UTIL_H__

#include "header.hpp"

namespace util {
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

DIR_RESPONSE
directoryExists(std::string path);

DIR_RESPONSE
directoryHasAccess(std::string path);

bool
fileExists(std::string path);

inline std::string colorReset = "\033[1;0m";
inline std::string black = "\033[1;30m";
inline std::string red = "\033[1;31m";
inline std::string green = "\033[1;32m";
inline std::string yellow = "\033[1;33m";
inline std::string blue = "\033[1;34m";
inline std::string magenta = "\033[1;35m";
inline std::string cyan = "\033[1;36m";
inline std::string white = "\033[1;37m";

bool isDigit(std::string value);
}

#endif