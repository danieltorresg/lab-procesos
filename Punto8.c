#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t id1 = fork();
    char buff1 [5];
    char buff2 [5];
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);
    int num1;
    int num2;



    if(id1 == 0){
        pid_t id2 = fork();
        if (id2 == 0)
        {
            close(fd1[0]);
            close(fd2[1]);
            write(fd1[1], "abcde", 5); 
            close(fd1[1]);

            num2 = read(fd2[0], buff2, 5);
            printf("El padre lee %d bytes y el mensaje es: %s\n", num2, buff2);
            close(fd2[0]);


        }else
        {
            close(fd1[1]);
            close(fd2[0]);
            num1 = read(fd1[0], buff1, 5);
            printf("El hijo lee %d bytes y el mensaje es: %s\n", num1, buff1);
            close(fd1[0]);

            write(fd2[1], "edcba", 5); 
            close(fd2[1]);
        }
        



    }
    
    
}