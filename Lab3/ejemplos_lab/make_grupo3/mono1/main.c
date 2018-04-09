#include <stdio.h>

void hola(int opc);

int main() {
  printf("Hola...\n");
  saludar(1);
  saludar(2);
  return 0;
}

void hola(int opc) {
  if(opc == 1) {
    printf("Hola!!!\n");
  }
  else if(opc == 2) {
    printf("Hi!!!\n");
  }
  else {
    printf("ERROR: Opcion invalida!!!\n");
  }
}
