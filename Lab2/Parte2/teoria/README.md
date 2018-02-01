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
            <b>Nota</b>: Supóngase que <b>el apuntador<\b> se guarda en la posición 500.
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




