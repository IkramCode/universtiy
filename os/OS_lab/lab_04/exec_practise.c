#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main () {
    pid_t pid = fork();

    if (pid == 0){
        char* args[] = {"env", NULL};
        char* envp[] = {"MYVAR=HELLO", "MYNAME=IKRAM",NULL};
        execve("/usr/bin/env",args,envp);

    }
    waitpid(pid, NULL, 0);       // wait so output isn't mixed with your prompt
    return 0;
}
