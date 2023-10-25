#! /bin/bash

read -r -p 'Enter directory path: ' dir_path
if [ ! -d "$dir_path" ]; then
    echo "That directory is not found!"
    exit 1
fi
find "$dir_path" -type d -empty -exec stat -c "%n %w" {} \;
empty_folder_count=$(find "$dir_path" -type d -empty | wc -l)
echo "Number of empty folders in $dir_path: $empty_folder_count"

# MAGUTU PH NYARANG'O SCT211-0030/2020

