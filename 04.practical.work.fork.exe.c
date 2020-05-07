#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    if(pid == 0){
        int pid0 = fork();
        if(pid0 == 0){
            printf("I am child after fork()");
            char *args[] = {"/bin/free", "-h", NULL};
            execvp("/bin/free", args);
        }
        else
        {
            wait(NULL);
            printf("I am parent before fork(), the child id %d", pid0);
        }
        printf("I am child after fork\n");
        char *args[] = {"/bin/ps", "-ef", NULL};
        execvp("/bin/ps", args);
    }
    else
    {
        wait(NULL);
        printf("I am parent before fork, the child id %d\n", pid);
    }
    return 0;

}