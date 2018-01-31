/*
 * Name         : lab2_p1_res4.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_res4.c -o lab2_p1_res4.out
 * Execution    : ./lab2_p1_res4.out
*/

#include <stdio.h>
int main(void)
{
  int ascii;

  printf("Enter an ASCII code: ");
  scanf("%d", &ascii);
  printf("%d is the ASCII code for %c.\n", ascii, ascii);
  return 0;
}
