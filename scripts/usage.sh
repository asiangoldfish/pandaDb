#!/usr/bin/bash

## Help page
function usage()
{
    echo "Usage: $NAME [OPTION] ...

Utility tool for managing the Panda Database.

Options:
    build                   build the application
    clean                   clean all build files
    create-file             interactive menu to create a new project file
    help                    this page
    new-module              create new module with Makefile template
    path                    temporarily adds this script to PATH
    rebuild                 rebuild the application
    start-server            start the Panda Database server
    version                 version number

For more info about a command, execute it with the 'help'. Example:
    $NAME build help"
}

function usage_create_file()
{
    :
}

# Help page: @cmd start-server
function usage_start_server()
{
    echo "Usage: $NAME start-server [OPTIONS] ...

Start the Panda Database server.

Options:
    build                   build project before starting the server
    help                    this page
    host                    hostname or ip address
    rebuild                 clean build project before starting the server
    port                    port number

Example:
    $NAME start-server -h 127.0.0.1 -p 11000"
}
