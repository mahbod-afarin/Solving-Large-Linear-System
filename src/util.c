#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/util.h"

int print_matrix(const double *A, const int m, const int n)
{
	int i;
	printf("[");
	for (i = 0; A + i && i < m * n; i++)
	{

		if ((i + 1) % n == 0)
			printf("%5.2f ", A[i]);
		else
			printf("%5.2f, ", A[i]);
		if ((i + 1) % n == 0)
		{
			if (i + 1 < m * n)
				printf(";\n");
		}
	}
	printf("]\n");

    if (i != m * n) return -1;
    return 0;
}

int randomize_matrix(double *A, const int m, const int n)
{
	srand(time(NULL));
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; A + i * n + j && j < n; j++)
		{
			A[i * n + j] = (double)(rand() % 100) + 0.01 * (rand() % 100);
			if ( (rand() % 2) == 0 )
			{
				A[i * n + j] *= -1.;
			}
		}
        if (j != n) return -1;
	}
    return 0;
}

double get_sec()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec + 1e-6 * time.tv_usec);
}


int matrix_copy(double *C, const double *D, const int m, const int n)
{
	int i;

	for (i = 0; C + i && D + i && i < m * n; i++)
	{
		C[i] = D[i];
	}
    if (i != m * n) 
    {
        if (!(C + i)) 
        {
            printf("invalid memory access at %d on input 1, return -1\n", i);
            return -1;
        }
        if (!(D + i))
        {
            printf("invalid memory access at %d on input 2, return -2\n", i);
            return -2;
        }
    }

    return 0;
}

int verify_matrix(const double *C, const double *D, const int m, const int n)
{
	int i;
	double diff;
	for (i = 0; i < m * n; i++)
	{
		diff = fabs(C[i] - D[i]);
        if (diff > 1e-3) 
		{
			//printf("correct answer: %f != %f in i = %d\n",C[i],D[i],i);
			//printf("but look, %f = %f in %d!\n",C[i+1],D[i+1],i+1);
			break;
		}
	}

	if (diff > 1e-3) 
    {
        return -1;
    }
    else
    {
        return 0;
    }
    
}
