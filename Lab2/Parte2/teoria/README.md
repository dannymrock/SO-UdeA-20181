# Apuntadores, arreglos y matrices

> **Objetivos**
> * Conocer y utilizar los apuntadores para el uso eficiente de la memoria.
> * Presentar el uso de las funciones y establecer cómo se realiza el paso de parámetros a funciones.
> * Conocer y aplicar el concepto de arreglos de una y más dimensiones en la resolución de problemas mediante algoritmos.
> * Conocer cómo es posible asignar de forma eficiente espacio en memoria.

## 1. Conceptos previos - ¿Que sucede cuando se declara una variable?
Cuando una variable se declara esta pasa a ocupar un lugar de memoria cuyo tamaño dependerá del número de bytes asociados al tipo de dato con el cual esta se declara. Suponiendo que se tienen las siguientes instrucciones en C:

```C
int i;
i = 35;
```

La siguiente figura ilustra su representación en memoria:

![var_mem](./imagenes/var_memoria.png)

**Figura 1**. Representación de una variable en memoria.

Desde el punto de vista del mapa de memoria y suponiendo que una variable tipo int ocupa 4 bytes tenemos el siguiente resultado por instrucción:

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

Como se puede ver en la figura anterior, lo que se modifica cuando se hace manipulación sobre variables es el contenido almacenado en un lugar especifico de memoria. Entender esto es de vital importancia para manejar el próximo tema.

## 2. Entrando en materia - Algunos aspectos sobre los apuntadores

### 2.1. ¿Que es un apuntador?

Un apuntador es una variable que almacena una **dirección de memoria y no un valor** como ocurre en el caso de las variables normales. La siguiente tabla resalta este hecho:

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

Como se puede notar en la figura anterior, cuando el valor almacenado en el apuntador hará referencia a la dirección 1000 y no al valor de 1000, esto nos permitirá acceder a dicho lugar de memoria desde el apuntador. Más tarde veremos cómo. Así mismo, como un apuntador guarda una dirección de memoria y teniendo en cuenta que para el ejemplo se supone una arquitectura en la cual se manejan 32 bits ( equivalentes a 4 bytes), esto hará que una variable tipo apuntador sin importar el tipo de dato al que apunte tenga un tamaño de 4 bytes. (Este tamaño se define por la arquitectura. Por ejemplo si la maquina es de 64 bits entonces el tamaño ocupado por una variable tipo apuntador será de 8 bytes).

### 2.2. ¿Como se declara un apuntador?

Un apuntador se declara de la siguiente manera (donde las cosas que se encuentran entre corchetes son opcionales):

```C
tipo *[modificadores_del_tipo] nombre [=valor inicial];
```
Dónde:
* **Tipo**: Tipo de dato al cual se desea apuntar, puede ser un tipo de dato simple (char, int, etc.) o un tipo de dato complejo como una estructura).
* **Modificadores del tipo**: Puede contener cualquier combinación de los modificadores de tipo const, volatile y restrict.
* **Nombre**: Nombre del apuntador.
* **Valor inicial**: Valor inicial del apuntador. 

La siguiente figura muestra esto lo anterior en términos del mapa de memoria:

<table>
    <tr>
        <td><b>Instrucciones</b></td>
        <td><b>Mapa de memoria</b></td>
    </tr>
    <tr>
        <td><b>    
        short i = 5; <br>
        short *ptr = &i; 
         </b> <br> <br>
         <b>Nota</b>:
        <ul>
        <li>El tamaño de una variables short es de 2 bytes.</li>
        <li>El tamaño de una variable tipo apuntador es de 4 bytes.</li>
        <li>En el dibujo del mapa de memoria cada dirección aumenta de 1 en 1</li>
        </ul> 
        </td>       
        <td>
            <img src="./imagenes/rep_ptr_map1.png"> 
        </td>
    </tr>
</table>

Como se puede notar en la figura anterior, lo que se guarda en el apuntador es la dirección base (dirección del byte de menor peso) de la variable a la cual se apunta. Para el caso anterior, la variable i ocupa 2 bytes (103 y 104) sin embargo, en el apuntador se almacena la parte menos correspondiente al byte pesado (byte 103). 

