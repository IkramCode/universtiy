#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { fprintf(stderr, "Usage: %s n\n", argv[0]); return 1; }
    int n = atoi(argv[1]);
    int p2c[2], c2p[2];
    if (pipe(p2c) == -1 || pipe(c2p) == -1) { perror("pipe"); exit(1); }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {                        /* child */
        close(p2c[1]); close(c2p[0]);
        int num;
        read(p2c[0], &num, sizeof(num));
        long long fact = 1;
        for (int i = 2; i <= num; i++) fact *= i;
        write(c2p[1], &fact, sizeof(fact));
        close(p2c[0]); close(c2p[1]);
        exit(0);
    }
    close(p2c[0]); close(c2p[1]);          /* parent */
    write(p2c[1], &n, sizeof(n));
    close(p2c[1]);
    long long result;
    read(c2p[0], &result, sizeof(result));
    close(c2p[0]);
    printf("Factorial of %d is %lld\n", n, result);
    wait(NULL);
    return 0;
}
