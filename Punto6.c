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
        printf("Retorno wait del hijo(%d): %d\n", getpid(), waitHijo);
        
    }else
    {
        waitHijo = waitpid(id,0,0);
        printf("Retorno wait del padre(%d): %d\n", getpid(), waitHijo);
    } 
}