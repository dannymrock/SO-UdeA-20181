#include <stdio.h>

void incremento(int *num);

int main() {
  int N = 3;
  printf("Valor de N antes del llamado a la funcion: %d\n", N);
  incremento(&N);
  printf("Valor de N despues del llamado a la funcion: %d\n", N);
  return 0;
}

void incremento(int *num) {
  *num += 1;
}