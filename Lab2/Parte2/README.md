# Laboratorio de vectores y apuntadores

> **Objetivos**
> * Introducir el concepto de apuntador, su uso e importancia en la realizacion de programas en C.
> * Comprender la relación que se establece entre apuntadores, variables y memoria.
> * Entender el uso de vectores en C.
> * Relacionar y aplicar los conceptos: vectores, apuntadores y funciones para el desarrollo de problemas de programacion.

## 1. Resumen y repaso

Revisar la parte teorica la cual se encuentra en el siguiente [enlace](https://github.com/dannymrock/SO-UdeA-20181/tree/master/Lab2/Parte2/teoria)

## 2. Ejemplos de repaso

### 2.1. Apuntadores y variables

1. Despues de que se simula el siguiente [codigo](https://goo.gl/QXBsL8), ¿Cual es el valor final de la variable ch?

```C
#include <stdio.h>

int main() {
  char *p1, *p2;
  char ch = 'a';
  printf("ch = %c\n", ch);
  p1 = &ch;
  (*p1)++;
  printf("ch = %c\n", ch);
  p2 = p1;
  *p2 += 3;
  printf("ch = %c\n", ch);
  return 0;
}
```

2. Suponga que se simula el siguiente [codigo](https://goo.gl/5NeAxm)

```C
#include <stdio.h>

int main() {
  int *p1, *p2;
  int a = 3;
  p1 = &a;
  p2 = p1;
  printf("------------------\n");
  printf("a = %d\n", a);
  printf("p1 = %p\n", p1);
  printf("p2 = %p\n",p2);  
  (*p1)++;
  *p2++;
  printf("------------------\n");
  printf("a = %d\n", a);
  printf("p1 = %p\n", p1);
  printf("p2 = %p\n",p2);
  return 0;
}
```

Por que se muestran los valores mostrados a la salida en pantalla. Puede ser util que revise el siguiente [enlace](http://en.cppreference.com/w/c/language/operator_precedence)

### 2.2. Apuntadores y vectores

1. ¿Que es lo que hace el siguiente [codigo](https://goo.gl/ybji6p)?

```C
#include <stdio.h>

int main() {
  int V[4] = {1,2,3,4};
  int VS[4];
  int s;   
  for(int i = 0; i < 4; i++) {    
    s = 0;
    for(int j = 0; j <= i; j++) {
      s += V[j];
    }
    VS[3 - i] = s;
  }
  return 0;
}
```

2. ¿Que es lo que hace el siguiente [codigo](https://goo.gl/jnaR9z)?

```C
#include <stdio.h>

int main() {
  int V[4] = {1,2,3,4};
  int VS[4];
  int s;   
  for(int i = 0; i < 4; i++) {    
    s = 0;
    for(int j = 0; j <= i; j++) {
      s += *(V + j);
    }
    *((VS + 3) - i) = s;
  }
  return 0;
}
```

3. ¿Que es lo que hace el siguiente [codigo](https://goo.gl/Ao4mjH)?

```C
#include <stdio.h>

int main() {
  int *p1, *p2;
  int V[4] = {1,2,3,4};
  int VS[4];
  int s;  
  p2 = &VS[3];  
  for(int i = 0; i <4; i++) {
    p1 = V;
    s = 0;
    for(int j = 0; j <= i; j++) {
      s += *p1;
      p1++;
    }
    *p2 = s;
    p2--;
  }
  return 0;
}
```

### 2.3. Funciones por referencia y por valor

Ejemplo de un incremento (En construccion)

## 3. Ejercicios conceptuales

**Ejercicio 1**:

Suponga que se tiene el siguiente vector con las siguientes direcciones:

![imagen1](./imagenes/ejercicio1_vini.png)
**Figura 1**. Vector inicial ejercicio 1 

Adicionalemente, suponga que se declararon 3 apuntadores **p1**, **p2** y **p3** los cuales se encuentran en la direcciones **1000**, **2000** y **3000** respectivamente. Dadas las siguientes instrucciones:

```C
int *p1, *p2;
p1 = x;
p2 = &X[9];
*p2 = (*p2)*(-1)-(-1);
*p1 = 2*(*(p2-1))+*(p2-2);
p1++; // p1 = p1 + 1;
int *p3 = X + 3;
*p3 = *p3 + 1;
p2 = p3 + 2;
```

1. Dibuje el mapa de memoria asociado al problema anterior.
2  Despues de que se ejecuta el codigo anterior: Actualice el vector con los nuevos valores después de la ejecución del código anteriormente mostrado (**Nota**: no olvide resaltar el lugar apundado por los apuntadores):

![imagen2](./imagenes/ejercicio1_vfin.png)
**Figura 2**. Contenido del vector del ejercicio 1 despues de la ejecucion del codigo (Llenar).

Adicionalmente, llene el mapa de memoria con los nuevos valores tanto de los elementos del vector como de los apuntadores despues de la ejecucion del codigo.

3. Llene la siguiente tabla después de que se llevó a cabo la ejecución del código:

| Expresión  | Valor |
| ------------- | ------------- |
| &p1  |   |
| &p2  |   |
| &p3  |   |
| p1  |   |
| p2  |   |
| p3  |   |
| *p1  |   |
| *p2  |   |
| *p1  |   |
| *p1 + 1  |   |
| *(p1 + 1)  |   |
| p3 + 1  |   |
| p3 - 2  |   |

**Ejercicio 2**:
El proposito del siguiente codigo es que usted refuerce el concepto de llamadas por valor y por referencia. Observe el siguiente codigo:

```C
int f(int x, int y, int *z);

int main() {
  int a, b, c, d;
  int *p1, *p2 = &a, *p3 = &d;
  a = 2;
  b = -1;
  p2 = &c;  
  d = f(a + 3, b, &c);
  p1 = p2;
  // Parada 1...
  *p3 = f(*p2, -d, p1);
  // Parada 2...
  return 0;
}

int f(int x, int y, int *z) {
  *z = x + y;
  x++;  
  return *z + x + y;
}
```

Ahora responda las siguientes preguntas:

1. Llene la siguiente tabla con el contenido de las variables hasta que se llega al punto de parada 1 (Ver comentario en el codigo):


| Expresión  | Valor |
| ------------- | ------------- |
| a  |   |
| b  |   |
| c  |   |
| d  |   |
| *p1  |   |
| *p2  |   |
| *p3 |   |
| p1  |   |
| p2  |   |
| p3  |   |

2. Ahora llene la siguiente tabla con el contenido de las variables hasta que se llega al punto de parada 2 (Ver comentario en el codigo):

| Expresión  | Valor |
| ------------- | ------------- |
| a  |   |
| b  |   |
| c  |   |
| d  |   |
| *p1  |   |
| *p2  |   |
| *p3 |   |
| p1  |   |
| p2  |   |
| p3  |   |

## 4. Problemas de programacion

En construccion
