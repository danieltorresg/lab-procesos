#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main () {
    int x = 100;
    int id;
    id = fork();
    if (id == 0)
    {
        printf("%s %d \n", "El valor de x antes de cambiar en el hijo es: ", x);
        x = 101;
        printf("%s %d \n", "El valor de x en el hijo es: ", x);
        printf("%s %d \n", "Soy el hijo y mi identificador es: ", getpid());
        sleep(2);
    }else
    {
        wait(NULL);
        printf("%s %d \n", "El valor de x antes de cambiar en el padre es: ", x);
        x = 99;
        printf("%s %d \n", "El valor de x en el padre es: ", x);
        printf("%s %d \n", "Soy el padre y mi identificador es: ", getpid());
    }  
    
}
