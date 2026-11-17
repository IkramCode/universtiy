#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t c1, c2, g1;

    printf("P: PID = %d, PPID = %d\n", getpid(), getppid());

    c1 = fork();

    if (c1 == 0){
        printf("C1: PID = %d, PPID = %d\n", getpid(), getppid());

        g1 = fork();
        if (g1 == 0){
            printf("G1: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        waitpid(g1, NULL, 0);
        exit(0);
    }
    else{
        c2 = fork();

        if (c2 == 0) {
            printf("C2: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        waitpid(c1, NULL, 0);
        waitpid(c2, NULL, 0);
    }

    return 0;
}

