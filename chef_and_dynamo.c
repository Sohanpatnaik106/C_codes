#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t, l, n; 
	long long int a, b, c, d, e, s, x;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		x = 1;
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			x = 10 * x;
		scanf("%lld", &a);
		s = 2*x + a;
		printf("%lld\n", s);
		fflush(stdout);
		scanf("%lld", &b);
		c = x - b;		
		printf("%lld\n", c);
		fflush(stdout);
		scanf("%lld", &d);
		e = x - d;
		printf("%lld\n", e);
		fflush(stdout);
		scanf("%d", &l);
		if(l == -1)
			exit(-1);
	}
	return 0;
}
