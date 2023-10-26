#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
        printf("This is the child process. (pid: %d)\n", getpid());
    else
	{
		printf("pid in parent %d\n",pid);
        printf("This is the parent process. (pid: %d)\n", getpid());
	}
    return (0);
}
