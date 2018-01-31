/*
 * Name         : lab2_p1_example1.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example1.c -o lab2_p1_example1.out
 * Execution    : ./lab2_p1_example1.out
*/

#include <stdio.h>

int main() {
  int edad;
  float estatura;
  printf("Digite la edad: ");
  scanf("%d", &edad);
  printf("Digite la estatura (en metros): ");
  scanf("%f", &estatura);
  printf("\n------------------------------------------\n");
  printf("Edad: %d\n",edad);
  printf("Estatura %f\n",estatura);
  return 0;
}