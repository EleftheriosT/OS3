#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
  int pipefd[2];
    pid_t pid;
    char buffer[100];

   if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }


if (pid == 0) {
        // Child process: Read from the pipe
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    } else {
        // Parent process: Write to the pipe
        close(pipefd[0]); // Close unused read end
        write(pipefd[1], "Hello, Child!", 14);
        close(pipefd[1]);
    }







return 0; }
