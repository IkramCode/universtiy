#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char* argv[]) {
        
    if(argc != 2){
        fprintf(stderr, "Error: arguments must be only one\n");
        return 1;
    }

    int n;
   if (sscanf(argv[1], "%d", &n) != 1) {
        fprintf(stderr, "Error: arguments must be integers\n");
        return 1;
     }


   for(int i = 0; i < n; i++){
       pid_t pid = fork();
       if(pid == 0){ 
           printf("child pid %d : %d \n",i+1,getpid());
           return 0;
       }else if(i == n-1){
           wait(NULL);
           printf("parent pid: %d \n",getpid()); 
       }
   }

    return 0;
}
