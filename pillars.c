#include<stdio.h>

int main()
{
	int n, count = 0;
	scanf("%d", &n);
	
	for(int i = 2; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(j % i != 0)
				count++;
		}
	}	
	count = 2*(count + n - 1) + 1;
	printf("%d\n", count);

	return 0;
}
