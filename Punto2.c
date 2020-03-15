#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main (){
    ssize_t nro_bytes;
    int file = open("archivo.txt", O_WRONLY | O_CREAT);

    int id;
    id = fork();
    if (id == 0)
    {
        //sleep(5);
        char buf [23]= "El hijo acaba de editar";
        write(file, buf, 23);


        
        printf("%s %d \n", "Soy el hijo y mi identificador es: ", getpid());
        //printf("%d\n", (int)nro_bytes);
    }else
    {
        char buf [24]= "El padre acaba de editar";
        write(file, buf, 24);
        wait(NULL);
        
        printf("%s %d \n", "Soy el padre y mi identificador es: ", getpid());
    }  








    //nro_bytes = read(file, buf, 30);

    //close(file);

    //printf("\nEl número de bytes es: %d\nEl contenido es: %s\n", (int)nro_bytes, buf);
    printf("%d %d\n", file, getpid());
}