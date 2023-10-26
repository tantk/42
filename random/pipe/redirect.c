#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // Open the file for reading (you can open it with other flags if needed)
    int file_descriptor = open(argv[1], O_RDONLY);

    if (file_descriptor == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Redirect standard input (stdin) to the file descriptor
    if (dup2(file_descriptor, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }

    // Close the original file descriptor
    close(file_descriptor);

    // Prepare the arguments for execve
    char *const cmd[] = {"wc", "-l", NULL};

    // Execute the wc -l command to count lines
    if (execve("/usr/bin/wc", cmd, NULL) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }

    // This code will not be executed if execve is successful
    return 0;
}

