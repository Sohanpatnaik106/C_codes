#include<stdio.h>
#include<stdlib.h>

int main()
{
	long int n, sum_up = 0, sum_down = 0;
	int m, c;	
	scanf("%ld", &n);
	scanf("%d %d", &m, &c);
	int *x, *y, *p;
	x = (int *)malloc(n * sizeof(int));
	y = (int *)malloc(n * sizeof(int));
	p = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x[i], &y[i], &p[i]);
		if(m*x[i] - y[i] + c < 0)
			sum_up = sum_up + p[i];
		else if(m*x[i] - y[i] + c > 0)
			sum_down = sum_down + p[i];
	}
	if(sum_up > sum_down)
		printf("%ld", sum_up);
	else
		printf("%ld", sum_down);

	return 0;
}
