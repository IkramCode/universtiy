#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}

int calculate_sum(int n){
    if(n <= 0){
        return 0;
    };
    return n + calculate_sum(n-1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int n;
    if (sscanf(argv[1], "%d", &n) != 1) {
        fprintf(stderr, "Error: enter an integer\n");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        return 1;
    }
    if (pid1 == 0) {
        exit(is_prime(n) ? 1 : 0);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        return 1;
    }
    if (pid2 == 0) {
        exit(calculate_sum(n));  
    }

    pid_t pid3 = fork();
    if (pid3 < 0) {
        perror("fork");
        return 1;
    }
    if (pid3 == 0) {
        volatile int *ptr = NULL;
        *ptr = 5;
    }

    pid_t pids[] = {pid1, pid2, pid3};
    for (int i = 0; i < 3; i++) {
        int status;
        pid_t done = waitpid(pids[i], &status, 0);

        // WIFEXITED returns a bool true if the child exited normally. 
        if (WIFEXITED(status)) {

            printf("Child %d (PID %d) exited normally, exit code %d\n",

                    // WEXITSTATUS checks and tell what is the exit code does not truncate to 8 bit
                   i + 1, done, WEXITSTATUS(status));

            // WIFSIGNALED checks if the child was killed by a sginal like in our case killed by one.
        } else if (WIFSIGNALED(status)) {
            printf("Child %d (PID %d) killed by signal %d\n",

                    // WTERMSIG prints the signal value that killed it.
                   i + 1, done, WTERMSIG(status));
        }
    }

    return 0;
}
