/*
 * Name         : lab2_p1_example4.c
 * Author       : Stephen Prata
 * Description  : Ejercicio con scanf y printf
 * Compilation  : gcc -Wall lab2_p1_example4.c -o lab2_p1_example4.out
 * Execution    : ./lab2_p1_example4.out
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

int main() {
  int signo;
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
  printf("Seleccione el signo del zodiaco de su preferencia: ");
  scanf("%d",&signo);
  switch(signo) {
	  case ARIES:
	  case LEO:
	  case SAGITARIO:
	    printf("Su signo es categoria fuego\n");
		break;
	  case TAURO:
          case VIRGO:	  
          case CAPRICORNIO:
	    printf("Su signo es categoria tierra\n");
	    break;
	  case GEMINIS:
          case ESCORPIO:	  
	  case PISCIS:
	    printf("Su signo es categoria agua\n");
	    break;
	  case CANCER:
          case LIBRA:	  
	  case ACUARIO:
	    printf("Su signo es categoria aire\n");
	    break;
	  default:
	    printf("\"ERROR\": no está asociado a ningún signo");
  }
  return 0;