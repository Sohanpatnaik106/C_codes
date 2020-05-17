#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t, n, no_of_c, *c;
	long int *l, *b, *area,  length, breadth;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &no_of_c);
		l = (long int *)malloc(n * sizeof(long int)); 			b = (long int *)malloc(n * sizeof(long int));
		c = (int *)malloc(n * sizeof(int));
		area = (long int *)malloc(n * sizeof(long int));		
		for(int i = 0; i < n; i++)
			scanf("%ld %ld %d", &l[i], &b[i], &c[i]);

		long int max_len = l[n-1], max_bre = b[n-1];
		for(int i = n - 1; i >= 0; i--)
		{
			if(i == n-1)
			{				
				length = l[i];
				breadth = b[i];
				area[i] = length * breadth;
			}
			else if(l[i] > l[i+1])
			{
				breadth = b[i];
				length = l[i] - l[i+1];
				area[i] = length * breadth;
			}
			else if(b[i] > b[i+1])
			{
				length = l[i];
				breadth = b[i] - b[i+1];
				area[i] = length * breadth;
			}
			else if(l[i] > l[i+1] && b[i] > b[i+1])
			{
				area[i] = l[i]*b[i] - l[i+1]*b[i+1];
			}
			else
			{
				area[i] = 
			}

			if(l[i] > max_len)
				length = 
		}

		for(int i = 0; i < n; i++)
			printf("%ld ", area[i]);
	}
	return 0;
}
