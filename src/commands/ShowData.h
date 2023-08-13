#ifndef __SHOW_DATA_H__
#define __SHOW_DATA_H__

#include "commands/Command.h"
#include <vector>

class PandaDB;

namespace cmd {

class ShowData : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void showData(PandaDB& db);
};

}
#endif