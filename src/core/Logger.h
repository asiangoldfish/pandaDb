#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <header.hpp>

class Logger
{
    enum class SEVERITY
    {
        INFO,
        DEBUG,
        WARN,
        FATAL
    };

  public:
    // TODO - Print with timestamp
    static void info(std::string msg);
    static void debug(std::string msg);
    static void warn(std::string msg);
    static void fatal(std::string msg);
};

#endif