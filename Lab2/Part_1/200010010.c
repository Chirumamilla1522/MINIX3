#include <stdio.h> 
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h> 
#include <unistd.h> 
int main(){
    char string[] = "Hello World";
    int index, pid = 0;
    for (index=0; index < 11; index++){
        if(pid == 0){
            printf("%c %d\n",string[index], getpid());
	        sleep((rand()%4) + 1); 
            pid = fork();
        }
    }
    wait(NULL);
    return 0;
}