#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
    int arr[5] = {1,2,3,4,5};
    pid_t pid = fork();
    
    if(pid < 0){
        perror("fork cannot be makde \n");
        return 1;
    }

    if (pid == 0){
        for(int i = 0; i < 5; i++){
            arr[i] = arr[i] * arr [i];
        }
    printf("\nArray printing... \n");
    for(int i = 0; i < 5; i++){
        printf(" %d ",arr[i]);
    }
    printf("\n child pid :%d",getpid());
    printf("\n child parent id: %d",getppid());

    }else{
        wait(NULL);
        printf("\nArray printing in parent... \n");
        for(int i = 0; i < 5; i++){
            printf(" %d ",arr[i]);
    }
    printf("\n parent pid :%d",getpid());
    printf("\n child id: %d",pid); 
    }
}

