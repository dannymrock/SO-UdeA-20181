/*
 * Name         : lab2_p1_res7.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_res7.c -o lab2_p1_res7.out
 * Execution    : ./lab2_p1_res7.out
*/

#include <stdio.h>

int main(void)
{
  char fname[40];
  char lname[40];

  printf("Enter your first name: ");
  scanf("%s", fname);
  printf("Enter your last name: ");

  scanf("%s", lname);
  printf("%s, %s\n", lname, fname);
  return 0;
}