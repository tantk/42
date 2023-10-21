#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]) {
    int i = 0;
    char* env_variable = envp[i];
    while (env_variable != NULL) {
        printf("%s\n", env_variable);
        i++;
        env_variable = envp[i];
    }
    return 0;
}
