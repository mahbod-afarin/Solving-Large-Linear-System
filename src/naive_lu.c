#include "../include/lu_functions.h"
#include "../include/for_you_to_do.h"

void naive_lu(double *A, double *B, int n)
{
    int ipiv[n], i;
    for (i = 0; i < n; i++) {
        ipiv[i] = i;
    }

    int success = mydgetrf(A, ipiv, n);

    if (success) 
    {
        printf("LU factoration failed: coefficient matrix is singular.\n");
        return;
    }

    mydtrsv('L', A, B, n, ipiv);
    mydtrsv('U', A, B, n, ipiv);

}
