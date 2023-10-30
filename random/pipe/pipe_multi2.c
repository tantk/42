#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the child process

        // Close the write end of the pipe, as the child will read from it
        close(pipe_fd[1]);

        // Read data from the pipe and print it
        char data[100];
        ssize_t bytes_read = read(pipe_fd[0], data, sizeof(data));
        if (bytes_read > 0) {
            data[bytes_read] = '\0';
            printf("Program 3 received: %s\n", data);
        }

        // Close the read end of the pipe
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    } else {
        // This is the parent process

        // Close the read end of the pipe, as the parent will write to it
        close(pipe_fd[0]);

        // Write data to the pipe
        const char *message = "Hello from Program 3!";
        write(pipe_fd[1], message, strlen(message) + 1);

        // Close the write end of the pipe
        close(pipe_fd[1]);
    }

    return 0;
}

