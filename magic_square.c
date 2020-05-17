#include<stdio.h>

int matrix_rot(int a[][3])
{
	int temp;
	for(int j = 0; j < 3; j++)
	{
		a[0][j] = temp;
		a[0][j] = a[2][j];
		a[2][j] = temp;
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = i; j < 3; j++)
		{
			a[i][j] = temp;
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

}

int main()
{
	int a[3][3], matrix[3][3];
	
	/*a[0][0] = 6, a[0][1] = 1, a[0][2] = 8;
	a[1][0] = 7, a[1][1] = 5, a[1][2] = 3;
	a[2][0] = 2, a[2][1] = 9, a[2][2] = 4; */

	printf("Enter the matrix :\n");
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	}
	matrix_rot(a);
	return 0;
}
