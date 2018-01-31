/*
 * Name         : lab2_p1_res3.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con printf
 * Compilation  : gcc -Wall lab2_p1_res3.c -o lab2_p1_res3.out
 * Execution    : ./lab2_p1_res3.out
*/

#include <stdio.h>
int main(void)
{
  int toes;
  
  toes = 10;
  
  printf("toes = %d\n", toes);
  printf("Twice toes = %d\n", 2 * toes);
  printf("toes squared = %d\n", toes * toes);
  return 0;
}
/* or create two more variables, set them to 2 * toes and toes * toes */