#!/usr/bin/bash

VERSION=0.0.1
NAME=pandadb

SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"   # Script parent dir
SCRIPTS="$SCRIPT_PATH/scripts"
BUILD_DIR="$SCRIPT_PATH"'/build'                            # Build dir path
MAKEFILE="$SCRIPT_PATH"'/Makefile'                          # Makefile path

APP="$SCRIPT_PATH/build/pandadb_app"

# Includes
source "$SCRIPTS/usage.sh"
source "$SCRIPTS/utils.sh"

## Build project
function build()
{
    verifyFile 'file' 'Makefile'
    if [ "$?" == 1 ]; then errorMessage "1"; fi
    
    make
}

## Remove all build files
function clean()
{
    verifyFile 'file' 'Makefile'
    if [ "$?" == 1 ]; then errorMessage "1"; fi
    make clean
}

function create_file()
{
    printf "hello!\n"
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
    # Arguments activated by command-line arguments and default values
    local build='false'
    local host=127.0.0.1
    local port=11000
    local rebuild='false'
    local buildStatus=0         ## Whether build was successful
    
    local args; declare -A args=(
        [build]='false'
        [host]='127.0.0.1'
        [port]='11000'
        [rebuild]='false'
        [buildStatus]=0
    )

    parseCliArgs "${args[*]}}" "$@"; exit 0
    
    ## Parse commands
    local index=0           # Access elements based on index
    for i in "${@:1}"; do
        case "$i" in
            "build" ) args[build]=true;;
            'help'      ) usage_start_server; exit;;
            'host'      ) host="$1";;
            'port'      ) port="$1";;
            'rebuild'   ) rebuild='true';;
        esac
        shift               # Next argument

        ((index+=1))        # Increment index
    done

    printf "%s\n" "${args[build]}"
    
    exit 0
    # Build or rebuild project if this option was passed
    if [ "$build" == true ]; then
        printf "Building project...\n"
        build 1> /dev/null
        buildStatus="$?"
        
        elif [ "$rebuild" == true ]; then
        printf "Building project...\n"
        rebuild /dev/null
        buildStatus="$?"
    fi
    
    # Has the project been built yet?
    verifyFile 'file' "$APP"; local exitCode="$?"
    if [ "$exitCode" != 0 ]; then
        printf '%s: Could not initiate the server. Is it built yet?\n' "$NAME"
        exit 1
    fi
    
    # Only execute the program if the build was successful
    if [ "$buildStatus" == 0 ]; then
        printf '\n'             # Newline
        "$APP" "$port" "$host"
    fi
}

function parse()
{
    ## Parse commands
    for i in "${@:1}"; do
        echo "$0"
        echo "$i"
    done
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

## Parses commands from console
function parseCmds()
{
    if [ -z "$*" ]; then usage; exit; fi
    
    for arg in "$@"; do
        case "$arg" in
            'build' ) build; exit;;             # Builds the project with Make
            'clean' ) clean; exit;;             # Removes all build files
            'create-file' ) create_file; exit;; # Create new project file
            'help' ) usage; exit;;              # Help page
            'new-module' ) newModule; exit;;    # Create a new project module
            'path' )                            # Adds this script to PATH
                echo "This command must be sourced"
                PATH="$PATH:$SCRIPT_PATH"
                break
            ;;
            'rebuild' ) rebuild; exit;;        # Cleans and rebuilds the project
            'start-server' ) startServer "$@"; exit;; # Start the server
            'version' ) echo "version $VERSION"; exit;; # Prints version no.
            *) usage; exit;;                    # Invalid command
        esac
        shift
    done
}

## Main function
function main()
{
    # Parse commands and call functions accordingly
    parseCmds "$@"
}

# Execute program
main "$@"