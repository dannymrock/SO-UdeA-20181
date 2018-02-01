/*
 * Name         : ejemploX.c
 * Author       : SO UdeA
 * Description  : Ejercicio que obtiene la categoria a la que pertenece cada signo del zodiaco
 * Compilation  : gcc -Wall ejemploX.c -o ejemploX
 * Execution    : ./ejemploX
*/

#include <stdio.h>

#define ARIES 1
#define TAURO 2
#define GEMINIS 3
#define CANCER 4
#define LEO 5
#define VIRGO 6
#define LIBRA 7
#define ESCORPIO 8
#define SAGITARIO 9
#define CAPRICORNIO 10
#define ACUARIO 11
#define PISCIS 12

enum tipo {
    fuego = 0,
    tierra = 1,
    agua = 2,
    aire = 3,
	invalido = -1,
};
enum tipo tipoSigno;

/* Declaración de las funciones */
void menu(void);
tipoSigno obtenerTipo(int signo);

int main() {
  int signo;
  tipoSigno tSigno;
  menu();
  printf("Seleccione el signo del zodiaco de su preferencia: ");
  scanf("%d",&signo);
  ts =  obtenerTipo(signo);
  switch(signo) {
	  case fuego:
	    printf("Su signo es categoria fuego\n");
		break;
	  case tierra:
	    printf("Su signo es categoria tierra\n");
		break;
	  case agua:
	    printf("Su signo es categoria agua\n");
		break;
	  case aire:
	    printf("Su signo es categoria aire\n");
		break;
	  default:
	    printf("\"ERROR\": no está asociado a ningún signo");
  }
  return 0;
}

/* Definicion de las funciones */
void menu(void) {
  printf("SIGNOS DEL ZODIACO\n");
  printf("1. Aries\n");
  printf("2. Tauro\n");
  printf("3. Géminis\n");
  printf("4. Cáncer\n");
  printf("5. Leo\n");
  printf("6. Virgo\n");
  printf("7. Libra\n");
  printf("8. Escorpio\n");
  printf("9. Sagitario\n");
  printf("10. Capricornio\n");
  printf("11. Acuario\n");
  printf("12. Piscis\n\n");	
}

tipoSigno obtenerTipo(int signo) {
  if (signo == ARIES || signo == LEO || signo == SAGITARIO) {
    return fuego;
  }
  else if (signo == TAURO || signo == VIRGO || signo == CAPRICORNIO) {
    return tierra;
  }	
  else if (signo == GEMINIS || signo == ESCORPIO || signo == PISCIS) {
    return agua;    
  }		
  else if (signo == CANCER || signo == LIBRA || signo == ACUARIO) {
    return aire;   
  }
  else {
    return invalido; 
  }		
}