Si observa la segunda instrucción anteriormente mostrada, la forma como se obtuvo la dirección de i fue por medio del operador dirección (&) antepuesto a la variable. La siguiente tabla se llena con base en la figura anterior:


| Expresión	| Significado |	Valor |
|-----------|-------------|-------|
|i	| Contenido de i	|5|
|&i	| Dirección de i	|103|
|p	| Contenido del apuntador p	|103|
|&p	| Dirección del apuntador p	|106|

Note en la tabla anterior y la figura previa que con & lo que se obtiene es dirección base de una variable no importa su tipo ya sea una variable normal (char, int, float, etc), apuntador u otro. A continuación se muestra una forma simplificada (tomada de la sección **Pointers basics** de [How Stuff Works](https://computer.howstuffworks.com/c22.htm)) para visualizar los apuntadores y las variables comunes de manera gráfica sin tener que recurrir al bosquejo del mapa de memoria previamente realizado. 

![var_mem](./imagenes/apuntador2.png)

**Figura 2**. Vista simplificada con variables y apuntadores.

Note la diferencia en la gráfica, en el dibujo el circulo representa una variable tipo apuntador y como tal almacena una dirección de memoria, la de i para el caso (103); por otro lado el vinculo entre el apuntador y la variable se representa por medio de la flecha. Finalmente, el contenido de la variable puede ser accedido o manipulado desde el símbolo i, o desde al desreferenciar el apuntador (usando *ptr), pero este sera un tema a tratar después.

Una forma aun mas simplificada e incluso mas conveniente al momento de hacer pruebas de escritorio se muestra a continuación. En esta solo se resalta el vinculo del apuntador con la variable:

![var_mem](./imagenes/apuntador.png)

**Figura 3**. Vista aun mas simplificada con variables y apuntadores.

### 2.3. Manipulación de memoria mediante apuntadores

Una de las aplicaciones más importantes es el acceso directo a memoria para su manipulación. Para ello, se manejan dos operadores importantes los cuales el operador referencia (&) y el operador des-referencia (*).

### 2.3.1. Referenciar un apuntador

Consiste en asociar el apuntador a una dirección específica (durante la declaración o después de esta), para esto se suele usar el operador & para obtener la dirección de la variable en cuestión. A continuación se muestra la forma como normalmente se hace esto:

```C
apuntador = &variable;
```
También es posible referenciar un apuntador pasándole el valor que se tiene en otro apuntador. Note que no se hizo uso del operador & en este caso:

```C
apuntador = &variable;
```
Todo apuntador debe inicializarse antes de usarse. Si esto no se hace, cuando intente usarlo para hacer alguna operación en memoria el programa sacara un error. Un puntero que no ha sido inicializado se conoce como **Wild pointer**.

### 2.3.2. Des-referenciar un apuntador
Para poder acceder al lugar de memoria que está siendo apuntado por el puntero y realizar operaciones de lectura y escritura sobre esta dirección de memoria se debe des-referenciar el apuntador. Para ello se hace uso del operador des-referencia (*) después de la declaración del apuntador. El contenido del lugar de memoria apuntado (lectura) se obtiene de la siguiente manera:

```C
variable = *apuntador;
```
Ahora si lo que se desea hacer es escribir en el lugar de memoria apuntado se hace lo siguiente:

```C
*apuntador = variable;
```

**Ejemplo 1**

Suponga que se tiene el siguiente fragmento de código fuente:

```C
int i,j;
int *p; //Apuntador a un entero
p = &i;
*p = 5;
j = i;
```

También tenga en cuenta lo siguientes enunciados:
* Suponga que i y j son de 4 bytes y ocupan las direcciones base 1000 y 1004.
* El apuntador p ocupa las direccione base 2000.
* Así mismo la arquitectura es de 64 bits por lo que el espacio ocupado por el apuntador sera de 8 bytes.

Muestre la ejecución paso a paso del código anterior resaltando la evolución en memoria:

**Solución**: Las instrucciones que se están evaluando en un momento dado se resaltan, sin embargo, para mayor facilidad, la simulación del código anterior se puede hacer siguiendo el siguiente [enlace](https://goo.gl/MPttRK).

<table>
    <tr>
        <td><b>Instrucciones ejecutadas</b></td>
        <td><b>Contenido del mapa de memoria</b></td>
        <td><b>Visualización al estilo HowStuffWorks</b></td>
    </tr>
    <tr>
        <td>
            <b>
            int i,j;</br>
            int *p; //Apuntador a un entero</br></b>
            p = &i;</br>
            *p = 5;</br>
</td>
        <td><img src="./imagenes/ptr_ejem2_map1.png"></td>
        <td><img src="./imagenes/ptr_ejem2_hsw1.png"></td>
    </tr>
    <tr>
        <td>        
        int i,j;</br>
        int *p; //Apuntador a un entero</br>
        <b>p = &i;</br></b>
        *p = 5;</br>    
        </td>
        <td><img src="./imagenes/rep_ptr_map2.png"></td>
        <td><img src="./imagenes/ptr_ejem2_hsw2.png"></td>
    </tr>
    <tr>
        <td>        
        int i,j;</br>
        int *p; //Apuntador a un entero</br>
        p = &i;</br>
        <b>*p = 5;</br></b>     
        </td>
        <td><img src="./imagenes/rep_ptr_map3.png"></td>
        <td><img src="./imagenes/ptr_ejem2_hsw3.png"></td>
    </tr>
</table>

Note que en la última instrucción resaltada el cambio del contenido de la sección de memoria asociado a la variable i no se realizó desde esta (i = 5) sino desde el apuntador p (*p = 5) el cual previamente se puso a apuntar a dicho lugar de memoria (p = &i).

**Ejemplo 2**

A continuación se muestra otro ejemplo en el cual se resalta que es posible que varios apuntadores estén apuntando a un mismo lugar de memoria. Tenga en cuenta lo siguientes enunciados:
* Suponga que i y j son de 4 bytes y ocupan las direcciones base 1000 y 1008.
* Los apuntadores p, q y r ocupan las direcciones base 2000, 3000 y 4000.
* Así mismo la arquitectura es de 32 bits por lo que el espacio ocupado por el apuntador será de 4 bytes.

**Solución**: en el siguiente [enlace](https://goo.gl/XpVxW9) se muestra la simulación, la siguiente tabla muestra con detalle los resultados:

<table>
    <tr>
        <td><b>Instrucciones ejecutadas</b></td>
        <td><b>Contenido del mapa de memoria</b></td>
        <td><b>Visualización al estilo HowStuffWorks</b></td>
    </tr>
    <tr>
        <td>
          int i = 5; </br>
          int *p,*q,*r; </br>
          p = &i; </br>
          q = &i; </br>
          r = p; </br>
        </td>
        <td><img src="./imagenes/rep_ptr2_map.png"></td>
        <td><img src="./imagenes/rep_ptr2_hsw.png"></td>
    </tr>
</table>

### 2.4. Usos de los apuntadores

### 2.4.1. Funciones y apuntadores

Como se vio en la primera parte del laboratorio, existen dos maneras de hacer llamados a funciones, por referencia y por valor. Cuando se realiza un **llamado por valor**; se trabaja sobre una copia de la variable pasada como argumento y por lo tanto la variable original (la que se pasó como argumento) no se modifica. Por otro lado, cuando se realiza un **llamado por referencia** al estar accediendo al lugar de memoria en el que se encuentra la variable pasada como argumento es posible modificar el valor original de la variable pasada como argumento. La siguiente tabla compara un poco la diferencia entre referencia y valor:

<table>
    <tr>
        <td><b>Ítem analizado</b></td>
        <td><b>Llamada por valor</b></td>
        <td><b>Llamada por referencia</b></td>
    </tr>
    <tr>
        <td><b>Declaración</b></td>
        <td>void swap(int i, int j);</td>
        <td>void swap(int *i, int *j);</td>
    </tr>
    <tr>
        <td><b>Definición</b></td>
        <td>
          void swap(int i, int j) { </br>
            &nbsp;&nbsp;&nbsp;int t; </br>
            &nbsp;&nbsp;&nbsp;t = x; </br>
            &nbsp;&nbsp;&nbsp;i = j; </br>
            &nbsp;&nbsp;&nbsp;j = t; </br>
          } </br>
        </td>
        <td>
           int v1 = 1, v2 = 2; </br>
           swap(v1, v2); </br>
        </td>
    </tr>
    <tr>
        <td><b>Invocación</b></td>
        <td>
            void swap(int *i, *int j) { </br>
               &nbsp;&nbsp;&nbsp;int t; </br>
               &nbsp;&nbsp;&nbsp;t = *i; </br>
               &nbsp;&nbsp;&nbsp;*i = *j; </br>
               &nbsp;&nbsp;&nbsp;*j = t; </br>
            }   </br>
        </td>
        <td>
           int v1 = 1, v2 = 2; </br>
           swap(&v1, &v2); </br>
        </td>
    </tr>
</table>

El paso de funciones por referencia es de extrema utilidad cuando los argumentos que se están pasando a la función son pesados ya que esto evita que se tengan que hacer copias de dichos argumentos que en el peor de los casos pueden ocasionar que el programa colapse por llenar **stack**. También, mediante el uso de apuntadores, es posible superar la restricción que se tiene en la cual una función no puede retornar más de un elemento; así, por medio de referencias es posible retornar un array por ejemplo.

Para indicar que una función será pasada por referencia, se emplean apuntadores en la cabecera de la función, esto porque lo que se pasa como argumento es la dirección de memoria. Por ejemplo:

```C
tipo_retorno f(tipo_1 *pName_1,tipo_2 *pName_2,...,tipo_N *pName_N) 
```
Para aterrizar un poco más lo anterior, supongamos esta función:

```C
void swap(int *i, int *j) {
    int t;
    t = *i;
    *i = *j;
    *j = t;
}
```
Como se pueden notar en la definición de la función anterior, en este caso ambos argumentos son pasados por referencia. 

Ahora en lo que respecta a la invocación si lo que se pasa es como parámetro es una variable como tal se debe hacer uso del operador **&** para obtener la dirección de dicha variable y así inicializar el apuntador que funciona como argumento. Por otro lado si lo que se está pasando es un apuntador a una variable, no es necesario usar el operador **&** ya que el valor almacenado en este será una dirección de memoria. La siguiente tabla ilustra esto:

<table>
    <tr>
        <td><b>Caso</b></td>
        <td><b>Invocación</b></td>
        <td><b>Observaciones</b></td>
    </tr>
    <tr>
        <td>Se está pasando una variable a una función que se llama por referencia</td>
        <td>
            int a = 5, b = 10; </br>
            swap(&a,&b); </br>
        </td>
        <td>Es necesario usar el operador & para obtener la dirección de memoria de las variables y así poder inicializar lo apuntadores que funcionan como argumentos.</td>
    </tr>
    <tr>
        <td>Se está pasando apuntador a una función que se llama por referencia</td>
        <td>
            int a = 5, b = 10; </br>
            int *px = &a, *py; </br>
            py = &b;  </br>
            swap(px,py); </br>
        </td>
        <td>Como lo que se pasan son apuntadores previamente inicializados, estos ya tienen la dirección de memoria de la variable que será pasada como argumento de la función, por lo tanto no es necesario usar el operador &.</td>
    </tr>
</table>

La siguiente figura (tomada de [HowStuffWorks](http://computer.howstuffworks.com/c26.htm)) muestra cómo trabaja una función por referencia:

![call_ref](./imagenes/call_ref.png)

**Figura 4**. Llamado por referencia.

Para aclarar un poco observe el siguiente código (el cual puede ser simulado en el siguiente [enlace](https://goo.gl/jbpVKV)):

```C
#include <stdio.h>

void swap (int *x, int *y);
void swap (int x, int y);

int main() {
    int x = 5, y = 10;
    printf("---------------------------------------------------\n");
    printf("Llamada por valor \n");
    printf("Antes del swap -> x = %d, y = %d\n",x,y);
    swap(x, y);
    printf("Después del swap -> x = %d, y = %d\n",x,y);
    printf("---------------------------------------------------\n");
    printf("Llamada por referencia " << endl;
    printf("Antes del swap -> x = %d, y = %d\n",x,y);
    swap(&x, &y);
    printf("Después del swap -> x = %d, y = %d\n",x,y);
    printf("---------------------------------------------------\n");
    return 0;
}

void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;    
}

void swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
```

La salida del programa sera la siguiente:
```
---------------------------------------------------
Llamada por valor 
Antes del swap -> x = 5, y = 10
Después del swap -> x = 5, y = 10
---------------------------------------------------
Llamada por referencia 
Antes del swap -> x = 5, y = 10
Después del swap -> x = 10, y = 5
---------------------------------------------------
```
Una función también puede retornar un apuntador cuando es invocada, para hacer esto, en la definición y declaración de la función se debe indicar que la función retornara un apuntador lo cual se hace precediendo el nombre de la función por un asterisco (Ver parte resaltada e rojo a continuación). A continuación se muestra la forma que debe llevar la función para este caso:

```C
tipo_retorno *f(parámetros...) 
```

Observe el siguiente fragmento de código, el cual consiste en una función que obtiene el valor mayor de un vector mediante apuntadores devolviendo la dirección del elemento mayor mediante un apuntador:

```C
int *mayor(int *a, int n) {
  int i;
  int *m = a;
  a++;
  for (i = 1; i < n; ++i )
    if(*m < *a) {
      m = a;
      a++;
    }
  return m;
}
```
La declaración de la función anterior se muestra a continuación:

```C
int *mayor(int *a, int n); 
```
Otra forma de declaración puede ser:

```C
int *mayor(int *, int n); 
```

Recuerde lo importante en la declaración de la función es indicarle al compilador como van a usarse los parámetros.

Así mismo, note también, que lo realimente importante es que se declaró un apuntador a un tipo de dato específico, se inicializo, se actualizo y luego se retornó este, en general en la definición de la función se sigue la siguiente plantilla:

```C
tipo *funcion(tipo *arg1,...) {
  tipo *ptr;  // Declaración del apuntador
  ptr = &arg; // Inicialización del apuntador
  
  /** Operaciones **/
  ...  
  return ptr; // Retorno del apuntador
}
```

Para reforzar lo anteriormente trabajado, compile y ejecute el siguiente programa en el cual se hace uso de la función anteriormente creada. Comprenda bien cómo funciona (sobre todo analice: Declaración, definición e invocación), ayúdese del siguiente [enlace](https://goo.gl/YmKvcC) para simular:

```C
#include <stdio.h>

int *mayor(int *a,int n); // Declaración

int main() {
    int a[6] = {1,2,5,9,-1,3};
    int *p;
    p = mayor(a,5); // Invocación
    printf("El elemento mayor del vector es: *p \n",*p);
    return 0;
}

// Definición
int *mayor(int *a,int n) {
  int i;
  int *m = a;
  a++;
  for (i = 1; i < n; ++i )
    if(*m < *a) {
      m = a;
      a++;
    }
  return m;
}
```
La siguiente figura muestra el estado de ejecución del programa antes de hacer el retorno de la subrutina mayor:

![ret_ptr](./imagenes/retorno_prt.png)

**Figura 5**. Funcion retornando un apuntador.

La salida del programa anterior en pantalla es la siguiente:

```
El elemento mayor del vector es: 9
```


### 2.4.2. Apuntadores y vectores

#### 2.4.2.1. Vectores

Un arreglo es un conjunto o colección indexada que permite manejar elementos que son del mismo tipo de dato como un solo objeto. A continuación se muestran algunos ejemplos ([enlace simulación](https://goo.gl/8qAgxY)):

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

Cabe resaltar que la manipulación es similar a la empleada en otros lenguajes como java.

#### 2.4.2.1. Apuntadores y vectores

Como los apuntadores son variables es posible realizar operaciones matemáticas sobre ellos, sin embargo debido a que lo almacenado en  estos son direcciones de memoria no todas las operaciones convencionales que se podrían hacer sobre una variable normal son posibles. La siguiente tabla muestra las operaciones validas:

<table>
    <tr>
        <td><b>Operación</b></td>
        <td><b>Anotaciones</b></td>
    </tr>
    <tr>
        <td>Añadir o sustraer un entero de un apuntador.</td>
        <td>Esto hace  que el puntero apunte a otro lugar de memoria diferente al que inicialmente estaba apuntando esto debido a la modificación de lo que se encuentra almacenado en este.</td>
    </tr>
    <tr>
        <td>Sustraer un apuntador de otro.</td>
        <td>Cuando se realiza esta operación, los dos apuntadores deben ser del mismo tipo. </td>
    </tr>
    <tr>
        <td>Comparar dos apuntadores.</td>
        <td>La comparación es comúnmente empleada para comparar cualquier puntero con el puntero a <b>NULL</b> usando los operadores de igualdad (<b>==</b> o <b>!=</b>).</td>
    </tr>
</table>

Las tres operaciones anteriormente descritas son generalmente útiles para apuntadores que se refieren a los elementos de un array. Recordemos que un array consiste de un conjunto de variables del mismo tipo las cuales pueden ser accedidas bajo un mismo nombre usando subíndices. Cuando se declara un array lo que sucede en memoria es que se reservan un conjunto de posiciones contiguas en memoria tal y como se muestra en la siguiente figura: 

![array_hsw](./imagenes/array_hsw.png)

**Figura 6**. Diferencia entre una variable normal y un vector.

Para ilustrar lo anterior suponga lo que tiene dos apuntadores, p1 y p2 los cuales están apuntando a los elementos de un array a como el siguiente:

![array_a](./imagenes/array_a.png)

**Figura 7**. Arreglo a.

* p1 apunta al elemento i del array (a[i]).

![array_a_p1](./imagenes/array_a_p1.png)

**Figura 8**. Arreglo a y apuntador p1.

* Si n es un entero, entonces la expresión **p2 = p1 + n** hace que **p2** apunta al elemento **a[i+n]**. Ojo que **i+n** debe estar dentro del índice del array (es decir **0 <= i+n <= Tamaño del array - 1**). La siguiente figura muestra el caso para **n = 2**, es decir que **p2** apuntara al elemento **a[i+2]**

![array_a_p1_p2](./imagenes/array_a_p1_p2.png)

**Figura 9**. Arreglo a y apuntadores p1 y p2.

* La resta **p2 – p1** da el número de elementos del array entre los dos apuntadores. Para el caso de la gráfica anterior **2**.
* La comparación **p1 < p2** es cierta si el elemento referenciado por p2 tiene un índice más grande que el referenciado por **p1**, de otro lado la comparación es **falsa**. Donde para la figura anterior el resultado es **cierto**.

Lo anterior muestra que existe una relación entre la forma de escribir un array con subíndices y escribirlo con apuntadores aritmética de apuntadores. Para aterrizar un poco lo anterior analicemos la siguiente tabla:

<table>
    <tr>
        <td><b>Relación entre índices y array</b></td>
        <td><b>En resumen</b></td>
    </tr>
    <tr>
        <td>El nombre de un arreglo es <b>realmente un apuntador al primer elemento en el array</b>, así si a es un arreglo unidimensional entonces la dirección del primer elemento del array es <b>&a[0]</b> o simplemente <b>a</b>.</td>
        <td>&a[0]↔a</td>
    </tr>
    <tr>
        <td>La dirección del elemento **i** del array puede ser expresada como <b>&a[i]</b> o como <b>a + i</b>, por lo tanto existen dos manera de escribir la dirección de cualquier elemento del array.</td>
        <td>&a[i]↔a+i</td>
    </tr>
    <tr>
        <td><b>a[i]</b> o <b>*(a+i)</b> representan el contenido que hay en la dirección en cuestión</td>
        <td>a[i]↔*(a+i)</td>
    </tr>
</table>

Para entender un poco lo anterior suponga que se ejecutan las siguientes instrucciones:

```C
char b[] = {'h', 'o', 'l', 'a','\0'};
*(b+2) = *b;
char *p1 = b;
char *p2 = b + 3;
p2 = p2 - 1;
p1 = p2 - 1;
*p2 = *(b + 1) + 1;
p2 = &b[1];
return 0;
```

Para entender el resultado del código anterior puede seguir el siguiente [enlace](https://goo.gl/sSW8gy).






## 7. Enlaces de interés
* https://www.geeksforgeeks.org/data-types-in-c/
* https://www.programiz.com/c-programming/c-enumeration





