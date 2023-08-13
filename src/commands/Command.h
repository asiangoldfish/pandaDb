#ifndef __COMMANDS__H__
#define __COMMANDS__H__

#include <string>

class PandaDB;

class Command
{
  public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args, PandaDB& db) = 0;
};

#endif
