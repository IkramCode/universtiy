#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("P0: PID = %d, PPID = %d\n", getpid(), getppid());
    fflush(stdout);

    pid_t p1 = fork();
    if (p1 == 0) {
        printf("P1: PID = %d, PPID = %d\n", getpid(), getppid());
        fflush(stdout);

        pid_t p3 = fork();
        if (p3 == 0) {
            printf("P3: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        pid_t p4 = fork();
        if (p4 == 0) {
            printf("P4: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("P2: PID = %d, PPID = %d\n", getpid(), getppid());
        fflush(stdout);

        pid_t p5 = fork();
        if (p5 == 0) {
            printf("P5: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        pid_t p6 = fork();
        if (p6 == 0) {
            printf("P6: PID = %d, PPID = %d\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    return 0;
}
