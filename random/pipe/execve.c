#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    //execve("/bin/awk",argv+1,NULL);
    //printf("This line will not be executed.\n");

/*	char* a;

	a = malloc(0);
	free(a);
	a = NULL;
	free(a);*/
	char *arg[3] = {"ls","-l",NULL};
	execve("/usr/bin/ls", arg,NULL);
    return (0);
}
