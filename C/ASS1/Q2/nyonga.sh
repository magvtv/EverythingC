# MAGUTU PH NYARANGO SCT211-0030/2020

#!/bin/bash

# conditional checking the shell script was run with an argument
if [ "$#" -ne 0 ]; then
    echo "Usage: ./nyonga.sh (without any arguments)"
    exit 1
fi

# fetch the pid of the current shell script
shell_pid=$$

# terminate the current shell pid
kill $shell_pid
