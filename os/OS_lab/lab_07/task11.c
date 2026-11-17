#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); exit(1); }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {                        /* child: reader */
        close(fd[1]);                      /* MUST close write end, otherwise read() never returns 0 */
        char buf[100];
        ssize_t n;
        int total = 0;
        while ((n = read(fd[0], buf, sizeof(buf))) > 0) {
            printf("Child read %zd bytes: %s\n", n, buf);
            total += n;
        }
        printf("Total bytes read: %d\n", total);
        close(fd[0]);
        exit(0);
    }
    close(fd[0]);                          /* parent: writer */
    const char *words[] = {"red", "green", "blue"};
    for (int i = 0; i < 3; i++) {
        write(fd[1], words[i], strlen(words[i]) + 1);
        sleep(1);
    }
    close(fd[1]);                          /* signals EOF to the child */
    wait(NULL);
    return 0;
}
