#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
    pid_t pid = fork();

    if (pid < 0){
        printf("fork failed\n");
    }

    if(pid > 0){
        printf("parent of childs: %d \n",getpid());
        printf("child one pid: %d \n",pid); 

        pid_t pid1 = fork();

       if(pid1 > 0){
           printf("second child pid: %d \n",pid1);
           pid_t pid2 = fork();
           if(pid2 > 0){
               printf("third child pid: %d \n",pid2);
           } 
       } 
    }

}
