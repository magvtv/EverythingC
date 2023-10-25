#!/bin/bash

read -p -r "Enter IP address within range: " ip_range

if [ -z "$ip_range" ]; then
    echo "IP address or range not provided."
    exit 1
fi

for host in $(seq 1 254); do
    ip="${ip_range/-/$host}"
    if ping -c 1 -W 1 "$ip" &> /dev/null; then
        echo "Host $ip is up and running"
    fi
done

# MAGUTU PH NYARANG'O SCT211-0030/2020
