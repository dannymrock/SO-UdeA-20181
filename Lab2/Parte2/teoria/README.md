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

![var_mem](https://github.com/dannymrock/SO-UdeA-20181/blob/master/Lab2/Parte2/teoria/imagenes/var_memoria.png)

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
<td><img src="https://github.com/dannymrock/SO-UdeA-20181/blob/master/Lab2/Parte2/teoria/imagenes/rep_mapa_inst1.png" alt="var_mm1"></td>
</tr>
<tr>
<td>i = 35;</td>
<td><img src="https://github.com/dannymrock/SO-UdeA-20181/blob/master/Lab2/Parte2/teoria/imagenes/rep_mapa_inst2.png" alt="var_mm2"></td>
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
            <b>Nota</b>: Supóngase que <b>el apuntador<b> se guarda en la posición 500.
        </td>
        <td>
            <img src="https://github.com/dannymrock/SO-UdeA-20181/blob/master/Lab2/Parte2/teoria/imagenes/rep_mapa_ptr_inst1.png">
        </td>
    </tr>
    <tr>
        <td colspan="2">Mapa de memoria</td>
    </tr>
    <tr>
        <td>
          <b>int p;<br>
            p = 1000;</b><br><br>
            <b>Nota</b>: Supóngase que la <b>variable p<\b> se guarda en posición 500.
          </td>
        <td>
            <img src="https://github.com/dannymrock/SO-UdeA-20181/blob/master/Lab2/Parte2/teoria/imagenes/rep_mapa_var_inst1_comp.png"> 
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
        </td>
    </tr>
</table>




| Carácter de escape                               | Singnificado | Código ASCII                     |
|---------------------------------------------|-------------------|---------------------------|
| \a                          | Carácter de alerta (timbre)                | 7           |
| \b                          | Retroceso de espacio                | 8           |
| \f                         | Avance de página               | 12           |
| \n                          | Nueva línea                | 10           |
| \r                          | Retorno de carro                | 13           |
| \t                          | Tabulación horizontal                | 9           |
| \v                          | Tabulación vertical                | 11           |
| \\                          | Backslash ( \ ).              | 92           |
| \?                          | Interrogación ( ? ).              | 63           |
| \'                          | Comilla sencilla ( ' ).              | 39           |
| \"                          | Comillas dobles.              | 34           |
| \0nn                          | Número octal.              |            |
| \Xnn                          | Número hexadecimal              |            |
| \0                          | Carácter nulo o terminación de cadena              |           |



## 7. Enlaces de interes
* https://www.geeksforgeeks.org/data-types-in-c/
* https://www.programiz.com/c-programming/c-enumeration





