/*
 * Name         : lab2_p1_example2.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example2.c -o lab2_p1_example2.out
 * Execution    : ./lab2_p1_example2.out
*/

#include <stdio.h>

int main() {
  char nombre[15]; // Almacena maximo 14 caracteres
  printf("Digite el nombre: ");
  scanf("%s",nombre);
  printf("\nHola: %s\n",nombre);
  return 0;
}