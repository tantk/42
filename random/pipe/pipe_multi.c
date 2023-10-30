#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe_ls_grep[2];
    int pipe_grep_wc[2];
    pid_t ls_pid, grep_pid, wc_pid;

    if (pipe(pipe_ls_grep) == -1 || pipe(pipe_grep_wc) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the first child process to run "ls -la" and send output to the pipe
    ls_pid = fork();

    if (ls_pid == -1) {
        perror("fork ls");
        exit(EXIT_FAILURE);
    }

    if (ls_pid == 0) {
        // Child process: set up pipe
        close(pipe_ls_grep[0]); // Close the reading end of the first pipe
		close(pipe_grep_wc[0]);
		close(pipe_grep_wc[1]);
        dup2(pipe_ls_grep[1], STDOUT_FILENO); // Redirect standard output to the writing end of the first pipe
        close(pipe_ls_grep[1]); // Close the duplicated file descriptor

        // Execute "ls -la"
        execlp("ls", "ls", "-la", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    // Create the second child process to run "grep file" and read from the pipe
    grep_pid = fork();

    if (grep_pid == -1) {
        perror("fork grep");
        exit(EXIT_FAILURE);
    }

    if (grep_pid == 0) {
        // Child process: set up pipes
        close(pipe_ls_grep[1]); // Close the writing end of the first pipe
        dup2(pipe_ls_grep[0], STDIN_FILENO); // Redirect standard input from the reading end of the first pipe
        close(pipe_ls_grep[0]); // Close the duplicated file descriptor
        close(pipe_grep_wc[0]); // Close the reading end of the second pipe
        dup2(pipe_grep_wc[1], STDOUT_FILENO); // Redirect standard output to the writing end of the second pipe
        close(pipe_grep_wc[1]); // Close the duplicated file descriptor

        // Execute "grep file"
        char *args[] = {"grep", "file", NULL};
        execvp("grep", args);
        perror("execvp grep");
        exit(EXIT_FAILURE);
    }

    // Create the third child process to run "wc -l" and read its input
    wc_pid = fork();

    if (wc_pid == -1) {
        perror("fork wc");
        exit(EXIT_FAILURE);
    }

    if (wc_pid == 0) {
        // Child process: set up pipe
        close(pipe_grep_wc[1]); // Close the writing end of the second pipe
        dup2(pipe_grep_wc[0], STDIN_FILENO); // Redirect standard input from the reading end of the second pipe
        close(pipe_grep_wc[0]); // Close the duplicated file descriptor

        // Execute "wc -l"
        char *args[] = {"wc", "-l", NULL};
        execvp("wc", args);
        perror("execvp wc");
        exit(EXIT_FAILURE);
    }

    // Close all pipes in the parent process
    close(pipe_ls_grep[0]);
    close(pipe_ls_grep[1]);
    close(pipe_grep_wc[0]);
    close(pipe_grep_wc[1]);

    // Wait for all child processes to finish
    waitpid(ls_pid, NULL, 0);
    waitpid(grep_pid, NULL, 0);
    waitpid(wc_pid, NULL, 0);

    return 0;
}

