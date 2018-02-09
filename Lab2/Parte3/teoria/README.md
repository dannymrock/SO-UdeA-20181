# Apuntadores y arreglos

> **Objetivos**
> * Introducir el concepto, manipulacion y uso de los arreglos multidimensionales.
> * Tratar mas aplicaciones de los apuntadores

## 1. Arreglos multidimensionales en C

A diferencia de los vectores, los arreglos multidimensionales (tambien conocidos como) se caracterizan por que manejan mas de un indice. Respecto a la manipulación, no existen considerables diferencias con java, sin embargo, a modo de repaso vamos a introducir algunos conceptos de repaso.

### 1.1. Declaración
Aqui se establecen ls dimensiones de cada componente, las formas mas comunes siguen una sintaxis como la siguiente:

**Caso para un arreglo de dos dimensiones**

```C
// Arreglo de dos dimensiones
arrayType  arrayName[Rows][Columns];
```

**Caso para un arreglo de tres dimensiones**

```C
// Arreglo de tres dimensiones
arrayType  arrayName[Planes][Rows ][Columns];
```

**Caso para un arreglo de N dimensiones**

```C
// Arreglo de N dimensiones
arrayType  arrayName[Dim1][Dim2]...[DimN];
```

**Ejemplo**
El siguiente [codigo](https://goo.gl/3Yt92d) muestra algunas declaraciones:

```C
int A[2][3];
float B[3][1];
int main() {
  char C[2][3][4];
  return 0;
}
```

La salida es como se muestra a continuacion:

![matrix_1](./imagenes/matriz1.png)

**Figura 1**. Declaración de varios arreglos multidimensionales.

A veces, puede ser util **inicializar** una matrix al declararla, a continuacion se muestran algunos ejemplos:

**Ejemplo**
El siguiente [codigo](https://goo.gl/ZoWP41) muestra diferentes formas de declarar e inicializar matrices:

```C
int matrix1[][4] = {
                    {4, 2, 7, 3},
                    {6, 1, 9, 5},
                    {8, 5, 0, 1}  
                  };


int main() {
  int matrix2[2][2] = {{1, 2}, {3, 4}};
  int matrix3[2][2] = {{1}, {3, 4}}; 
  int matrix4[3][5]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int matrix5[][3]={1, 2, 3, 4};
  return 0;
}
```

La representación en memoria de las matrices declaradas en el ejercicio anterior se muestra a continuación

![matrix_2](./imagenes/matriz2.png)

**Figura 2**. Declaración e inicialización de varios arreglos multidimensionales.


<table>
<tbody>
<tr>
<td>&nbsp;Instrucción</td>
<td>Representación en&nbsp;memoria&nbsp;</td>
</tr>
<tr>
<td>int i;</td>
<td><img src="./imagenes/rep_mapa_inst1.png" alt="var_mm1"></td>
</tr>
<tr>
<td>i = 35;</td>
<td><img src="./imagenes/rep_mapa_inst2.png" alt="var_mm2"></td>
</tr>
</tbody>
</table>




<table>
    <tr>
        <td colspan="2">Instrucciones</td>
    </tr>
    <tr>
        <td><b>int *p;<br>
            p = 1000;</b><br><br>
            <b>Nota</b>: Supóngase que <b>el apuntador</b> se guarda en la posición 500.
        </td>
        <td>
            <img src="./imagenes/rep_mapa_ptr_inst1.png">
        </td>
    </tr>
    <tr>
        <td colspan="2">Mapa de memoria</td>
    </tr>
    <tr>
        <td>
          <b>int p;<br>
            p = 1000;</b><br><br>
            <b>Nota</b>: Supóngase que la <b>variable p</b> se guarda en posición 500.
          </td>
        <td>
            <img src="./imagenes/rep_mapa_var_inst1_comp.png"> 
         </td>
    </tr>
</table>


Un apuntador se declara de la siguiente manera (donde las cosas que se encuentran entre corchetes son opcionales):

```C
tipo *[modificadores_del_tipo] nombre [=valor inicial];
```
Dónde:
* **Tipo**: Tipo de dato al cual se desea apuntar, puede ser un tipo de dato simple (char, int, etc.) o un tipo de dato complejo como una estructura).
* **Modificadores del tipo**: Puede contener cualquier combinación de los modificadores de tipo const, volatile y restrict.
* **Nombre**: Nombre del apuntador.
* **Valor inicial**: Valor inicial del apuntador. 




| Expresión	| Significado |	Valor |
|-----------|-------------|-------|
|i	| Contenido de i	|5|
|&i	| Dirección de i	|103|
|p	| Contenido del apuntador p	|103|
|&p	| Dirección del apuntador p	|106|



#### 2.4.2.1. Vectores

Un arreglo es un conjunto o colección indexada que permite manejar elementos que son del mismo tipo de dato como un solo objeto. A continuación se muestran algunos ejemplos ([enlace simulación](https://goo.gl/8qAgxY)) en los cuales se lleva a cabo la devlaración e inicialización de un vector:

<table>
    <tr>
        <td><b>Declaración del arreglo</b></td>
        <td><b>Representación en memoria</b></td>
    </tr>
    <tr>
        <td>int veci[4] = {2, 4, 6, 8};</td>
        <td><img src="./imagenes/vec_int.png"></td>
    </tr>
    <tr>
        <td>float vecf[] = {2.657, 7.9, 2.003, 1.1, 5.8, 8.54, 9.5, 4.09};</td>
        <td><img src="./imagenes/vec_float.png"></td>
    </tr>
    <tr>
        <td>char mess1[10] = "Hola";</td>
        <td><img src="./imagenes/vec_char1.png"></td>
    </tr>
    <tr>
        <td>mess2[] = {'H','o','l','a','\0'};</td>
        <td><img src="./imagenes/vec_char2.png"></td>
    </tr>
</table>

Notese, que cuando no se pasa el **tamaño** en la declaracion entre corchetes; este es deducido de la lista de inicializacion (pasada entre llaves) o la cadena de caracteres (string) pasada al declarar. En sí, se sigue la siguiente forma:

**Forma 1**: Pasando el tamaño:

```C
tipo arrayName[TAM] = {valor1, valor2, ...};
```
**Nota**: La cantidad de elementos de la lista de inicialización no puede superar el tamaño (TAM) del arreglo. 

**Forma 2**: Pasando el tamaño:

```C
tipo arrayName[] = {valor1, valor2, ...};
```

Por otro lado, cuando solo se declaran los arreglos pero no se inicializan, es obligatorio colocar entre corchetes el **tamaño**. La forma de hacer esto se muestra a continuación:

```C
tipo arrayName[TAM];
```

La siguiente figura muestra el caso en el que solo se declaran varios vectores de diferentes tipos tanto globales como locales:

```C
// Variables globales
int A[3];
double B[4];

int main() {
  // Variables locales
  char C[6];
  int D[2];
  return 0;
}
```

La siguiente figura muestra en resultado de simular el [código](https://goo.gl/hWPDDj) anterior, observe la diferencia en el valor inicial de los arreglos globales respecto a los locales:

![array_no_init](./imagenes/array_no_inicializado.png)

**Figura 6**. Representación en memoria de arreglos no inicializados.

**Forma 2**: Pasando el tamaño:

En lo que respecta a la manipulacion de arreglos, es igual que en java. El uso de estructuras repetitivas para el manejo de los sibindices en el arreglo es empleado. En los siguientes ejemplos se tiene ilustra esto de manera rapida.

**Ejemplos**

1. Hacer un progama que llene un arreglo de 10 elementos con los multiplos del 10 (1, 10, 20, etc.).

```C
#include <stdio.h>

#define TAM 10

int main() {
  int A[TAM];
  int num = 1;
  // Inicializando el arreglo
  for(int i = 0; i < TAM; i++) {
    A[i] = 10*num;
    num++;     
  }
  // Imprimiendo el arreglo
  printf("A = [ ");
  for(int i = 0; i < TAM; i++) {
    printf("%d ", A[i]);     
  }
  printf("]");
  return 0;
}
```
La [simulación](https://goo.gl/ACQc4J) de la aplicacion arroja el siguiente resultado:

![array_ciclos1](./imagenes/array_ciclos1.png)

**Figura 7**. Empleo de ciclos para manipulación de arrays.

2. Hacer cree dos arreglos (A y B), luego, inicialice el arreglo A con numeros aleatorios entre el 1 y el 20, y finalmente lleve al arreglo B los elementos del arreglo A en orden inverso.

```C
#include <stdio.h>
#include <stdlib.h> // required to use 'rand()'
#include <time.h>  // required to use 'srand(time(NULL))'
#define TAM 10

int main() {
  srand(time(NULL)); // required for "randomness"
  int A[TAM], B[TAM];
  int limSup = 20, limInf = 1;  
  // Inicializando el arreglo
  for(int i = 0; i < TAM; i++) {
    A[i] = rand()%limSup + limInf; // generate a number 
                                   // between limInf and limSup
     
  }
  // Imprimiendo el arreglo A
  printf("A = [ ");
  for(int i = 0; i < TAM; i++) {
    printf("%d ", A[i]);   
    B[TAM - (i + 1)] = A[i];
  }
  printf("]\n"); 
  // Imprimiendo el arreglo B
  printf("B = [ ");
  for(int i = 0; i < TAM; i++) {
    printf("%d ", B[i]);   
  }
  printf("]\n");
  return 0;  
}
```

La [simulación](https://goo.gl/kGLi2e) de la aplicacion arroja el siguiente resultado:

![array_ciclos2](./imagenes/array_ciclos2.png)

**Figura 8**. Otro ejemplo de empleo de ciclos para manipulación de arrays.

Es posible pasar **arreglos** como argumentos de funciones. Basicamente para el caso se tienen en cuenta los mismos 3 aspectos que se mencionaron previamente al tratar las funciones de manera introductoria, pero hay una leve diferencia cuando se emplean arreglos y es propiamente en la parte de la declaracion y la definicion donde se nota esto. Veamos la forma:

**Definición de la función**

```C
return_type function_name (data type array[],...) {
  local declarations;
  function statements;
}
```
**Declaración de la función**

```C
return_type function_name (data type arrayParam[],...) 
```

**Invocación de la función**
```C
[return_type var = ] function_name (arrayArg[],...) 
```

**Ejemplo**
1. Observe el ejemplo 2 anteriormente analizado, muestra cada uno de los componentes (definición, declaracón e invocación) de lo que sería una función para imprimir entero un vector de cualquier tamaño.

* **Definición de la función**

```C
// Definicion de la funcion para imprimir un array de cualquier tamaño
void imprimirVector(int V[],int tam) {
  printf("[ ");
  for(int i = 0; i < tam; i++) {
    printf("%d ", V[i]);   
  }
  printf("]\n");
}
```
* **Declaración de la función**

```C
// Declaracion de la funcion para imprimir un array de cualquier tamaño
void imprimirVector(int V[],int tam);
```

* **Invocación de la función**
```C
// Invocacion para imprimir 
int X[] = {1, 2, 3, 4};
imprimirVector(X, 4); // Salida --> [ 1 2 3 4 ]
```
2. Observe el ejemplo 2 anteriormente analizado e implementelo en forma modular empleando funciones.

La simulación del código se muestra en el siguinente [enlace](https://goo.gl/xDatTm) 

```C
#include <stdio.h>
#include <stdlib.h> // required to use 'rand()'
#include <time.h>  // required to use 'srand(time(NULL))'
#define TAM 10

void imprimirVector(int V[],int tam);
void generarVectorAleatorio(int V[], int tam, int vInf, int vSup);
void copiaReversa(int destino[], int origen[], int tam) ;

int main() {
  srand(time(NULL)); // required for "randomness"
  int A[TAM], B[TAM];
  int limSup = 20, limInf = 1;  
  generarVectorAleatorio(A, TAM, 1, 20);
  copiaReversa(B, A, TAM);
  // Imprimiendo el arreglo A
  printf("A = ");
  imprimirVector(A, TAM);
  // Imprimiendo el arreglo B
  printf("B = ");
  imprimirVector(B, TAM);
  return 0;  
}

void generarVectorAleatorio(int V[], int tam, int vInf, int vSup) {
  for(int i = 0; i < tam; i++) {
    V[i] = rand()%vSup + vInf;            
  }
}

void imprimirVector(int V[],int tam) {
  printf("[ ");
  for(int i = 0; i < tam; i++) {
    printf("%d ", V[i]);   
  }
  printf("]\n");
}

void copiaReversa(int destino[], int origen[], int tam) {
  for(int i = 0; i < tam; i++) {
    destino[tam - (i + 1)] = origen[i];   
  }
}
```

La siguiente figura muestra el resultado del código anterior:

![funciones_arrays](./imagenes/funciones_arrays.png)

**Figura 9**. Manipulando arreglos con funciones.


## xxx. Enlaces de interés
* https://www.geeksforgeeks.org/data-types-in-c/
* https://www.programiz.com/c-programming/c-enumeration
* http://people.duke.edu/~tkb13/courses/ncsu-csc230/lecture/
* https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/
* https://www.geeksforgeeks.org/tag/c-pointers/
* https://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/
* https://www.eskimo.com/~scs/cclass/int/sx8.html
* https://www.tutorialspoint.com/cprogramming/c_pointer_to_pointer.htm
* https://boredzo.org/pointers/
* https://beginnersbook.com/2014/01/c-pointer-to-pointer/
* https://www.tutorialspoint.com/cprogramming/index.htm




