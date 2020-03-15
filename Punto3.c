#include <stdio.h>
#include <unistd.h>

int main () {
    int id;
    id = fork();
    if (id == 0)
    {
        printf("%s \n", "Hello ");
        
    }else
    {
        sleep(2);
        printf("%s \n", "Goobye ");        
    } 
}