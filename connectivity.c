#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define NROOMS 10

void genDoors(int A[][NROOMS])
{
	srand(time(0));
	for(int i = 0; i < NROOMS; i++)
	{
		for(int j = 0; j < NROOMS; j++)
		{
			if(i != j)
				A[i][j] = A[j][i] = rand() % 2;
			else 
				A[i][j] = 1;
		}
	}
}

void printConn(int A[][NROOMS])
{
	for(int i = 0; i < NROOMS; i++)
	{
		for(int j = 0; j < NROOMS; j++)
			printf("%d ", A[i][j]);

		printf("\n");
	}
}

void boolMul(int A[][NROOMS], int B[][NROOMS], int C[][NROOMS])
{
	for(int i = 0; i < NROOMS; i++)
	{
		for(int j = 0; j < NROOMS; j++)
		{
			C[i][j] = 0;
			for(int k = 0; k < NROOMS; k++)
			{
				C[i][j] = C[i][j] + A[i][k]*B[k][j]; 
			}
			if(C[i][j] != 0)
				C[i][j] = 1; 
		}
	}
}

int main()
{
	int A[NROOMS][NROOMS], C[NROOMS][NROOMS];
	genDoors(A);
	printConn(A);
	
	for(int i = 0; i < NROOMS; i++)
	{
		boolMul(A, A, C);
	}

	printf("\n");
	
	printConn(C);
	return 0;
}

