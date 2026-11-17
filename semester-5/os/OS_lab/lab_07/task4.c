#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int p[3][2];
    for (int i = 0; i < 3; i++)
        if (pipe(p[i]) == -1) { perror("pipe"); exit(1); }

    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();
        if (pid < 0) { perror("fork"); exit(1); }
        if (pid == 0) {
            if (i > 0)  dup2(p[i-1][0], STDIN_FILENO);   /* read from previous pipe */
            if (i < 3)  dup2(p[i][1], STDOUT_FILENO);    /* write to next pipe */
            for (int k = 0; k < 3; k++) { close(p[k][0]); close(p[k][1]); }
            switch (i) {
                case 0: execlp("cat",  "cat", "names.txt", (char *)NULL); break;
                case 1: execlp("sort", "sort", (char *)NULL); break;
                case 2: execlp("uniq", "uniq", "-c", (char *)NULL); break;
                case 3: execlp("sort", "sort", "-rn", (char *)NULL); break;
            }
            perror("exec"); exit(1);
        }
    }
    for (int k = 0; k < 3; k++) { close(p[k][0]); close(p[k][1]); }
    for (int i = 0; i < 4; i++) wait(NULL);
    return 0;
}
