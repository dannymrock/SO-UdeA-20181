/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 1

struct matrix2D {
  int num_rows;
  int num_colums;
  double *data;
} typedef matrix2D;

enum operacion {suma = 1, resta = 2, multiplicacion = 3};

/* Funciones para paralelizar */
struct fila {
  int num_elementos;
  double *data;
  double valor;
} typedef fila;

/* Funciones para paralelizar a nivel de hilo */
void* llenar_fila (void* parameters);

/* Funciones normales */
void inicializar_matrix(double value, matrix2D *M);
void imprimir_matrix(matrix2D *M);
int chequear_dimensiones(enum operacion op, matrix2D M1, matrix2D M2);
matrix2D *sumarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *restarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2);
double get_ms(struct timeval t_ini,struct  timeval t_fin);

/* Funciones de test */
void test_llenarfila(void);
void test_llenar_matrix(void);

int main ()
{
  // test_llenarfila();
  test_llenar_matrix();
  return 0;
}

void test_llenar_matrix(void) {
  matrix2D *M = malloc(sizeof(matrix2D));
  M->num_rows = 10;
  M->num_colums = 10;
  M->data = malloc(sizeof(double)*M->num_rows*M->num_colums);
  inicializar_matrix(3, M);
  imprimir_matrix(M);
  free(M);
}

void inicializar_matrix(double value, matrix2D *M) {
  fila *f[M->num_rows];
  pthread_t threads_ids[M->num_rows];
  fila f_unica;
  f_unica.valor = value;
  f_unica.num_elementos = M->num_colums;
  int i;
  for(i = 0; i < M->num_rows; i++) {
    // Acceso a cada fila de la matrix
    f_unica.data = M->data + i*M->num_rows;
    f[i] = &f_unica;
    // Creando un hilo para llenar cada fila
    pthread_create (&threads_ids[i], NULL, &llenar_fila, f[i]);
    pthread_join(threads_ids[i],NULL);
  }
}

void imprimir_matrix(matrix2D *M) {
  for(int i = 0; i < M->num_rows; i++) {
    printf("[ ");
    for(int j = 0; j < M->num_colums; j++) {
      printf("%lf ", *((M->data + i) + j*M->num_colums));
    }
    printf(" ]\n");
  }
}

int chequear_dimensiones(enum operacion op, matrix2D M1, matrix2D M2) {
  if (op == suma | op == resta) {
    if((M1.num_rows == M2.num_rows) && (M1.num_colums == M2.num_colums)) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
  else {
    if(M1.num_colums == M2.num_rows) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}

matrix2D *sumarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  if (chequear_dimensiones(suma,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M1->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(int i = 0; i < MR->num_rows; i++) {
      for(int j = 0; j < MR->num_colums; j++) {
        *((MR->data + i) + j*MR->num_colums) = *((M1->data + i) + j*M1->num_colums) + *((M2->data + i) + j*M2->num_colums);
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}

matrix2D *restarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M1->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(int i = 0; i < MR->num_rows; i++) {
      for(int j = 0; j < MR->num_colums; j++) {
        *((MR->data + i) + j*MR->num_colums) = *((M1->data + i) + j*M1->num_colums) - *((M2->data + i) + j*M2->num_colums);
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}

matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  double acum = 0;
  int i,j,k;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M2->num_colums;

    MR->data = malloc(sizeof(double)*M1->num_rows*M2->num_colums);
    for(i = 0; i < M1->num_rows; i++) {
      for(j = 0; j < M2->num_colums; j++) {
        for(k = 0; k < M1->num_rows; k++) {
          acum += *((M1->data + i) + k*M1->num_colums) + *((M2->data + k*M2->num_colums) + j);
        }
        *((MR->data + i) + j*MR->num_colums) = acum;
        acum = 0;
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}

double get_ms(struct timeval t_ini,struct timeval t_fin) {
  return (t_fin.tv_sec - t_ini.tv_sec)*1000 + (t_fin.tv_usec - t_ini.tv_usec)/1000.0;
}

/* Funciones para paralelizar */
void* llenar_fila (void* parameters)
{

  fila *p = (fila*) parameters;
  int i;
  for (i = 0; i < p->num_elementos; ++i)
    *(p->data + i) = p->valor;
  return NULL;
}

void test_llenarfila(void) {
  double v[4];
  fila f1;
  f1.num_elementos = 4;
  f1.valor = 2;
  f1.data = v;
  llenar_fila(&f1);
  for (int i = 0; i < f1.num_elementos; i++) {
    printf("%lf ",*(f1.data + i));
  }
  printf("\n");
}
