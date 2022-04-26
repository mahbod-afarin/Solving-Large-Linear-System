#ifndef _LU_H_
#define _LU_H_

#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "mkl.h"
#include "mkl_lapack.h"
#include "../include/util.h"

void lapack_lu(double *A, double *B, int n);
void naive_lu(double *A, double *B, int n);
void block_lu(double *A, double *B, int n, int b);

#endif // _LU_H_