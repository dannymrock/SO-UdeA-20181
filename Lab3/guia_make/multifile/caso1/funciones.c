#include "funciones.h"

extern int opc;

double area_triangulo(double base, double altura) {
  double area;
  area = base*altura/2;
  return area;
}

double area_circulo(double radio) {
    float area;
    area = PI*radio*radio;
    return area;
}

double area_rectangulo(double base, double altura) {
  return base*altura;
}

double area_trapecio(double base_mayor, double base_menor, double altura) {
  double area = ((base_mayor+base_menor)*altura)/2;
  return area;
}

void menu(void) {
    printf("MENU\n");
    printf("1. Hallar el area del triangulo\n");
    printf("2. Hallar el area del rectangulo\n");
    printf("3. Hallar el area del trapecio\n");
    printf("4. Hallar el area del circulo\n");
    printf("5. Salir\n");
    printf("\n\nSeleccione una opcion: ");
    scanf("%d",&opc); // opc es global
}

void borrar_pantalla(void) {
    getchar();
    printf("\033[2J\033[0;0f");
    printf("\033[%d;%df", 0, 0);
}
