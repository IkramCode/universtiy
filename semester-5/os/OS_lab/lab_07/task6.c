#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); exit(1); }

    if (fork() == 0) {                 /* child 1: writer */
        close(fd[0]);
        const char *msg = "Hello from sibling 1";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
        exit(0);
    }
    if (fork() == 0) {                 /* child 2: reader */
        close(fd[1]);
        char buf[100];
        read(fd[0], buf, sizeof(buf));
        printf("Sibling 2 received: %s\n", buf);
        close(fd[0]);
        exit(0);
    }
    close(fd[0]); close(fd[1]);
    wait(NULL); wait(NULL);
    return 0;
}
