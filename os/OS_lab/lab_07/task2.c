#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

int main (){
    int pid = fork();
    if(pid < 0){
        perror("fork failed");
        exit(1);
    }

    if(pid == 0){
        int in_fd = open("names.txt", O_RDONLY); 
        if(in_fd < 0){
            perror("open failed");
            exit(1);
        }

        dup2(in_fd, STDIN_FILENO);
        close(in_fd);

        int out_fd = open("sorted.txt", O_WRONLY| O_CREAT| O_TRUNC, 0644);
        if(out_fd < 0){
            perror("out failed");
            exit(1);
        }

        dup2(out_fd, STDOUT_FILENO);
        close(out_fd);

        execlp("sort", "sort", NULL);
        perror("exec failed");
        exit(1);

    }else{
        wait(NULL);
    }
    return 0;
}
