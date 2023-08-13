#ifndef __SELECT_FILE_H__
#define __SELECT_FILE_H__

#include "commands/Command.h"
#include <string>
#include <vector>

class PandaDB;

namespace cmd {

class SelectFile : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void select(std::string filename, PandaDB& db);
};

}

#endif