#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{

    if (access(argv[1], R_OK) != -1)
        printf("I have permission\n");
    else
	{
        printf("I don't have permission\n");
	}

	perror("Status");
	printf("test errmsg %s",strerror(errno));
    return (0);
}
