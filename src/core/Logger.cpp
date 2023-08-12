#include "core/Logger.h"

#include <iostream>

std::string Logger::reset = "\033[1;0m";
std::string Logger::black = "\033[1;30m";
std::string Logger::red = "\033[1;31m";
std::string Logger::green = "\033[1;32m";
std::string Logger::yellow = "\033[1;33m";
std::string Logger::blue = "\033[1;34m";
std::string Logger::magenta = "\033[1;35m";
std::string Logger::cyan = "\033[1;36m";
std::string Logger::white = "\033[1;37m";

void Logger::info(std::string msg)
{
    std::cout << msg << std::endl;
}

void Logger::debug(std::string msg)
{
    info("[DEBUG]: " + msg);
}

void Logger::warn(std::string msg)
{
    std::cout << yellow << "[WARNING]: " << msg << reset << std::endl;
}

void Logger::fatal(std::string msg)
{
    std::cout << red << "[FATAL]: " << msg << reset << std::endl;
}
