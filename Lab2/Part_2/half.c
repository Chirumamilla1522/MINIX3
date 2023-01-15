
#include <sys/wait.h>  //for waitpid()
#include <unistd.h>    //for chdir(), fork(), exec(), pid_t
#include <stdlib.h>    //for malloc(), realloc(), free(), exit(), execvp(), EXIT_FAILURE, EXIT_SUCESSS
#include <stdio.h>     //for stderr, getchar(), perror(), printf(), scanf()
#include <string.h>    //for strcmp(), strtok()
#include <sys/types.h> //for pid, exec() stuff

#include <stdlib.h>

int main(int argc, char **argv)
{
    char **cmd = malloc(1024 * sizeof(char *));
    int i;

    for (int i = 1; i < argc; i++)
        cmd[i - 1] = argv[i];
    cmd[i - 1] = NULL;

    int a = atoi(cmd[argc - 2]);
    a = a / 2;

    sprintf(cmd[argc - 2], "%d", a);

    if (cmd[1] == NULL)
    {
        printf("%s\n", cmd[argc - 2]);
        exit(0);
    }

    char str[80];
    strcpy(str, "./");
    strcat(str, cmd[0]);
    cmd[0] = str;

    printf("PID of %s: %d\n", cmd[0], getpid());
    if (execvp(cmd[0], cmd) < 0)
    {
        printf("cmd failed\n");
        exit(0);
    }

    return 0;
}