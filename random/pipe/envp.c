#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]) {
    int i = 0;
    char* env_variable = envp[i];
/*    while (env_variable != NULL) {
        printf("%s\n", env_variable);
        i++;
        env_variable = envp[i];
    }
	i = 0;*/
	env_variable = envp[i];
    while (env_variable && strncmp(env_variable,"PATH",4)) {
    //    printf("%s\n", env_variable);
	
        i++;
        env_variable = envp[i];
    }
	printf("path found: %s\n",env_variable);
    return 0;
}
