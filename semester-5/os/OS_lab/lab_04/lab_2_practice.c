// orphan.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // child
        printf("Child: PID %d, parent PID %d\n", getpid(), getppid());
        sleep(5);   // give the parent time to die
        printf("Child: PID %d, new parent PID %d\n", getpid(), getppid());
        sleep(30);  // stay alive so you can inspect it
        exit(0);
    }

    // parent exits right away
    printf("Parent (PID %d) exiting\n", getpid());
    exit(0);
}
