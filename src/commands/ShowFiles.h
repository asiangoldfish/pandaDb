#ifndef __SHOW_FILES_CMD_H__
#define __SHOW_FILES_CMD_H__

#include "commands/Command.h"

namespace cmd {

class ShowFiles : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void showAllFiles(PandaDB &db);
};

}
#endif