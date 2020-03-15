# PRÁCTICA 1 - PROCESOS #

## Daniel Santa rendón - 1040050021
## Daniel Torres González - 1020492000

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. ¿Cuál es el valor de retorno de la función ```wait()```?, ¿Qué pasa si usted usa la función ```wait``` en el hijo?
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

## 3. Entregable ##

Los entregables para esta practica incluiran:
1. Codigo de los ejercicos propuestos.
2. Solución a las preguntas planteadas. apoyar la explicación con graficas donde lo vea necesario.

# Respuestas #

## 1)
- El valor de la variable en el proceso hijo es 100
- Antes de cambiarlo, para ambos procesos, el valor es 100, 
cada variable cambia únicamente en su proceso

## 2)
- Sí, cada uno puede acceder al file descriptor y funcionar con el, ambos editan el mismo archivo
- No hay  una forma concurrente de esscribir a la misma vez, lo más cercano es que uno escriba
inmediatamente desoués que el otro, ahí, lo que sicede es que ambos escriben en el mismo archivo
pero en el mimsmo orden de instrucciones.

## 3)
- Sí, se puede hacer usando la función sleep, esta función detiene un momento el proceso padre y
el hijo termina su ejecución poniendo "Hello" antes que "Goodbye"

## 4)
Existen tantas variantes de esta llamada básica pues se satisface la necesidad de como pasar los 
argumentos al fichero que se va a ejecutar, también, de la forma en que el sistema encuentra el 
nombre del archivo que ejecuta. Por ejemplo, para las funciones execlp, execl y execle los 
argumentos se entregan de manera individual a al método del fichero. Mientras que para execve, 
execv y execvp lo parámetros son pasados como un arreglo de apuntadores.Para las funciones execve
y execle, se le agrega, además, un arreglo de apuntadores a las variables de entorno. 
Por otro lado, las funciones execvp y execlp, para encontrar el nombre del archivo path pasado 
como argumento, utilizan la variable de entorno PATH.

## 5)
- El valor de retorno del wait es el PID del proceso  hijo
- Al ejecutarse la función wait en un proceso sin hijos, esta retornará -1

## 6)
- Se puede usar cuando se tiene más de un hijo y se debe esperar hasta que finalice la ejecución de uno
o varios de ellos, esto facilita para dar un orden a la lista de procesos padre e hijos

## 7)
- Fracasa el intento al usar la función printf porque el descriptor está cerrado, pero continúa su 
ejecución sin ningún inconveniente
