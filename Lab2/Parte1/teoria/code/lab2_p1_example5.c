/*
 * Name         : lab2_p1_example5.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example5.c -o lab2_p1_example5.out
 * Execution    : ./lab2_p1_example5.out
*/

#include <stdio.h>

int main() {
  int N;   // Cantidad de numeros
  int num; // Numero a leer
  int i;   // i-esimo numero
  int sum = 0; // Suma de los numeros
  printf("Ingrese la cantidad de numeros a sumar: ");
  scanf("%d",&N);
  for(i = 0; i < N; i++) {
    scanf("%d",&num);
    sum += num;
  }
  printf("\nLa suma es: %d\n",sum);
  return 0;
}