#include "commands/CreateFile.h"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"
#include "util/util.h"

void
cmd::CreateFile::createFile(std::string filename,
                            std::vector<std::string> argStr,
                            PandaDB& db)
{
    using namespace std;

    if (util::fileExists(conf::databaseDirPath() + "/" + filename)) {
        Logger::info("This file already exists");
        return;
    }

    // Name, type
    map<string, string> columns;

    // Evaluate the args' validity for each argument
    for (string arg : argStr) {
        size_t colonPos = arg.find(':');
        string columnName = arg.substr(0, colonPos);
        string dataTypeExpression = arg.substr(colonPos + 1);

        if (colonPos != string::npos) {
            // varchar has length. Example: varchar(64) is 64 long string
            size_t openParenPos = dataTypeExpression.find('(');
            size_t closeParenPos = dataTypeExpression.find(')');

            // If this is true, then it might be varchar type
            if (openParenPos != std::string::npos &&
                closeParenPos != std::string::npos) {
                string dataType = dataTypeExpression.substr(0, openParenPos);

                string sizeExpression = dataTypeExpression.substr(
                  openParenPos + 1, closeParenPos - openParenPos - 1);

                if (dataType != "varchar") {
                    Logger::info("Type \'" + dataType + "\' is invalid");
                    return;
                }

                columns[columnName] = dataTypeExpression;
            } else {
                // Logger::debug("Searching " + dataTypeExpression + "...");

                bool isTypeFound = false;
                for (auto type : db.getLegalTypes()) {
                    if (dataTypeExpression == type) {
                        isTypeFound = true;
                        break;
                    }
                }

                if (isTypeFound) {
                    columns[columnName] = dataTypeExpression;
                } else {
                    Logger::info("Type \'" + dataTypeExpression +
                                 "\' is invalid");
                    return;
                }
            }
        }
    }

    db.createFile(filename, argStr);
}
