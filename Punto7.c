#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    int id;
    id = fork();
    if (id == 0)
    {
        printf("Id del hijo: %d\n", getpid());
        fclose(stdout);
        printf("Intendo de impresión después de cerrar salida estandar");
        
    }else
    {
        printf("Id del padre: %d\n", getpid());
    } 
}