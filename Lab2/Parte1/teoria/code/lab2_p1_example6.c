/*
 * Name         : lab2_p1_example6.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example6.c -o lab2_p1_example6.out
 * Execution    : ./lab2_p1_example6.out
*/

#include <stdio.h>

const unsigned CENTINELA = 9999;
int main() {
  int num; // Numero a leer
  int sum = 0; // Suma de los numeros
  scanf("%u",&num);
  while(num != CENTINELA) {
    sum += num;
    scanf("%d",&num);
  }
  printf("\nLa suma es: %d\n",sum);
  return 0;
}