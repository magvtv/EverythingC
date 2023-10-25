#!/bin/bash
sum=0
for ((i = 1; i <= 5; i++)); do
    echo -n "Enter number $i: "
    read -r number

    # conditional to check validity of user number input
    if [[ $number =~ ^[0-9]+$ ]]; then
        sum=$((sum + number))
    else
        echo "Invalid number. Enter a valid number!"
        i=$((i - 1))
    fi
done

echo "Sum of all five numbers: $sum"

# MAGUTU PH NYARANG'O SCT211-0030/2020