#include "../include/for_you_to_do.h"
#include <math.h>
/**
 *
 * this function computes LU factorization
 * for a square matrix
 *
 * syntax
 *
 *  input :
 *      A     n by n , square matrix
 *      ipiv  1 by n , vector
 *      n            , length of vector / size of matrix
 *
 *  output :
 *      return -1 : if the matrix A is singular (max pivot == 0)
 *      return  0 : return normally
 *
 **/
int mydgetrf(double *A, int *ipiv, int n)
{
    /* add your code here */
		int i, maxind, t, j , temps,k;
	        double max;
	        for(i=0; i<n-1; i++)
	        {
	                /*Pivoting*/
	                maxind = i;
	                max = fabs(A[i*n+i]);
	                for(t=i+1; t<n; t++)
	                {
	                        if(fabs(A[t*n+i])>max)
	                                {
	                                maxind=t;
	                                max=fabs(A[t*n+i]);
	                                }
	                }
	                if(max==0) return -1;
	                else if(maxind != i)
	                        {
	                                /*save pivot information*/
	                                temps =ipiv[i];
	                                ipiv[i] = ipiv[maxind];
	                                ipiv[maxind] = temps;
	                                /*swap rows*/
	                                for(j=0;j<n;j++)
	                                {
	                                        double tempv;
	                                        tempv = A[i*n+j];
	                                        A[i*n+j] = A[maxind*n+j];
	                                        A[maxind*n+j] = tempv;
	                                }
	                        }
	                /*factorization*/
	                for(j=i+1;j<n;j++)
	                {
	                        A[j*n+i] = (double)A[j*n+i]/A[i*n+i];
	                        for(k=i+1;k<n;k++)
	                                A[j*n+k] = A[j*n+k] - A[j*n+i] * A[i*n+k];
	                }
	        }

    return 0;
}

/**
 *
 * this function computes triangular matrix - vector solver
 * for a square matrix . according to lecture slides, this
 * function computes forward AND backward subtitution in the
 * same function.
 *
 * syntax
 *
 *  input :
 *      UPLO  'L' or 'U' , denotes whether input matrix is upper
 *                         lower triangular . ( forward / backward
 *                         substitution )
 *
 *      A     n by n     , square matrix
 *
 *      B     1 by n     , vector
 *
 *      ipiv  1 by n     , vector , denotes interchanged index due
 *                                  to pivoting by mydgetrf()
 *
 *      n                , length of vector / size of matrix
 *
 *  output :
 *      none
 *
 **/
void mydtrsv(char UPLO, double *A, double *B, int n, int *ipiv)
{
	/* add your code here */
				double y[n];
        int i;
        int j;
        if(UPLO =='L')
        {
        y[0] = B[ipiv[0]];
        for (i=1; i<n; i++)
        {
                double sum=0;
                for (j = 0; j < i; j++)
                        sum += y[j] * A[i*n+j];
                y[i] = B[ipiv[i]]-sum;
        }
        }

        else if(UPLO =='U')
        {
        y[n-1] =(double)B[n-1] / A[(n - 1) * n + (n - 1)];
        for (i = n-2; i >= 0; i--)
        {
                double sum =0;
                for (j = i + 1; j < n; j++)
                        sum += y[j] * A[i * n + j];
                y[i] = (B[i] - sum) / A[i * n + i];
        }



        }
        for(i = 0; i < n; i++)
                B[i] = y[i];

	return;
}

/**
 *
 * Same function as what you used in lab1, cache_part4.c : optimal( ... ).
 *
 **/
