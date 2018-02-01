/*
 * Name         : lab2_p1_res9.c
 * Author       : SO UdeA
 * Description  : Ejercicio que obtiene un coeficiente binomial
 * Compilation  : gcc -Wall lab2_p1_res9.c -o lab2_p1_res9.out
 * Execution    : ./lab2_p1_res9.out
*/

#include <stdio.h>

/* Declaracion de funciones */
int factorial(int n);
int coefBinomial(int m, int n);

/* Funcion principal */
int main() {
  int seguir; 
  int m, n;
  int cf;
  printf("Digite un numero positivo o -1 para terminar: ");
  scanf("%d", &seguir);
  while(seguir != -1) {
	 printf("Ingrese el numero m: ");
     scanf("%d",&m);	 
	 printf("Ingrese el numero n: ");
	 scanf("%d",&n);
	 if (n > m) {
	   printf("El numero m debe ser mayor que n\n");
	 }
	 else {
       cf = coefBinomial(m,n);
	   printf("El valor de m sobre n es: %d\n", cf);
	 }
     printf("\nDigite un numero positivo o -1 para terminar: ");
     scanf("%d", &seguir); 	 
  }
  printf("\nSuerte es que le digo...\n");
  return 0;
}

/* Definicion de funciones */ 

// Coeficiente binomial
int coefBinomial(int m, int n) {
	int coef;
	coef = (factorial(m))/(factorial(n)*factorial(m - n));
	return coef;
}

// Factorial de un numero
int factorial(int n) {
	if (n > 0) {
		return n*factorial(n-1);
	}
	else {
		return 1;
	}
}