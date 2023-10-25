#!/bin/bash

read -p -r "Enter the UID: " uid
user_count=$(who | awk -v uid="$uid" 'BEGIN { count = 0 } $6 == uid { count++ } END { print count }')
echo "User with UID $UID is logged in $user_count times."

# MAGUTU PH NYARANG'O SCT211-0030/2020
