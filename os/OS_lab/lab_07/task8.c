#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); exit(1); }
    const char *msg = "Operating Systems";
    char buf[100];

    ssize_t w = write(fd[1], msg, strlen(msg) + 1);   /* include '\0' -> 18 bytes */
    printf("Wrote %zd bytes\n", w);
    ssize_t r = read(fd[0], buf, sizeof(buf));
    printf("Read %zd bytes: %s\n", r, buf);

    close(fd[0]); close(fd[1]);
    return 0;
}
