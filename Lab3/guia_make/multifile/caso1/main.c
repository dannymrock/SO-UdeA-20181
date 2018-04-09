#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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
