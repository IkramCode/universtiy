/* Task 9: Child writes, parent reads */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { fprintf(stderr, "Usage: %s string\n", argv[0]); return 1; }
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); exit(1); }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {                        /* child: sender */
        close(fd[0]);
        write(fd[1], argv[1], strlen(argv[1]) + 1);
        close(fd[1]);
        exit(0);
    }
    close(fd[1]);                          /* parent: reader */
    char buf[256];
    ssize_t n = read(fd[0], buf, sizeof(buf));
    printf("Parent read %zd bytes: %s\n", n, buf);
    close(fd[0]);
    wait(NULL);
    return 0;
}
