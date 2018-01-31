/*
 * Name         : lab2_p1_example7.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example7.c -o lab2_p1_example7.out
 * Execution    : ./lab2_p1_example7.out
*/

#include <stdio.h>

int num; // Numero a leer

int main() {
  
  do {
    scanf("%d",&num); 
    if(num >= 0) {
      printf("Numero positivo, siga usted\n"); 
    }
    else {
      printf("Numero negativo asi que suerte\n"); 
    }
  } while(num >= 0) {    
  printf("\nFin del programa\n");
  return 0;
}