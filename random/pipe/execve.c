#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	char *const argv[] = { "awk", "-F:", "{print $1}", "/etc/passwd", NULL };
    execve("/bin/awk", argv, NULL);
    printf("This line will not be executed.\n");
*/
	char* a;

	a = malloc(0);
	free(a);
	a = NULL;
	free(a);
    return (0);
}
