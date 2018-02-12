# Laboratorio de introducción al lenguaje C

> **Objetivos**
> * Reforzar los conceptos discutidos en el laboratorio.
> * Ir ganando experiencia en la resolución de problemas empleando lenguaje C.

## 1. Ejemplos de repaso

A modo de repaso se mostraran algunos ejercicios resueltos.

1. Hacer un programa que calcule el máximo de 2 números.

**Solucion**: [ejemplo1_sol.c](ejemplo1_sol.c)

2. Hacer un programa que diga si un numero es cuadrado perfecto.

**Solucion**: [ejemplo2_sol.c](ejemplo1_sol.c)

3. Hacer un programa que permita calcular el área de diferentes figuras geométricas.

**Solucion**: [ejemplo3_sol.c](ejemplo1_sol.c)

4. Hacer una función que solicite 2 números, genere 10 números aleatorios entre estos 2
números y cuente la cantidad de números pares.

**Solucion**: [ejemplo4_sol.c](ejemplo1_sol.c)

5. Realizar un programa que calcule el valor de la función seno usando la serie equivalente para
ello. Los valores de entrada son x y el número de términos. A continuación se muestra la serie
equivalente:

**Solucion**: [ejemplo5_sol.c](ejemplo1_sol.c)

## 2. Ejemplo de aplicacion



## 3. Problemas propuestos

1. **Problema 1**: Escriba una función llamada múltiplo que tome dos enteros y determine si el segundo es múltiplo del primero. La función deberá tomar dos argumentos enteros y devolver 1 si el segundo es un múltiplo del primero y 0 si no. Luego, utilice esta función en un programa que acepte como entrada una serie de pares de enteros.

2. **Problema 2**: Escribir un programa que lea dos números **x** y **n** y en una función, calcule la suma de la progresión geométrica: 

```
1 + x + x^2 + x^3 + x^4 + ⋯ + x^n
```

2. **Problema 2**: Una ecuación cuadrática es aquella que tiene la siguiente forma:

```
a*x^2 + b*x + c = 0
```

El discriminante es una expresión  que se forma a partir de los coeficientes del polinomio siguiendo la siguiente fórmula:

```
D = b^2 - 4*a*c
```

Según el valor del discriminante se pueden dar tres posibles situaciones:
* **La ecuación cuadrática tiene como solución dos raíces reales y distintas**: Lo cual se da cuando **D > 0**.
* **La ecuación cuadrática tiene dos raíces reales iguales**: Lo cual se da cuando **D = 0**.
*	**La ecuación cuadrática tiene como solución dos raíces complejas conjugadas**: Lo cual se da cuando **D < 0**

a. Realizar una función (declaración y definición) que calcule el discriminante de una ecuación cuadrática. La función se deberá llamar discriminante y deberá recibir tres argumentos reales asociados a los coeficientes del polinomio cuadrático. Como valor de retorno esta debe devolver los siguientes valores para indicar cada uno de los tres posibles casos:
* Cuando D < 0 la función deberá retornar -1.
* Cuando D = 0 la función deberá devolver 0.
* Cuando D > 0 la función deberá devolver 1.

b. Una vez realizado lo anterior realizar un test breve de la función (el cual debe ser sustentado al docente) adaptando la declaración y la definición en el siguiente archivo fuente en el cual esta es invocada en el main:

```C
#include <stdio.h>

// Aquí van los prototipos de la funciones

int main() {
  int x = 1,y = 2,z = 6,w;
  w = discriminante(1,0,1);
  printf("w = %d\n",w);
  w = discriminante(y,z,x);
  printf("w = %d\n",w);
  w = discriminante(y++,--z,5);
  printf("w = %d\n",w);
  return 0;
}


// Aquí van las definiciones de las funciones 

```

c. Realizar un programa que solicite por teclado los valores de los coeficientes y de acuerdo a estos, despliegue si la ecuación cuadrática tiene raíces reales y distintas, reales e iguales o complejas conjugadas. Para tal fin se debe hacer uso de la función discriminante previamente creada.

3. **Problema 3**: Para obtener las raíces de una ecuación de segundo grado utilizando la fórmula:

```
x1 = (-b - D^(1/2))/(2*a)

x2 = (-b + D^(1/2))/(2*a)
```

a. Realizar una función que calcule y despliegue las raíces de una ecuación cuadrática. Tenga en cuenta que el valor de estas depende de D de tal modo que:
* Si D > 0 las raíces son: 

```
x1 = (-b - D^(1/2))/(2*a)

x2 = (-b + D^(1/2))/(2*a)
```

Y la función deberá desplegar algo como: **x1, x2**

* Si D = 0, las raíces serán: 

```
x1 = x2 = -b/(2*a)
```

Y la función deberá desplegar algo como: **x1 con multiplicidad 2**.

* Si D < 0, las raíces serán: 

```
x1 = (-b/(2*a))i - ((-D)^(1/2))/(2*a))j

x2 = (-b/(2*a))i + ((-D)^(1/2))/(2*a))j
```

Y la función deberá desplegar algo como: **R + Ij, R – Ij**.

La función anterior se deberá llamar bachiller, y esta simplemente realizara los cálculos de las raíces desplegando los resultados (no devolviéndolos porque son 2) por lo tanto el valor de retorno deberá ser tipo void. La función anterior deberá invocar la función del punto 1 para el cálculo del discriminante. 

b. Invocar en el main la función varias veces de tal manera que la salida sea la mostrada en la siguiente captura de pantalla:

```
1 2 2
1 3 2
1 2 1
2 3 1
2.1 3.2 1.7 
2 2 0.5

-1.00 + 1.00j, -1.00 - 1.00j  
-2.00. -1.00
-1.00 con multiplicidad 2
-0.76 + 0.48j, -0.76 - 0.48j 
-0.50 con multiplicidad 2
```

c.	Realizar un programa que solicite al usuario los valores de los coeficientes y que haciendo uso de la función bachiller despliegue las raíces de estos coeficientes desplegados en pantalla.

4. **Problema 4**: Escriba una función que tome un valor entero y devuelva el número con sus dígitos en reversa. Por ejemplo, dado el numero 7631, la función deberá devolver 1367.