void mydgemm(double *A, double *B, double *C, int n, int matx, int maty, int b)
{
	int i , j , k , iB, jB , kB;
        for( k = 0;k < maty ; k += b)
                for( i = 0;i < matx;i += b)
                        for( j = 0;j < matx ;j += b)
                        {
                                for( kB = k;kB < k + b && kB < maty;kB += 2)
                                        for( iB = i;iB <i + b && iB < matx;iB += 2)
                                        {
                                                register int regA00 = iB *n + kB;
                                                register int regA10 = regA00 + n;
                                                register double a00 = A[regA00],a01 = A[regA00 + 1],a10 = A[regA10],a11 = A[regA10 + 1];
                                                for(jB = j;jB < j + b && jB < matx;jB += 2)
                                                {
                                                        register int regB00 = kB * n + jB,regC00 = iB * n + jB;
                                                        register int regB10 = regB00 + n,regC10 = regC00 + n;
                                                        register double b00 = B[regB00],b01 = B[regB00 + 1],b10 = B[regB10],b11 = B[regB10 + 1];
                                                        register double c00 = C[regC00],c01 = C[regC00 + 1],c10 = C[regC10],c11 = C[regC10 + 1];
                                                        C[regC00] -= a00 * b00 + a01 * b10;
                                                        C[regC00+1] -= a00 * b01 + a01 * b11;
                                                        C[regC10] -= a10 * b00 + a11 * b10;
                                                        C[regC10+1] -= a10 * b01 + a11 * b11;

                                                }
                                        }
                        }/*
	int i , j , k, iB , jB , kB;
		for(k = 0;k < maty;k += b)
			for(i = 0;i < matx;i += b)
				for( j = 0;j < matx;j += b)
				{
					for(kB = k;kB <k + b && kB < maty;kB++)
						for(iB = i;iB < i + b && iB < matx;iB++)
						{
							register double sum = A[iB * n + kB];
							for(jB = j;jB < j + b && jB < matx;jB++)
								C[iB * n + jB] -=sum*B[kB * n + jB];
						}
				}*/


}

/**
 *
 * this function computes triangular matrix - vector solver
 * for a square matrix using block gepp introduced in course
 * lecture .
 *
 * just implement the block algorithm you learned in class.
 *
 * syntax
 *
 *  input :
 *      UPLO  'L' or 'U' , denotes whether input matrix is upper
 *                         lower triangular . ( forward / backward
 *                         substitution )
 *
 *      A     n by n     , square matrix
 *
 *      B     1 by n     , vector
 *
 *      ipiv  1 by n     , vector , denotes interchanged index due
 *                                  to pivoting by mydgetrf()
 *
 *      n                , length of vector / size of matrix
 *
 *  output :
 *      return -1 : if the matrix A is singular (max pivot == 0)
 *      return  0 : return normally
 *
 **/
int mydgetrf_block(double *A, int *ipiv, int n, int b)
{
		int i, maxind, k, j, ib, end, temps, t;
		double max;
		for(ib = 0; ib < n - 1; ib += b)
		{
			/*Partial Pivoting*/
			end = ((n-1) > (ib + b -1)) ? (ib + b - 1) : n-1;
			//printf("end = %d\n",end);
			for(i = ib; i <= end; i++)
			{
				maxind = i;
				max = fabs(A[i*n+i]);
				for(k = i+1; k < n; k++)
				{
					if(fabs(A[k * n + i]) > max)
					{
						maxind = k;
						max = fabs(A[k * n + i]);
					}
				}
				if(max == 0) return -1;
				else if (maxind !=i)
				{

					/*Save Pivot Infortmation*/
					temps = ipiv[i];
					ipiv[i] = ipiv[maxind];
					ipiv[maxind] = temps;
					/*Swap rows*/
					for(j = 0; j < n; j++)
					{
						double tempv;
						tempv = A[i * n + j];
						A[i * n + j] = A[maxind * n + j];
						A[maxind * n + j] = tempv;
					}
				}

				/*Update columns i+1 to end*/
				for(j = i + 1; j < n; j++)
				{
					A[j * n + i] = (double)A[j * n + i] / A[i * n + i];
					for(t = i + 1;t <= end; t++)
					{
						A[j*n+t] = A[j*n+t] - A[j*n+i] * A[i*n+t];
					}
				}
			}

			/*inv(LL)*/
			/*double y;y = (double *) malloc(sizeof(double) * (end - ib + 1) * (n - end));y[0] =; */
			for(i = ib; i <= end; i++)
			{
				for(k = end +1; k < n; k++)
				{
					double sum = 0;
					for(j = ib; j < i; j++)
					{
						sum += A[i * n + j] * A [j * n + k];
					}
					A[i * n + k] -= sum;
				}
			}
			/*Delayed update of rest of matrix using matrix-matrix multiplication*/
			/*void mydgemm(double *A, double *B, double *C, int n, int matx, int maty, int b)*/
			//if(end!=n)
			mydgemm(&A[(end+1) * n + ib], &A[ib * n + end +1], &A[(end+1) * n + (end + 1)], n , (n - end - 1) , (end-ib+1/*=b*/), 32);
		}
    return 0;
}
