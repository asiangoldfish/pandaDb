#include "core/Logger.h"

#include "util/util.h"
#include <iostream>

void
Logger::info(std::string msg)
{
    std::cout << msg << std::endl;
}

void
Logger::debug(std::string msg)
{
    info("[DEBUG]: " + msg);
}

void
Logger::warn(std::string msg)
{
    std::cout << util::yellow << "[WARNING]: " << msg << util::colorReset
              << std::endl;
}

void
Logger::fatal(std::string msg)
{
    std::cout << util::red << "[FATAL]: " << msg << util::colorReset
              << std::endl;
}
