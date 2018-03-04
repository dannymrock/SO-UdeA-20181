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

### 3.2. Manejo dinamico de memoria

#### 3.2.1. Asignación de memoria: Memory Allocation o Malloc

La función ```malloc``` permite reservar un bloque de memoria (sin inicializar) en el heap. El prototipo de esta función se muestra a continuación:

> **Sintaxis**:
>
> ```C
> void * malloc (size_t size)
> ```
>
> **Donde**:
> * **size**: Numero de bytes que seran reservados
> 
> La funcion retorna la direccion en el heap a partir de la cual se reservó el tamaño de memoria solicitado o retorna **NULL** si no es posible reservar la cantidad de memoria. Cabe recordar que ```void*``` indica que la dirección retornada es genérica, es decir, en esa dirección se puede almacenar cualquier tipo de variable.

#### 3.2.2. Liberación de memoria: free

La función ```free``` libera un bloque de memoria previamente reservado en el heap. El prototipo de esta función se muestra a continuación:

> **Sintaxis**:
>
> ```C
> void free(void* pointer);
> ```
>
> **Donde**:
> * **pointer**: apuntador con la dirección del bloque de memoria (previamente reservado con **malloc** o con **calloc**) a liberar. 

#### Ejemplos
Con el fin de comprender los conceptos anteriormente expuestos analise y entienda los siguientes codigos

