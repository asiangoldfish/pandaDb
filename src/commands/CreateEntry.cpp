#include "commands/CreateEntry.h"
#include "core/PandaDB.h"
#include "header.hpp"

void
cmd::CreateEntry::createEntry(std::string entry, PandaDB& db)
{
    db.createEntry(entry);
}
