/*
 * Name         : lab2_p1_res8.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_res8.c -o lab2_p1_res8.out
 * Execution    : ./lab2_p1_res8.out
*/

#include <stdio.h>

int main(void)
{
  float height;
  char name[40];

  printf("Enter your height in inches: ");
  scanf("%f", &height);
  printf("Enter your name: ");
  scanf("%s", name);
  printf("%s, you are %.3f feet tall\n", name, height / 12.0);

  return 0;
}