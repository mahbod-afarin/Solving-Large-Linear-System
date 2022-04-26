#ifndef _TODO_H_
#define _TODO_H_

#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int mydgetrf(double *A, int *ipiv, int n);
int mydgetrf_block(double *A, int *ipiv, int n, int b);
void mydtrsv(char UPLO, double *A, double *B, int n, int *ipiv);

#endif // _TODO_H_