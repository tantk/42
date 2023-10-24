#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const pid_t process_id = fork(); // Compilation error

    if (process_id < 0) {
        perror("fork");
        exit(1);
    }

    if (process_id == 0) {
        // This is the child process
        printf("Child process with PID %d\n", getpid());
        exit(0);
    } else {
        // This is the parent process
        printf("Parent process with PID %d and child PID %d\n", getpid(), process_id);
        wait(NULL);
    }

    return 0;
}
