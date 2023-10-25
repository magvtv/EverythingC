// MAGUTU PH NYARANG'O SCT211-0030/2020

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void signal_handler(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("New message received: ");
    }
}

int main()
{
    signal(SIGUSR1, signal_handler);

    pid_t my_pid = getpid();
    printf("Chat Client (PID: %d) - Type message. Press Enter to send:\n", my_pid);

    while (1)
    {
        char message[256];
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove newline character
        if (strlen(message) > 0)
        {
            // Send the message to other chat clients by sending SIGUSR1 signal
            // In a real application, you would need a way to identify and notify other clients.
            printf("Message sent: %s\n", message);
            kill(my_pid, SIGUSR1);
        }
    }

    return 0;
}
