#!/usr/bin/bash

VERSION=0.0.1
NAME=pandadb

SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"   # Script parent dir
BUILD_DIR="$SCRIPT_PATH"'/build'                            # Build dir path
MAKEFILE="$SCRIPT_PATH"'/Makefile'                          # Makefile path

## Remove all build files
function clean()
{
    verifyFile 'file' 'Makefile'
    if [ "$?" == 1 ]; then errorMessage "1"; fi
    make clean
}

## Build project
function build()
{
    verifyFile 'file' 'Makefile'
    if [ "$?" == 1 ]; then errorMessage "1"; fi

    make
}

## Prints error message and exits
## Error messages are printed based on a given index
##
## @param errorIndex (int): Error message index
function errorMessage()
{
    local errorIndex="$1"
    local arg2="$2"
    
    case "$errorIndex" in
        1 )
            printf "%s: \'Makefile\' could not be found\n" "$NAME"
        exit;;
        2 )
            printf "%s: Directory \'%s\' already exists\n" "$NAME" "$arg2"
        exit;;
            
    esac
}

## Initialize server
function initialize()
{
    local ip='127.0.0.1'
    local port='15000'
}

## Create new project module
function newModule()
{
    local dirname
    local makefilePath="$SCRIPT_PATH/template/Makefile.template"
    local dirpath
    
    # Prompt for new module name
    printf "New module name: "
    read -r dirname

    # Verify that the named directory does not already exist
    verifyFile "dir" "$dirname"; local exitCode="$?"
    if [ "$exitCode" == 0 ]; then errorMessage "2" "$dirname"; fi

    # Verify that the Makefile template exists
    verifyFile "file" "$dirname"; local exitCode="$?"
    if [ "$exitCode" == 0 ]; then errorMessage "2" "$dirname"; fi

    dirpath="$SCRIPT_PATH/$dirname"     # New module path

    # Generate new module
    printf "Generating new module \'%s\'...\n" "$dirname"
    mkdir "$SCRIPT_PATH/$dirname"
    
    # Generate Makefile
    printf "Generating Makefile...\n"
    cp "$makefilePath" "$dirpath/Makefile"

    # Generate include and src directories
    printf "Setting up module...\n"
    mkdir "$dirpath/src" "$dirpath/include" 
}

## Rebuild project
function rebuild()
{
    # Verify Makefile
    verifyFile 'file' 'Makefile'
    if [ "$?" == 1 ]; then errorMessage "1"; fi
    
    make clean
    make
}

## Start the Panda Database server
function startServer()
{
    printf "Starting server...\n"
}

## Verify file or directory
## If verification failed, then prints error message and exits promptly
##
## @param type (str): Check 'file' or 'dir'
## @param filename (str) File or directory name to check for
## @param
function verifyFile()
{
    local type="$1"
    local filename="$2"
    
    # Perform checks
    if [ "$type" == 'dir' ] && [ -d "$filename" ]; then
        return 0
        elif [ "$type" == 'file' ] && [ -f "$filename" ]; then
        return 0
    else
        return 1
    fi
}

## Help page
function usage()
{
    echo "Usage: $NAME [OPTION] ...

Utility tool for managing the Panda Database.

Options:
    build                   build the application
    clean                   clean all build files
    help                    this page
    new-module              create new module with Makefile template
    path                    temporarily adds this script to PATH
    rebuild                 rebuild the application
    start-server            start the Panda Database server
    version                 version number"
}


## Parses commands from console
function parseCmds()
{
    if [ -z "$*" ]; then usage; exit; fi
    
    for arg in "$@"; do
        case "$arg" in
            'clean' ) clean; exit;;             # Removes all build files
            'build' ) build; exit;;             # Builds the project with Make
            'help' ) usage; exit;;              # Help page
            'new-module' ) newModule; exit;;    # Create a new project module
            'path' )                            # Adds this script to PATH
                echo "This command must be sourced"
                PATH="$PATH:$SCRIPT_PATH"
                break
            ;;
            'rebuild' ) rebuild; exit;;        # Cleans and rebuilds the project
            'start-server' ) startServer; exit;;
            'version' ) echo "version $VERSION"; exit;; # Prints version no.
            *) usage; exit;;                    # Invalid command
        esac
        shift
    done
}

## Main function
function main()
{
    printf "Starting server..."
}

parseCmds "$@"