1. **Codigo 1**: [codigo online](https://goo.gl/RVaqJs)

```C
#include <stdio.h>

int main() {
  int *p, *q;
  p = malloc(sizeof(int));
  q = p;
  *p = 10;
  printf("%d\n",*q);
  *q = 20;
  printf("%d\n",*q);
  free(p);  // Tambien para el caso puede ser q
  return 0;
}
```
2. **Codigo 2**:  [codigo online](https://goo.gl/FYjaPb) 

```C
#include <stdio.h>

int main() {
  int *p, *q;
  p = malloc(sizeof(int));
  q = malloc(sizeof(int));
  *p = 10;
  *q = 20;
  printf("*p = %d; *q = %d\n", *p, *q);
  *p = *q;
  printf("*p = %d; *q = %d\n", *p, *q);
  free(p);  
  free(q);  
  return 0;
}
```

Tambien es posible declarar arrays en memoria dinamica pasando el tamaño del array en bytes. Asi por ejemplo, para declara un array de **N** elementos, el valor pasado como parametro a la funcion **malloc** sera **N*sizeof(dataTipe)**

3. **Codigo 3**: Crear dinamicamente un array de 10 elementos y llenarlo de ceros [codigo online](https://goo.gl/rBSJ6x)

```C
#include <stdio.h>

#define TAM 10 

int main() {
  int *p, *q;
  p = malloc(TAM*sizeof(int));
  for (int i = 0; i < TAM; i++) {
    *(p + i) = 0; // p[i] = 0
  }
  free(p);    
  return 0;
}
```

> **Buen tip de programacion**: asignar NULL a un apuntador no es obligatorio, pero es buena practica. Esto para evitar algun error si el apuntador es erroneamente utilizado despues de que la memoria ha sido liberada.

4. **Codigo 4**: Crear dinamicamente un array de 10 elementos y llenarlo de ceros, pero esta vez haga uso de la buena practica de programacion para entenderla [codigo online](https://goo.gl/X8TJoA)

```C
#include <stdio.h>

#define TAM 10 

int main() {
  int *p, *q;
  p = malloc(TAM*sizeof(int));
  for (int i = 0; i < TAM; i++) {
    *(p + i) = 0; // p[i] = 0
  }
  free(p); 
  p = NULL;
  return 0;
}
```

#### 3.2.3. Asignación de memoria con inicializacion: calloc

La función ```calloc``` permite reservar e inicializat a 0 un bloque de memoria en el heap. El prototipo de esta función se muestra a continuación:

> **Sintaxis**:
>
> ```C
> void * calloc (size_t numElements, size_t size)
> ```
>
> **Donde**:
> * **num**: numero de elementos consecutivos a reservar. 
> * **size**: Tamaño en bytes de cada elemento. 
>
> El espacio total reservado en la funcion es de numElements*size. Normalmente, la funcion retorna un apuntador que contiene la direccion inicial del bloque reservado en el heap. En caso de que no haya suficiente memoria disponible la funcion retornara NULL.

#### Ejemplos
Con el fin de comprender los conceptos anteriormente expuestos analise y entienda los siguientes codigos:

1. **Codigo 1**: Declare una en el heap un dato double inicializado a 0. Ver [codigo online](https://goo.gl/j8A8Zn)

```C
#include <stdio.h>

int main() {
  double *p;
  p = calloc(1, sizeof(double));
  if(p == 0) {
    printf("ERROR: Out of memory\n");
    return -1;
  }
  printf("*p = %.1lf\n", *p);
  free(p);
  p = NULL;
  return 0;
}
```

2. **Codigo 2**: Crear dinamicamente un array de 10 elementos entero y llenarlo de ceros por medio de la funcion calloc. Ver [codigo online](https://goo.gl/BnEetd)

```C
#include <stdio.h>

int main() {
  int *p;
  p = calloc(10, sizeof(int));
  if(p == 0) {
    printf("ERROR: Out of memory\n");
    return -1;
  }
  free(p);
  p = NULL;
  return 0;
}
```

#### 3.2.4. Reasignación de memoria: Memory Re-allocation o realloc

La función ```realloc``` permite redimensionar un bloque de memoria previamente reservada con ```malloc```. El prototipo de esta función se muestra a continuación.

> **Sintaxis**:
>
> ```C
> void * realloc(void * ptr, size_t size)
> ```
>
> **Donde**:
> * **ptr**: Puntero a memoria. 
> * **size**: Nuevo tamaño requerido. 
>
> Si el tamaño es reducido, los datos se pueden perder. Si el tamaño es incrementado y la funcion es incapaz de extender la localizacion existente, esta asignara un nuevo espacio de memoria y copiara los datos a traves de esa retornando un puntero a la memoria nuevamente asignada. 

#### Ejemplos
Con el fin de comprender los conceptos anteriormente expuestos analise y entienda los siguientes codigos:

1. Muestre mediante un ejemplo el uso de la funcion anterior.

**Solución**: En el siguiente [enlace]() se encuentra la solución.

```C
#include <stdio.h>

#define TAM1 10 
#define TAM2 5
#define TAM3 15

int main() {
  int *p;
  p = malloc(TAM1*sizeof(int));
  printf("Ubicacion del apuntador tras el malloc: %p\n",p);
  for (int i = 0; i < TAM1; i++) {
    *(p + i) = i + 1; // p[i] = 0
  }
  p = realloc(p,TAM2*sizeof(int));
  printf("Ubicacion del apuntador tras el primer realloc: %p\n",p);
  p = realloc(p,TAM3*sizeof(int)); 
  printf("Ubicacion del apuntador tras el segundo realloc: %p\n",p);
  free(p);   
  p = NULL;
  return 0;
}
```


FIGURA

# **** PENDIENTE - EJEMPLOS CON ESTRUCTURAS - CUADRAAR LOS SIGUIETNRS EJEMPLOS

**Ejemplo**: [Enlace](https://goo.gl/kWh3Ru)

```C
int **createZeroMatrix(int F, int C);
int **createZeroMatrix2(int F, int C);
void cleanMatrix(int **M,int F, int C);

int main() {
  int **ZM1;
  int **ZM2;
  ZM1 = createZeroMatrix(2, 3);
  ZM2 = createZeroMatrix2(2, 4);
  cleanMatrix(ZM1,2,3);
  cleanMatrix(ZM2,2,4);
  ZM1 = 0;
  ZM2 = 0;
  return 0;
}

int **createZeroMatrix(int F, int C) {
  int **M = (int **)malloc(F * sizeof(int *));
  for(int i = 0; i < F; i++) {
    *(M + i) = calloc(C,sizeof(int)); // *(M + i) = M[i] = ... 
  }
  return M;
}

int **createZeroMatrix2(int F, int C) {
  int **M = (int **)malloc(F * sizeof(int *));
  for(int i = 0; i < F; i++) {
    *(M + i) = malloc(C*sizeof(int)); // *(M + i) = M[i] = ...   
    for(int j = 0; j < C; j++) {
      *(*(M + i) + j) = 0; // *(*(M + i) + j) = M[i][j] = ...
    }
  }
  return M;
}

void cleanMatrix(int **M,int F, int C) {
  for(int i = 0; i < F; i++) {
    free(M[i]);  // M[i] = *(M + i) 
  }    
  free(M);
  M = 0;
}
```
**Enlace**: https://goo.gl/oUhjpC

```C
#include <stdio.h>
#include <string.h>


char **separateCharacters(char *cad);
int esVocal(char ch);

int main(void)
{
    char mess[] = "hola";
    char **R;
    R = separateCharacters(mess);
    printf("El mensaje %s tiene el siguiente inventario:\n",mess);
    printf("-> Vocales: %s\n",R[0]);
    printf("-> Consonantes: %s\n",R[1]);
    free(R);
    return 0;
}

int esVocal(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || \
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return -1;
    }
}

char **separateCharacters(char *cad) {
    char *p[2];
    int **r = (char **)malloc(2 * sizeof(char *));
    int nV = 0, nC = 0;
    p[0] = malloc(strlen(cad)*sizeof(char));
    p[1] = malloc(strlen(cad)*sizeof(char));
    while (*cad != '\0') {
        if(esVocal(*cad) == 1) {
            // El caracter es vocal
            *(p[0] + nV) = *cad;   // *(*p + nV)
            nV++;
        }
        else if (esVocal(*cad) == 0) {
            // El caracter es consonante
            *(*(p + 1) + nC) = *cad;  // *(p[1] + nC)
            nC++;
        }
        cad++;
    }
    *(*p + nV) = '\0';
    *(*(p + 1) + nC) = '\0';

    p[0] = realloc(p[0],(nV + 1)*sizeof(char));
    p[1] = realloc(p[1],(nC + 1)*sizeof(char));
    r[0] = p[0];
    r[1] = p[1];
    return r;
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
* https://stackoverflow.com/questions/2128728/allocate-matrix-in-c
* https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
* https://www.programiz.com/c-programming/c-dynamic-memory-allocation
* https://www.cs.swarthmore.edu/~newhall/unixhelp/C_arrays.html

