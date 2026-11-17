#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){


    // ls / -R | grep 'std' | more
    // making program for this command

    int p1[2];
    int p2[2];

    pipe(p1);
    pipe(p2);

    if(fork() == 0){
        close(p2[0]);
        close(p2[1]);
        close(p1[0]);

        dup2(p1[1], 1);

        execlp("ls", "ls","/", "-R", NULL);
    }else {
        if(fork == 0){
            close(p1[1]);
            close(p2[0]);

            dup2(p1[0], 0);
            dup2(p2[1], 1);

            execlp("grep", "grep", "std", NULL);
        }else {
            if(fork() == 0){
                close(p1[0]);
                close(p1[1]);
                close(p2[1]);

                dup2(p2[0], 0);

                execlp("more", "more" , NULL);

            }else{
                close(p1[0]);
                close(p1[1]);
                close(p2[0]);
                close(p2[1]);

                wait(NULL);

            }
        }
    }



/*
    // creating two pipes 
    int fd1[2];
    pipe(fd1);

    if(fork() == 0){
        close(fd1[1]);
        int nums[2];
        read(fd1[0], nums, sizeof(nums));

        printf("child 1 writing: %d %d \n", nums[0],nums[1]);
        return 0;

    }else{

        int fd2[2];
        pipe(fd2);
            
        if(fork() == 0){
            close(fd2[0]);
            char msg[30] = "hello from child2";
            write(fd2[1], msg, sizeof(msg));

        } else {

            close(fd1[0]); // clsoing parent read end of first pipe it will write 
            int nums[3] = {1,2,3};
            write(fd1[1], nums, sizeof(nums));

            close(fd2[1]); // closing parent write end for first pipe it will read
            char msg[30];
            read(fd2[0], msg, sizeof(msg));
            printf("parent printing: %s", msg);

        }
    }
*/

/*

    // ls | sort program
    int fd[2];
    pipe(fd);

    if(fork() == 0){
        // mapping read end of pipe to std input
        dup2(fd[0], 0);
        close(fd[1]);

        execlp("sort", "sort", "-r", NULL);

    }else{
        // mapping wirte end of pipe to std output
        dup2(fd[1], 1);
        // good practise to close unsed pipes
        close(fd[0]);

        execlp("ls", "ls", NULL);
    }
    */
}
