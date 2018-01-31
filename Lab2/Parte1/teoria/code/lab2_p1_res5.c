/*
 * Name         : lab2_p1_res5.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_res5.c -o lab2_p1_res5.out
 * Execution    : ./lab2_p1_res5.out
*/

#include <stdio.h>

int main(void)
{
  float num;
  printf("Enter a floating-point value: ");
  scanf("%f", &num);
  printf("fixed-point notation: %f\n", num);
  printf("exponential notation: %e\n", num);
  return 0;
}