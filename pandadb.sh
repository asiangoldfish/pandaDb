#!/usr/bin/bash

NAME=pandadb
SCRIPT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"   # Script parent dir

VENV='venv'
PYSCRIPT="$SCRIPT_PATH/scripts/pandadb.py"

## Parses commands from console
function parseCmds()
{
    for arg in "$@"; do
        case "$arg" in
            'path' )                            # Adds this script to PATH
                echo "This command must be sourced"
                PATH="$PATH:$SCRIPT_PATH"
                return 1
            ;;
        esac
        shift
    done

    return 0
}


function executePy()
{
    if [ ! -d "$VENV" ]; then
        command -v virtualenv
        statusCode=$?
        
        if [ "$statusCode" != 0 ]; then
            printf "%s: Could not execute \'virtualenv\'. Is it installed?\n" "$NAME"
        fi
    fi
    
   # source "$SCRIPT_PATH/$VENV/bin/activate"
    if [ -f "$PYSCRIPT" ]; then
        python "$PYSCRIPT" "$@"
    else
        printf "%s: Could not find file \'%s\'\n" "$NAME" "$PYSCRIPT"
    fi
}

parseCmds "$@"
exitStatus="$?"
if [ "$exitStatus" == 0 ]; then
    executePy "$@"
fi
