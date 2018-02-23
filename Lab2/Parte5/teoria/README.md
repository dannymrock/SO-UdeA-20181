# Memoria dinamica en C

## 1. Introduccion

En los programas tipicos, la cantidad de memoria que usaran es desconocida, por ejemplo, cuando alguien emplea un editor de texto nunca sabe cuantas paginas va a escribir. Como el numero de paginas suele estar relacionada con elementos de memoria como matrices presuponer un numero maximo de paginas suele ser ineficiente, pues ello implicaria dos cosas:
1. Que se tenga gran cantidad de memoria osiosa si el usuario del editor no escribe en todas las paginas reservadas por la aplicacion.
2. Que el usuario se quede corto de paginas si escribe mucho, pues al tener el editor de texto el numero de paginas predefinido, es posible que el espacio en memoria no sea suficiente para lo que el usuario escribe.

Para dar administrar la memoria de manera mas eficiente, C permite introduce el concepto de **reserva dinamica de memoria** que no otra cosa que el proceso de gestion de memoria en tiempo de ejecución segun las necesidades demandadas por la aplicacion. Gracias a esto, es posible que no sea necesario que el editor de texto conozca con antelacion el numero de paginas que debe escribir el usuario, pues gracias a la gestion dinamica de memoria, el editor puede ir creando nuevas paginas a medida que el usuario va demandandolo. En esta seccion se verá las funciones que son empleadas en C para hacer esto posible.

## 2. Espacios de memoria

De manera resumida la memoria de datos de un programa en C puede ser dividida en tres partes:
1. **Memoria estatica**: en esta se localizan todas las variables globales (aquellas que son definidas fuera de funciones),
tambien se localizan las variables locales (definidas dentro de funciones) que son explicitamente declaradas como estaticas.
2. **Stack**: lugar de la memoria en el cual se definen las variables locales (variables automaticas (no estaticas) declaradas dentro 
de la funcion), los parametros de las funciones y los valores retornados por las funciones.
3. **Heap**: lugar de la memoria disponible para asignacion dinamica (en tiempo de ejecicion) de memoria. 

La siguiente figura resalta los espacios anteriormente descritos:

![mmap](./imagenes/memory_map3.png)
**Figura 1**. Mapa de memoria

Para clarificar un poco lo anterior supongamos que se codifica el siguiente [programa](https://goo.gl/Z16WF6) en C:

```C
#include <stdio.h>

int x=5;
char msg[] = "Hello";

int main(int argc, const char* argv[]) {
  int v;
  float pi = 3.14159;
  printf("%d\n",x);
  printf("%f\n",pi);
  return 0;
}

```

Cuya salida al ejecutar el programa se muestra en la siguiente figura:

![fig_exe](./imagenes/variables_memoria.png)

Como se puede ver de la figura anterior, se resaltan los espacios de memoria y las variables que se encuentran en estos:

| Espacio de memoria | Variables |
| ------------- | ------------- |
| Memoria estatica | x, msg  |
| Stack  | argc, argv, v, pi |
| Heap  | --- |

En la siguiente figura se muestra mas claramente esta reacion con el esquema mostrado en la figura 1:

![mmap_program](./imagenes/memoria_ambas2.png)
**Figura 2**. Asignacion de las variables en el espacio de memoria.

En la figura anterior, se puede ver que no hay variables en el **heap** pues no se hicieron asignaciones dinamicas de memoria el cual sera el proximo tema a tratar.

## 3. Asignando memoria


## x. Enlaces
* https://www.berthon.eu/wiki/foss:wikishelf:linux:memory
* http://resources.infosecinstitute.com/system-address-map-initialization-in-x86x64-architecture-part-1-pci-based-systems/#gref
* https://fypandroid.wordpress.com/2011/01/17/anatomy-of-a-program-in-memory/
* https://www.securitysift.com/windows-exploit-development-part-1-basics/
* https://www.ibm.com/developerworks/library/j-nativememory-linux/
* https://gabrieletolomei.wordpress.com/miscellanea/operating-systems/in-memory-layout/
* http://www.cs.utexas.edu/users/fussell/cs310h/lectures/Lecture_17-310h.pdf
* https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-087-practical-programming-in-c-january-iap-2010/lecture-notes/




