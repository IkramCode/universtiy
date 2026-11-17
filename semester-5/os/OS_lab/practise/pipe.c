#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(){
    int fd[2];
    pipe(fd);

    if(fork() == 0){
        
        int nums[] = {10,20,30};
        int len = sizeof(nums);
        close(fd[0]);

        write(fd[1], &len, sizeof(len));
        write(fd[1], nums, len);
    }else{
        close(fd[1]);
        int len;
        read(fd[0], &len, sizeof(len));

        void* data = malloc(len);
        read(fd[0], data, len);

        int *p = (int *)data;
        for(int i = 0; i < len/sizeof(int); i++){
            printf("%d ", p[i] );
        }
    }


    // if(fork() == 0){
    //     char arr[10];
    //     read(fd[0], arr, 10);
    //     printf("%s", arr);
    //
    // }else{
    //     int message[] = {1,2,3};
    //     int length = sizeof(message) / sizeof(message[0]);
    //     write(fd[1], message, length);
    //     wait(NULL);
    // }
}
