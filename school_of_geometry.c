#include<stdio.h>
#include<stdlib.h>

void sort(int *a, int *b, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
			if(b[j] > b[j+1])
			{
				int temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
}	

int main()
{
	int t;
	scanf("%d", &t);

	int n, s;
	while(t--)
	{
		s = 0;
		scanf("%d", &n);
		int *A = (int *)malloc(n * sizeof(int));
		int *B = (int *)malloc(n * sizeof(int));
		for(int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &B[i]);

		int ctr = 0;
		for(int i = 0; i < n-1 ; i++)
		{
			if(A[i] == A[i+1] && B[i] == B[i+1])
				ctr++;
		}

	
		if(ctr == n-1)
		{
			if(A[0] < B[0])
				s = n * A[0];
			else
				s = n * B[0];
		}
		
		else
		{	
			sort(A, B, n);
		
			for(int i = 0; i < n; i++)
			{
				if(A[i] < B[i])
					s = s + A[i];
				else
					s = s + B[i];
			}
		}
		
		printf("%d\n", s);
	}

	return 0;
}
