#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
    pid_t p1 = fork();
    pid_t p2 = fork();
    pid_t p3 = fork();

    if(p1 < 0){
        perror("p1 failed\n");
    }
    if(p1 > 0){
        wait(NULL);
        printf("parent 1 pid: %d \n",getpid());
        printf("child of p1 pid: %d \n",p1);
    }

    if(p2 < 0){
        perror("p2 failed\n");
    }
    if(p2 > 0){
        wait(NULL);
        printf("parent 2 pid: %d \n",getpid());
        printf("child of p2 pid: %d \n",p2);
    }

    if(p3 < 0){
        perror("p2 failed\n");
    }
    if(p3 > 0){
        wait(NULL);
        printf("parent 3 pid: %d \n",getpid());
        printf("child of p3 pid: %d \n",p3);
    }
    return 0;
}
