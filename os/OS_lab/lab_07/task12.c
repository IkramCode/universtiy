#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { fprintf(stderr, "Usage: %s \"string\"\n", argv[0]); return 1; }
    int fd[2];
    if (pipe(fd) == -1) { perror("pipe"); exit(1); }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {                        /* child: counts */
        close(fd[1]);
        char buf[256];
        ssize_t n = read(fd[0], buf, sizeof(buf) - 1);
        buf[n > 0 ? n : 0] = '\0';
        int v = 0, c = 0;
        for (int i = 0; buf[i]; i++) {
            if (!isalpha((unsigned char)buf[i])) continue;   /* skips spaces etc. */
            char ch = tolower((unsigned char)buf[i]);
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') v++; else c++;
        }
        printf("Vowels: %d\nConsonants: %d\n", v, c);
        close(fd[0]);
        exit(0);
    }
    close(fd[0]);                          /* parent: sends */
    write(fd[1], argv[1], strlen(argv[1]) + 1);
    close(fd[1]);
    wait(NULL);
    return 0;
}
