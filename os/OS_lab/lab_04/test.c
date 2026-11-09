#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (){
    
    // creatting a fork for the first time   
    // // printf("before fork pid: %d \n", getpid());
    // int pid = fork();
    // // printf("after fork pid: %d \n", getpid());
    //
    //
    // if(pid == 0){
    //     printf("child");
    //     printf("\n");
    // }else if (pid == -1){
    //     printf("error");
    // }else{
    //     printf("parent of %d",pid);
    //     printf("\n");
    // }
    //
    //

    // waiting for the child
    // int status;
    // int pid = fork();
    //
    // if(pid == 0){
    //     printf("child working \n");
    //     sleep(2);
    //     printf("child done\n");
    //     exit(7);
    // }else{
    //     wait(&status);
    //     if(WIFEXITED(status))
    //         printf("parent: child exited with status %d", WEXITSTATUS(status));
    // }
    //
    //

    // exec commands
    printf("before exec: PID = %d\n", getpid());
    char* args[] = {"ls", "-l", NULL};
    // execl("/bin/ls", "ls",NULL);
    // execlp("ls","banana","-l",NULL);
    // execv("/bin/ls", args);
    execvp("ls", args);
    perror("exec failed to run");

    return 1;
}
