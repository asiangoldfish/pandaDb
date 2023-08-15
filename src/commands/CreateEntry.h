#ifndef __CREATE_ENTRY_H__
#define __CREATE_ENTRY_H__

#include "commands/Command.h"
#include "core/Logger.h"
#include <vector>

namespace cmd {

class CreateEntry : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void createEntry(std::vector<std::string> values, PandaDB& db);
    void createEntry(std::string values, PandaDB& db);
};

}
#endif