#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* itoa(int val, int base){
    
    static char buf[32] = {0};    
    int i = 30;    
    for(; val && i ; --i, val /= base)    
        buf[i] = "0123456789abcdef"[val % base];   
    return &buf[i+1];
    
}
int main(int argc, char *argv[])
{
    if (argc == 1)
        return 0;
    char *result = argv[argc - 1];
    int num = atoi(argv[argc - 1]);
    sprintf(result, "%d", (num * num));
    printf("Square: Current process id: %d, Current result: %s\n", getpid(), result);
    char *arg[argc];
    for (int i = 0; i < (argc - 2); i++)
        arg[i] = argv[i + 1];
    arg[argc - 2] = result;
    arg[argc - 1] = NULL;
    execvp(arg[0], arg);
}
