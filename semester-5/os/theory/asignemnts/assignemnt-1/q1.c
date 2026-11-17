#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
   pid_t pid = fork(); 
   
   if(pid == 0){
       printf("child process created. PID: %d \n, Parent id : %d",getpid(), getppid());
       printf("child running... \n");
       sleep(3);
       printf("child finished \n");
       exit(0);
   }else {
      int status;
      printf("parent process started. %d \n", getpid());
    
      while(waitpid(pid, &status, WNOHANG) == 0){
              printf("parent is waiting \n");
              sleep(1);
          }
      printf("Parent Detected child termination.\n");

      }
   return 0;
}

