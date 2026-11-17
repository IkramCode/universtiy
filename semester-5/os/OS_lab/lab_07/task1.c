#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main (){
    int pid = fork();
    
    if(pid < 0) {
        perror("fork fialed");
        exit(1);
    }

    if(pid == 0){
        int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
        if(fd < 0){
            perror("couldnot open");
            exit(1);
        }

        if(dup2(fd, STDOUT_FILENO)< 0){
            perror("dup failed");
            exit(1);
        }

        close(fd);

        execlp("date", "date", NULL);
        perror("execlp failed");
        exit(1);
    }else{
        wait(NULL);
    }
    return 0;
}

