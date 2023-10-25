// MAGUTU PH NYARANG'O SCT211-0030/2020

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Function to handle the alarm signal (SIGALRM)
void handle_alarm(int signo)
{
    if (signo == SIGALRM)
    {
        // Remove the file "JUJU" from drive C
        if (remove("/mnt/c/JUJU.txt") == 0)
        {
            printf("The file 'JUJU' has been deleted.\n");
        }
        else
        {
            perror("Failed to delete the file 'JUJU'");
        }
        exit(0);
    }
}

int main()
{
    // Register the signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    // Schedule the alarm to trigger in 5 seconds
    alarm(5);

    // Create the file "JUJU" on drive C
    FILE *file = fopen("/mnt/c/JUJU.txt", "w");
    if (file)
    {
        fprintf(file, "This is the JUJU file created on drive C.");
        fclose(file);
        printf("The file 'JUJU' has been created on drive C.\n");
    }
    else
    {
        perror("Failed to create the file 'JUJU'");
        return 1;
    }

    // Keep the program running to handle the alarm
    while (1)
    {
        sleep(1);
    }

    return 0;
}
