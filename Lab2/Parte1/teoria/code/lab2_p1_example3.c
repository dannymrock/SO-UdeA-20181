/*
 * Name         : lab2_p1_example3.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example3.c -o lab2_p1_example3.out
 * Execution    : ./lab2_p1_example3.out
*/

#include <stdio.h>

int main() {
  float nota;
  printf("Introduzca la nota que saco el pelao: ");
  scanf("%f",&nota);
  /* Implementacion con if anidados */
  if(nota >= 4.5) {
    // nota >= 4.5 --> E
	printf("La nota es: E\n");
  }
  else if(nota >= 4.0) {
    // nota < 4.5 y nota >= 4.0 --> 4 <= nota < 4.5 --> B+
	printf("La nota es: B+\n");
  }
  else if(nota >= 3.5) {
	// nota < 4.0 y nota >= 3.5 --> 3.5 <= nota < 4 --> B
	printf("La nota es: B\n");
  }
  else if(nota >= 3.0) {
	// nota < 3.5 y nota >= 3.0 --> 3.0 <= nota < 3.5 --> B-
	printf("La nota es: B-\n");
  }
  else {
	// nota < 3.0
	printf("La nota es: I\n");
  }
  return 0;
}