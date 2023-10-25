#!/bin/bash

# Prompt the user to enter their UID, default root user is 1000
read -p "Enter the UID: " uid

# Use the `who` command to list logged-in users and filter by UID
user_count=$(who | awk -v uid="$uid" 'BEGIN { count = 0 } $6 == uid { count++ } END { print count }')

# Display the result
echo "User with UID $UID is logged in $user_count times."
