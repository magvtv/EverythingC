#!/bin/bash

file_path="Assignment2/Q2/jujayetu.txt"
# conditional to check jujayetu.txt exists
if [ -e "$file_path" ]; then
    # Read the contents of the file, remove white spaces, and count characters
    char_count=$(cat "$file_path" | tr --delete ' ' | wc --chars)
    echo "Number of characters without white-space in '$file_path' file: $char_count"
else
    echo "File '$file_path' not found."
fi

# MAGUTU PH NYARANG'O SCT211-0030/2020