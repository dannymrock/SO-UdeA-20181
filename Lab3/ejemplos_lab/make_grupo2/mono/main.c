#include <stdio.h>

void f1(void);
void f2(void);
void f3(void);
 
int main() {
  printf("Este es un programa...");
  f1();
  f2();
  f3();
  return 0;
}

void f1(void) {
  printf("Hola!!!\n");
}


void f2(void) {
  printf("Hello!!!\n");
}


void f3(void) {
  printf("Hallo!!!\n");
}
