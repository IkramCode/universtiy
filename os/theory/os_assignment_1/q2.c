#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (){
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0){
        execlp("ls", "ls", "-l", NULL);
        perror("exec failed");
        exit(1);
    }else{
        int status;
        wait(&status);
        if (WIFEXITED(status))
            printf("Child execution completed. Exit code = %d\n", WEXITSTATUS(status));
    }
    return 0;
}
