/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <pthread.h>
#include <stdio.h>


struct matrix2D {
  int num_rows;
  int num_colums;
  double *data;
};



int main ()
{
  int rows_M1 = 4;
  int columns_M1 = 4;
  int rows_M2 = 4;
  int columns_M2 = 4;

  double *A = malloc(sizeof(double)*rows_M1*columns_M1);
  double *B = malloc(sizeof(double)*rows_M2*columns_M2);
  double *C;
  double *B = malloc(sizeof(double)*rows_M1*columns_M2);

  return 0;
}
