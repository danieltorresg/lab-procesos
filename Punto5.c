#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    int id;
    id = fork();
    int waitHijo;
    int waitPadre;
    if (id == 0)
    {
        waitHijo = wait(NULL);
        printf("Retorno wait del hijo(%d): %d\n", getpid(), waitHijo);
        
    }else
    {
        waitHijo = wait(NULL);
        printf("Retorno wait del padre(%d): %d\n", getpid(), waitHijo);
    } 
}