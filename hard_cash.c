#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d", &t);
		
	int n, r;
	int k;
	while(t--)
	{	
		r = 0;
		scanf("%d %d", &n, &k);
		int *a = (int *)malloc(n * sizeof(int));
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);

		for(int i = 0; i < n; i++)
		{
			if(a[i] % k <= k/2)
				r = r + (a[i] % k);
			else 
				r = r + (a[i] % k) - k; 
		}		
		
		r = r % k;
		if(r < 0)
			r = r + k;
		
		printf("%d\n", r);
	}
	return 0;
}
