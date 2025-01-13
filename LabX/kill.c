#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler for the child process
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child process received SIGUSR1 from parent.\n");
    }
}

int main() {
    pid_t pid;

    // Fork the process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler); // Set up signal handler

        printf("Child process waiting for signal...\n");
        pause(); // Wait for a signal
    } else {
        // Parent process
        sleep(1); // Give the child time to set up
        printf("Parent sending SIGUSR1 to child (PID: %d).\n", pid);
        kill(pid, SIGUSR1); // Send SIGUSR1 to the child
    }

    return 0;
}
