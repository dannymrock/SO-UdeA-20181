# Laboratorio de vectores y apuntadores

> **Objetivos**
> * Introducir el concepto de apuntador, su uso e importancia en la realizacion de programas en C.
> * Comprender la relación que se establece entre apuntadores, variables y memoria.
> * Entender el uso de vectores en C.
> * Relacionar y aplicar los conceptos: vectores, apuntadores y funciones para el desarrollo de problemas de programacion.

## 1. Resumen y repaso

Revisar la parte teorica la cual se encuentra en el siguiente [enlace](https://github.com/dannymrock/SO-UdeA-20181/tree/master/Lab2/Parte2/teoria)

## 2. Ejemplos de repaso

En construccion

## 3. Ejercicios conceptuales

**Ejercicio 1**:

Suponga que se tiene el siguiente vector con las siguientes direcciones:

IMAGEN.

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

IMAGEN

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



## 4. Problemas de programacion

