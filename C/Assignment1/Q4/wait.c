// MAGUTU PH NYARANG'O SCT211-0030/2020

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t child_pid, wpid;
    int status;

    // creating child process
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        // this is the child process
        printf("Child process: My PID is %d\n", getpid());
        // simulation the child process at work with sleep delay
        sleep(2);
        exit(42); // status to exit with
    }
    else
    {
        // this is the parent process
        printf("Parent process: My PID is %d\n", getpid());

        // wait() to wait for any child to end or terminate
        wpid = wait(&status);
        if (wpid == -1)
        {
            perror("Wait failed");
            exit(1);
        }

        if (WIFEXITED(status))
        {
            printf("Child with PID %d terminated with status: %d\n", wpid, WEXITSTATUS(status));
        }

        // creating another child process
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Fork failed");
            exit(1);
        }

        if (child_pid == 0)
        {
            // this is the second child process
            printf("Child process 2: My PID is %d\n", getpid());
            // simulation of child working
            sleep(3);
            exit(84); // status to exit with different from 1st child
        }
        else
        {

            // Using waitpid() to wait for a specific child (second child) to terminate
            wpid = waitpid(child_pid, &status, 0);
            if (wpid == -1)
            {
                perror("Waitpid failed");
                exit(1);
            }

            if (WIFEXITED(status))
            {
                printf("Child 2 with PID %d terminated with status: %d\n", wpid, WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
