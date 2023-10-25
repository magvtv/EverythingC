#!/bin/bash

# Prompt the user to enter the directory path
read -p -r "Enter the directory path: " dir_path

if [ ! -d "$dir_path" ]; then
    echo "Directory not found."
    exit 1
fi

bmp_file_count=$(find "$dir_path" -type f -name "*.bmp" | wc -l)

if [ "$bmp_file_count" -eq 0 ]; then
    echo "No .bmp files found in the directory."
    exit 0
fi

jpeg_file_count=$(find "$dir_path" -type f -name "*.jpg" | wc -l)
echo "Converted $bmp_file_count .bmp files to $jpeg_file_count .jpg files."

# MAGUTU PH NYARANG'O SCT211-0030/2020
