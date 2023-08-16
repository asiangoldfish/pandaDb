#include "commands/CreateFile.h"
#include "core/Logger.h"
#include "core/PandaDB.h"
#include "header.hpp"
#include "util/util.h"

bool
cmd::CreateFile::createFile(std::string filename,
                            std::vector<std::string> argStr,
                            PandaDB& db)
{
    using namespace std;

    if (util::fileExists(conf::databaseDirPath() + "/" + filename)) {
        Logger::info("This file already exists");
        return false;
    }

    // Name, type
    map<string, string> columns;

    // Evaluate the args' validity for each argument
    for (string arg : argStr) {
        size_t colonPos = arg.find(':');
        string columnName = arg.substr(0, colonPos);
        string dataTypeExpression = arg.substr(colonPos + 1);

        if (colonPos != string::npos) {
            size_t openParenPos = dataTypeExpression.find('(');
            size_t closeParenPos = dataTypeExpression.find(')');

            // Paranthesises were detected
            if (openParenPos != std::string::npos) {
                if (closeParenPos == std::string::npos) {
                    Logger::info(
                      "No closing paranthesis \')\' was found for \'" +
                      columnName + "\'");
                    return false;
                }

                string dataType = dataTypeExpression.substr(0, openParenPos);

                string sizeExpression = dataTypeExpression.substr(
                  openParenPos + 1, closeParenPos - openParenPos - 1);

                // Compatible types with paranthesis
                bool isCompatible = false;
                for (auto type : db.getCompatibleSizeTypes()) {
                    if (dataType == type) {
                        isCompatible = true;
                        break;
                    }
                }

                if (!isCompatible) {
                    Logger::info("Type \'" + dataType + "\' is invalid");
                    return false;
                } else if (sizeExpression.empty()) {
                    Logger::info("Type \'" + dataType +
                                 "\' is needs a size expression. Example: " +
                                 dataType + "(64)");
                    return false;
                } else if (!util::isDigit(sizeExpression)) {
                    Logger::info("Size expression \'" + sizeExpression +
                                 "\' of type \'" + dataType +
                                 "\' is invalid. Must be an integer");
                    return false;
                }

                columns[columnName] = dataTypeExpression;
            } else {
                bool isTypeFound = false;
                for (auto type : db.getLegalTypes()) {
                    if (dataTypeExpression == type) {
                        isTypeFound = true;
                        break;
                    }
                }

                if (dataTypeExpression == "varchar") {
                    Logger::info("Type \'varchar\' needs a size parameter. "
                                 "Example: varchar(64)");
                    return false;
                } else if (isTypeFound) {
                    columns[columnName] = dataTypeExpression;
                } else {
                    Logger::info("Type \'" + dataTypeExpression +
                                 "\' is invalid");
                    return false;
                }
            }
        } else {
            Logger::info("\'" + arg +
                         "\' is an invalid type. Format must be \'name:type\'");
            return false;
        }
    }

    // Returns 0 if success, so we invert it
    return !db.createFile(filename, argStr);
}
