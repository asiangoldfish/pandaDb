#!/usr/bin/bash

## Parse commands and match with a set of predefined variables
##
## @param matchArgs Associative arrays
function parseCliArgs()
{
    local matchArgs="$1"
    
    for key in "${@}"; do
        printf '%s\n' "$key"
    done
}