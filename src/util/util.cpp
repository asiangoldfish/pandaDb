#include "util/util.h"
#include "header.hpp"
#include "util.h"

// #include "core/Logger.cpp"

util::DIR_RESPONSE
util::directoryExists(std::string path)
{
    if (std::filesystem::is_directory(path)) {
        return util::DIR_EXISTS;
    } else {
        return util::DIR_NOT_EXISTS;
    }
}

util::DIR_RESPONSE
util::directoryHasAccess(std::string path)
{
    // Check if the directory is accessible (readable and executable) for the
    // current user
    if (access(path.c_str(), R_OK | X_OK) == 0) {
        return util::DIR_HAS_ACCESS;
    } else {
        return util::DIR_NOT_EXISTS;
    }
}

bool
util::fileExists(std::string path)
{
    return std::filesystem::exists(path);
}

bool
util::isDigit(std::string value)
{
    bool isString = true;

    // Source:
    // https://www.tutorialspoint.com/how-to-check-if-a-c-cplusplus-string-is-an-int
    for (int i = 0; i < value.size(); i++) {
        if (!isdigit(value[i])) {
            isString = false;
            break;
        }
    }

    return isString;
}
