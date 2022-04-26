#ifndef _UTIL_H_
#define _UTIL_H_


#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_matrix(const double *A, const int m, const int n);
int randomize_matrix(double *A, const int m, const int n);
double get_sec();
int matrix_copy(double *C, const double *D, const int m, const int n);
int verify_matrix(const double *C, const double *D, const int m, const int n);


#endif // _UTIL_H_