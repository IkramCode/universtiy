#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        for (int i = 0; i < 6; i++) {
            printf("Child second %d: PID = %d, PPID = %d\n", i, getpid(), getppid());
            sleep(1);
        }
        exit(0);
    } else {
        printf("Parent PID = %d, exiting in 2 seconds\n", getpid());
        sleep(2);
        exit(0);
    }
}

