#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {

file= fopen("pids.txt", "w");
if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }






pid = fork();

if (pid < 0) {
        perror("fork failed");
        exit(1);
    }



if (pid==0) {
	fprintf(file, "child PID: %d\n", getpid());

} else {
	fprintf(file, "parent PID: %d\n", getpid());
}
fclose(file);

return 0;

}
