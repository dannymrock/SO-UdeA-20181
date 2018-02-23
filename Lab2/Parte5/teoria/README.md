# Memoria dinamica en C

## 1. Introduccion

Comentarios

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
| Stack  | v, pi |
| Heap  | --- |

En la siguiente figura se muestra mas claramente esta reacion con el esquema mostrado en la figura 1:

![mmap_program](./imagenes/memoria_ambas2.png)
**Figura 2**. Asignacion de las variables en el espacio de memoria.

En la figura anterior, se puede ver que no hay variables en el **heap** pues no se hicieron asignaciones dinamicas de memoria el cual sera el proximo tema a tratar.




