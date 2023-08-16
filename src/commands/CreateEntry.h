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

    // Transform raw input data to a format that the database understands
    std::vector<std::string> parseValues(std::vector<std::string> args);
};

}
#endif