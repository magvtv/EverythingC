// MAGUTU PH NYARANGO SCT211-0030/2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>


// creating function to get process information by process id (PID)
void get_process_info(const char *pid) {
    char filename[100];
    char line[256];
    
    // Get process priority located in my machine at /proc/[PID]/stat
    snprintf(filename, sizeof(filename), "/proc/%s/stat", pid);
    FILE *stat_file = fopen(filename, "r");
    // conditional if the file exists
    if (stat_file) {
        if (fgets(line, sizeof(line), stat_file)) {
            int priority;
            sscanf(line, "%*s %*s %*s %*s %*s %d", &priority);
            printf("PID: %s, Priority: %d, ", pid, priority);
        }
        fclose(stat_file);
    }
    
    // Get parent process ID [PPID] from location /proc/[PID]/status
    snprintf(filename, sizeof(filename), "/proc/%s/status", pid);
    FILE *status_file = fopen(filename, "r");
    if (status_file) {
        while (fgets(line, sizeof(line), status_file)) {
            if (strstr(line, "PPID:") == line) {
                int ppid;
                sscanf(line, "PPID: %d", &ppid);
                printf("Parent PID: %d\n", ppid);
                break;
            }
        }
        fclose(status_file);
    }
}

int main() {
    DIR *dir;
    struct dirent *entries;
    

    // Open the /proc directory to access process information
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Cannot reach or open /proc directory");
        return 1;
    }

    // Loop through entries in the /proc directory
    while ((entries = readdir(dir)) != NULL) {
        // process only for names beginning with digits, these are the pid's
        if (isdigit(entries->d_name[0])) {
            get_process_info(entries->d_name);
        }
    }
    closedir(dir);
    
    return 0;
}




// QUESTION TWO