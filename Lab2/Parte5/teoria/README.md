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

Para tratar esta parte abordemos un problema tipico para ver las diferentes formas de solucion desde el punto de vista del manejo de memoria. Supongase que se desean ingresar un conjunto de datos asociados con la temperatura a lo largo del dia, el ingreso de estos datos se hace de manera manual leyendo el numero de registros manuales existentes en una planilla para luego ingresarlos al sistema. Hacer un programa que facilite esta tarea.

Existen diferentes maneras de asignar memoria:
* **Forma 1**: Declarar un arreglo estatico de tamaño fijo, asumientod que el numero de registros a ingresar nunca va a ser mayor que el tamaño fijo previamente definido. Esta forma de declaración es **estatica** por que la reserva de memoria (arreglo) se hace en tiempo de compilación.

```C
#include <stdio.h>

#define NUM_MAX_REG 100

int main() {
  float datos[NUM_MAX_REG]; // Se supone que no se van a ingresar mas de 100 registros
  float reg;
  int numReg;
  printf("Ingrese la cantidad de registros a leer: ");
  scanf("&d",numReg);
  if (numReg > NUM_MAX_REG) {
    printf("ERROR: solo se pierden %d datos\n", numReg - NUM_MAX_REG);
    numReg = NUM_MAX_REG;
  } 
  for(int i = 0; i < numReg; i++) {
    printf("Dato[%d]: ", i);
    scanf("%f", &reg);    
    *(datos + i) = reg;
  } 
  return 0;
}
```

Como se podra notar, la forma anterior es ineficiente por razones similares a las expuestas en la introducción.

* **Forma 2**: Declarar un arreglo dinamico (automatico) de un tamaño especificado en tiempo de ejecución. El siguiente codigo ilustra esta idea:

```C
#include <stdio.h>

int main() {
  float reg;
  int numReg;
  printf("Ingrese la cantidad de registros a leer: ");
  scanf("&d",numReg);
  float datos[numReg];
  for(int i = 0; i < numReg; i++) {
    printf("Dato[%d]: ", i);
    scanf("%f", &reg);    
    *(datos + i) = reg;
  } 
  return 0;
}
```

El problema de la forma anterior es que el compilador es previo a C99, no permite declarar un arreglo definiendo su tamaño a partir de una variable (siendo **numReg**) para el caso.

* **Forma 3**: Declarar un arreglo dinamico de un tamaño especificado en tiempo de ejecución empleando las funciones propias de la libreria estandar para tal caso (```malloc``` y ```calloc```). En lo que respecta al caso, esta es la mejor forma. La descripción y uso de estas funciones sera tratada en breve. Por ahora veamos el codigo asociado.

```C
#include <stdio.h>

int main() {
  float *datos;
  float reg;
  int numReg;
  printf("Ingrese la cantidad de registros a leer: ");
  scanf("&d",numReg);
  datos = (float *)malloc(numReg*sizeof(float));
  if (pF != NULL) {
    for(int i = 0; i < numReg; i++) {
      printf("Dato[%d]: ", i);
      scanf("%f", &reg);    
      *(datos + i) = reg;
  } 
  free(datos);
  return 0;
}
```

A continuacion, en los siguientes ejemplos se muestra la diferencia entre declarar una variable en el stack y declararla en el heap usando reserva dinamica de memoria.

### Ejemplos

1. Simule y analise los codigos 1 y 2 mostrados a continuacion. Pese a que logicamente hacen lo mismo, ¿Cual es la principal diferencia entre estos?

**Codigo 1**: [Codigo online](https://goo.gl/2kyQTR)

```C
#include <stdio.h>

int main() {
  int a;
  int *p = &a;
  *p = 5;
  printf("*p = %d\n", *p);
  return 0;
}
```

IMAGEN

**Codigo 2**: [Codigo online](https://goo.gl/PW73xh)

```C
#include <stdio.h>

int main() {
  int *p;
  p = malloc(sizeof(int));
  if(p == 0) {
    printf("ERROR: Out of memory\n");
    return 1;
  }
  *p = 5;
  printf("*p = %d\n", *p);
  free(p);
  return 0;
}
```

IMAGEN

## 3. Asignacion dinamica de memoria mediante C

### 3.1. Operador sizeof
Este es un operador (no una funcion) que devielve la cantidad en bytes ocupada por una variable o algun tipo de dato. La sintaxis basica de este operador se muestra a continuacion:

```C
sizeof ( type-name )  
```

**Ejemplo**: En el siguiente [codigo](https://goo.gl/yscp62) ejemplo se muestran algunos ejemplos del uso de este operador:

```C
#include <stdio.h>

int main() {
  short *p;
  long long a;
  printf("sizeof(short*) = %d\n",sizeof(short*));  // Pasando un tipo de dato
  printf("sizeof(p1) = %d\n",sizeof(p)); // Pasando una variable
  printf("sizeof(short) = %d\n",sizeof(short)); // Pasando un tipo de dato
  printf("sizeof(long long) = %d\n",sizeof(long long)); // Pasando un tipo de dato
  printf("sizeof(long long) = %d\n",sizeof(a)); // Pasando una variable
  printf("sizeof(double*) = %d\n",sizeof(double*)); // Pasando un tipo de dato
  printf("sizeof(char*) = %d\n",sizeof(char*)); // Pasando un tipo de dato
  printf("sizeof(char) = %d\n",sizeof(char)); // Pasando un tipo de dato
  return 0;
}
```




## x. Enlaces
* https://www.berthon.eu/wiki/foss:wikishelf:linux:memory
* http://resources.infosecinstitute.com/system-address-map-initialization-in-x86x64-architecture-part-1-pci-based-systems/#gref
* https://fypandroid.wordpress.com/2011/01/17/anatomy-of-a-program-in-memory/
* https://www.securitysift.com/windows-exploit-development-part-1-basics/
* https://www.ibm.com/developerworks/library/j-nativememory-linux/
* https://gabrieletolomei.wordpress.com/miscellanea/operating-systems/in-memory-layout/
* http://www.cs.utexas.edu/users/fussell/cs310h/lectures/Lecture_17-310h.pdf
* https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-087-practical-programming-in-c-january-iap-2010/lecture-notes/
