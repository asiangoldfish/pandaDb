#ifndef __DELETE_FILE_H__
#define __DELETE_FILE_H__

#include "commands/Command.h"

class PandaDB;

namespace cmd {

class DeleteFile : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override;

  private:
    void deleteFile(std::string filename, PandaDB& db);
};

}
#endif