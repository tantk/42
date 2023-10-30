#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];
    pid_t child_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the child process

        // Close the write end of the pipe, as the child will read from it
        close(pipe_fd[1]);

        // Redirect the standard input to the read end of the pipe
        dup2(pipe_fd[0], STDIN_FILENO);

        // Close the duplicated file descriptor
        close(pipe_fd[0]);

        // Execute wc -l
        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    } else {
        // This is the parent process

        // Close the read end of the pipe, as the parent will write to it
        close(pipe_fd[0]);

        // Redirect the standard output to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Close the duplicated file descriptor
        close(pipe_fd[1]);

        // Execute ls -la
        execlp("ls", "ls", "-la", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    return 0;
}

