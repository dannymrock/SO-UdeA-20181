# Apuntadores, arreglos y memoria dinamica

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

La siguiente figura ilustra su representacion en memoria:

![var_mem](./imagenes/var_memoria.png)

**Figura 1**. Representación de una variable en memoria.

Desde el punto de vista del mapa de memoria y suponiendo que una variable tipo int ocupa 4 bytes tenemos el siguiente resultado por instruccion:

<table>
<tbody>
<tr>
<td>&nbsp;Instruccion</td>
<td>Representacion en&nbsp;memoria&nbsp;</td>
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

Como se puede ver en la figura anterior, lo que se modifica cuando se hace manipulacion sobre variables es el contenido almacenado en un lugar especifico de memoria. Entender esto es de vital importancia para manejar el proximo tema.

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


| Expresion	| Significado |	Valor |
|-----------|-------------|-------|
|i	| Contenido de i	|5|
|&i	| Dirección de i	|103|
|p	| Contenido del apuntador p	|103|
|&p	| Dirección del apuntador p	|106|

Nótese de la tabla anterior y la figura previa que con & lo que se obtiene es dirección base de una variable no importa su tipo ya sea una variable normal (char, int, float, etc), apuntador u otro. A continuacion se muestra una forma simplificada (tomada de la sección **Pointers basics** de [How Stuff Works](https://computer.howstuffworks.com/c22.htm)) para visualizar los apuntadores y las variables comunes de manera grafica sin tener que recurrir al bosquejo del mapa de memoria previamente realizado. 

![var_mem](./imagenes/apuntador2.png)

**Figura 2**. Vista simplificada con variables y apuntadores.

Note la diferencia en la grafica, en el dibujo el circulo representa una variable tipo apuntador y como tal almacena una direccion de memoria, la de i para el caso (103); por otro lado el vinculo entre el apuntador y la variable se representa por medio de la flecha. Finalmente, el contenido de la variable puede ser accedido o manipulado desde el simbolo i, o desde al desreferenciar el apuntador (usando *ptr), pero este sera un tema a tratar depues.

Una forma aun mas simplificada e incluso mas conveniente al momento de hacer pruebas de escritorio se muestra a continuación. En esta solo se resalta el vinculo del apuntador con la variable:

![var_mem](./imagenes/apuntador.png)


### 2.3. Manipulación de memoria mediante apuntadores

Una de las aplicaciones más importantes es el acceso directo a memoria para su manipulación. Para ello, se manejan dos operadores importantes los cuales el operador referencia (&) y el operador desreferencia (*).

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

### 2.3.2. Desreferenciar un apuntador
Para poder acceder al lugar de memoria que está siendo apuntado por el puntero y realizar operaciones de lectura y escritura sobre esta dirección de memoria se debe desreferenciar el apuntador. Para ello se hace uso del operador desreferencia (*) después de la declaración del apuntador. El contenido del lugar de memoria apuntado (lectura) se obtiene de la siguiente manera:

```C
variable = *apuntador;
```
Ahora si lo que se desea hacer es escribir en el lugar de memoria apuntado se hace lo siguiente:

```C
*apuntador = variable;
```

**Ejemplo 1**

Suponga que se tiene el siguiente fragmento de codigo fuente:

```C
int i,j;
int *p; //Apuntador a un entero
p = &i;
*p = 5;
j = i;
```

Tambien tenga en cuenta lo siguientes enunciados:
* Suponga que i y j son de 4 bytes y ocupan las direcciones base 1000 y 1004.
* El apuntador p ocupa las direccione base 2000.
* Asi mismo la arquitectura es de 64 bits por lo que el espacio ocupado por el apuntador sera de 8 bytes.

Muestre la ejecución paso a paso del codigo anterior resaltando la evolucion en memoria:

**Solucion**: Las instrucciones que se estan evaluando en un momento dado se resaltan
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
        <td><img src="./imagenes/ptr_ejem2_hsw2.png"></td>
    </tr>
</table>

Nótese que en la última instrucción resaltada el cambio del contenido de la sección de memoria asociado a la variable i no se realizó desde esta (i = 5) sino desde el apuntador p (*p = 5) el cual previamente se puso a apuntar a dicho lugar de memoria (p = &i).

**Ejemplo 2**

A continuación se muestra otro ejemplo en el cual se resalta que es posible que varios apuntadores estén apuntando a un mismo lugar de memoria. Tenga en cuenta lo siguientes enunciados:
* Suponga que i y j son de 4 bytes y ocupan las direcciones base 1000 y 1008.
* Los apuntadores p, q y r ocupan las direcciones base 2000, 3000 y 4000.
* Así mismo la arquitectura es de 32 bits por lo que el espacio ocupado por el apuntador será de 4 bytes.

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



## 7. Enlaces de interes
* https://www.geeksforgeeks.org/data-types-in-c/
* https://www.programiz.com/c-programming/c-enumeration





