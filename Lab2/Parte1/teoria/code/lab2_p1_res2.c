/*
 * Name         : lab2_p1_res2.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con printf
 * Compilation  : gcc -Wall lab2_p1_res2.c -o lab2_p1_res2.out
 * Execution    : ./lab2_p1_res2.out
*/

#include <stdio.h>

int main(void)
{
  int ageyears; /* age in years */
  int agedays; /* age in days */
  /* large ages may require the long type */
  ageyears = 44;
  agedays = 365 * ageyears;
  printf("An age of %d years is %d days.\n", ageyears, agedays);
  return 0;
}