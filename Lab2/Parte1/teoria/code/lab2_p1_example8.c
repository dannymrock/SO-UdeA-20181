/*
 * Name         : lab2_p1_example8.c
 * Author       : Stephen Prata
 * Description  : Ejemplo con funciones
 * Compilation  : gcc -Wall lab2_p1_example8.c -o lab2_p1_example8.out
 * Execution    : ./lab2_p1_example8.out
*/

#include <stdio.h>

/* Declaracion de funciones */
int factorial(int n);

/* Funcion principal */
int main() {
  int num; 
  int fac;
  printf("Digite un numero positivo o -1 para terminar: ");
  scanf("%d", &num);
  while(num != -1) {
	 fac = factorial(num);
     printf("%d! = %d\n\n", num, fac);
     printf("Digite un numero positivo o -1 para terminar: ");
     scanf("%d", &num); 	 
  }
  printf("\nSuerte es que le digo ...");
  return 0;
}

/* Definicion de funciones */ 
int factorial(int n) {
  if (n > 0) {
    return n*factorial(n-1);
  }
  else {
    return 1;
  }
}