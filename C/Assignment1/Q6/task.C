// MAGUTU PH NYARANG'O SCT211-0030/2020

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t ready_to_start = 0;

void signal_handler(int signo) {
    if (signo == SIGUSR1) {
        ready_to_start = 1;
    }
}

int main() {
    signal(SIGUSR1, signal_handler);

    pid_t my_pid = getpid();
    printf("Worker (PID: %d) - Waiting for a start signal.\n", my_pid);

    while (!ready_to_start) {
        sleep(1);
    }

    printf("Worker (PID: %d) - Task started.\n", my_pid);
    // Simulate a task
    sleep(3);
    printf("Worker (PID: %d) - Task completed.\n", my_pid);

    return 0;
}
