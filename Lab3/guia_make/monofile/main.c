#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

void menu(void);
double area_triangulo(double, double);
double area_rectangulo(double, double);
double area_trapecio(double, double, double);
double area_circulo(double);
void borrar_pantalla(void);
 
int opc; // Variable global para la seleccion

int main() {
    double b, h, r, B, A; 
    do {
        menu();
        switch (opc) {
            case 1:
                printf("Digite la base del triangulo: ");
                scanf("%lf", &b);
                printf("Digite la altura del triangulo: ");
                scanf("%lf", &h);
                A = area_triangulo(b, h);
                printf("El area del triangulo es: %.2lf\n", A);
                break;
            case 2:
                printf("Digite la base del rectangulo: ");
                scanf("%lf", &b);
                printf("Digite la altura del rectangulo: ");
                scanf("%lf", &h);
                A = area_rectangulo(b, h);
                printf("El area del rectangulo es: %.2lf\n", A);
                break;
            case 3:
                printf("Digite la base menor del trapecio: ");
                scanf("%lf", &b);
		printf("Digite la base mayor del trapecio: ");
                scanf("%lf", &B);
		printf("Digite la altura del trapecio: ");
                scanf("%lf", &h);
                printf("El area del trapecio es: %.2lf\n", area_trapecio(B,b,h));
                break;
            case 4:
                printf("Digite el radio del circulo: ");
                scanf("%lf", &r);
                A = area_circulo(r);
                printf("El area del circulo es: %.2lf\n", area_circulo(r));
                break;
	    case 5: 
		printf("Hasta la vista baby Jesus\n");
		break;
            default:
                printf("\n\nOpcion no valida !!!!\n");
        }
        printf("Presione una tecla para continuar...\n");
        getchar();	
        borrar_pantalla();
    }while(opc != 5);
    printf("Fin del programa, Suerte es que le digo\n");
    return 0;
}


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
