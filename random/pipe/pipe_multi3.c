#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // First child process (ls)
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the child process (ls)

        // Close the read end of the pipe, as the child will write to it
        close(pipe_fd[0]);

        // Redirect the standard output to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);

        // Execute the "ls" command
        execlp("ls", "ls", (char *)NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Close the write end of the pipe, as the parent will read from it
        close(pipe_fd[1]);

        // Second child process (filtering)
        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            // This is the second child process (filtering)

            // Redirect the standard input to the read end of the pipe
            dup2(pipe_fd[0], STDIN_FILENO);
            close(pipe_fd[0]);

            // Execute the filter program (e.g., grep)
            execlp("grep", "grep", "pipe", (char *)NULL);
            perror("execlp grep");
            exit(EXIT_FAILURE);
        } else {
            // Parent process

            // Close the read end of the pipe, as the parent will write to it
            close(pipe_fd[0]);

            // Third child process (wc -l)
            child_pid = fork();

            if (child_pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0) {
                // This is the third child process (wc -l)

                // Redirect the standard input to the read end of the pipe
                dup2(pipe_fd[0], STDIN_FILENO);
                close(pipe_fd[0]);

                // Execute the "wc -l" command
                execlp("wc", "wc", "-l", (char *)NULL);
                perror("execlp wc");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Wait for all child processes to finish
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}

