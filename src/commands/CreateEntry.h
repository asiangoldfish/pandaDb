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
                         PandaDB& db) override
    {
        if (args.size() == 1) {
            createEntry(args[0], db);
        } else {
            Logger::info("Usage: create entry {column data}");
        }
    }

  private:
    void createEntry(std::string entry, PandaDB& db);
};

}
#endif