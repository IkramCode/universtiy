#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

int main () {
    pid_t child1 = fork();

    if(child1 < 0){
        fprintf(stderr, "Error: fork couldnot be created\n");
    }
    if(child1 == 0){
        execl("/bin/echo", "echo", "Hello world", NULL);
        perror("child 1 exec failed");
        exit(1);
    }

    pid_t child2 = fork();
    if(child2 < 0){
        fprintf(stderr, "Error: fork couldnot be created\n");
    }
    if(child2 == 0){
        char* args[] = {"wc", "-l", "/etc/passwd", NULL};
        execv("/usr/bin/wc", args);
        perror("child 2 exec failed");
        exit(1);
    }

    pid_t child3 = fork();
    if(child3 < 0){
        fprintf(stderr, "Error: fork cannot be created\n");
    }
    if(child3 == 0){
        execlp("/bin/ls", "ls", "-l", NULL);
        perror("child 3 exec failed");
        exit(1);
    }

    pid_t child4 = fork();
    if(child4 < 0){
        fprintf(stderr, "Error: fork cannot be created\n");
    }
    if(child4 == 0){
        char *env[] = {"MODE=test", "USER=ikram", NULL};
        execle("/usr/bin/env", "env", NULL, env);
        exit(1);
    }

    pid_t pids[] = {child1, child2, child3, child4};

    for(int i = 0; i < 4; i++){
        int status;
        pid_t done = waitpid(pids[i], &status , 0);

        if (WIFEXITED(status))
            printf("child %d (pid %d) exited with status %d\n", i + 1, done, WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            printf("child %d (pid %d) killed by signal %d\n", i + 1, done, WTERMSIG(status));
    }
}

