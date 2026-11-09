#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
    pid_t pid1 = fork();

    if(pid1 == 0){
        printf("Parrent of first child: %d \n", getppid());
        execlp("date", "date", NULL);
        perror("exec date failed \n");
        exit(1); 
    }

    pid_t pid2 = fork();

    if(pid2 == 0){
        printf("Parrent of second child: %d \n", getppid());
        execlp("whoami", "whoami", NULL);
        perror("exec whoami failed \n");
        exit(1); 
    }

    wait(NULL);
    wait(NULL);

    printf("Both child processes have completed successfully.\n");
}
