#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

int main () {
    int p1[2];
    int p2[2];

    pipe(p1);
    pipe(p2);

    if(fork() == 0){
        close(p1[0]);
        close(p2[0]);
        close(p2[1]);

        int err_fd = open("error.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(err_fd, 2);
        dup2(p1[1], 1);

        execlp("ls", "ls", "-l", NULL);

    }else{
        if(fork() == 0){
            close(p1[1]);
            close(p2[0]);

            dup2(p1[0], 0);
            dup2(p2[1], 1);

            execlp("grep", "grep", "txt", NULL);

        }else{
            if(fork() == 0){
                close(p1[0]);
                close(p1[1]);
                close(p2[1]);

                int out_fd = open("unique.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
                dup2(out_fd, 1);
                dup2(p2[0], 0);

                execlp("uniq", "uniq", NULL);

            }else{
                wait(NULL);
            }
        }
    }
}
