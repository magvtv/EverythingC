// MAGUTU PH NYARANG'0 SCT211-0030/2020

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t childPID; // This will store the process ID of the child process

    // Fork a child process
    childPID = fork();

    // Check if fork() was successful
    if (childPID < 0) {
        perror("Fork failed");
        return 1;
    }

    if (childPID == 0) {
        // printed out by the child process
        printf("Child process: My PID is %d. My Parent's PID is %d.\n", getpid(), getppid());
    } else {
        // printed out by the parent process
        printf("Parent process: My PID is %d. My Child's PID is %d.\n", getpid(), childPID);
    }

    return 0;
}
