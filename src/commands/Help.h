#ifndef __HELP_CMD_H__
#define __HELP_CMD_H__

#include "commands/Command.h"

namespace cmd {

class Help : public Command
{
  public:
    Help();
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void printCommands();

  private:
    std::map<std::string, std::string> commands;
};

}

#endif