#ifndef __CREATE_FILE_H__
#define __CREATE_FILE_H__

#include "commands/Command.h"

namespace cmd {

class CreateFile : public Command
{
  public:
    virtual void execute(const std::vector<std::string>& args,
                         PandaDB& db) override
    {
        if (args.size() > 1) {
            std::vector<std::string> argsWithoutFirst(args.begin() + 1,
                                                      args.end());
            std::string fileName = args[0];
            createFile(fileName, argsWithoutFirst, db);
        } else {
            std::cout << "Usage: create file <filename> <columns {name:type}>"
                      << std::endl;
        }
    }

  private:
    bool createFile(std::string filename,
                    std::vector<std::string> argStr,
                    PandaDB& db);
};

}
#endif