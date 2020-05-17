#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	long int n;
	scanf("%d", &t);
	while(t--)
	{
		int ctr = 0;
		scanf("%ld", &n);
		char a[100];
		scanf("%s", a);
		
	       	for(int i = 0; i < n - 3; i++)
		{
			if(a[i] == 'J' && a[i+1] == 'G' && a[i+2] == 'E' && a[i+3] == 'C')
				ctr++;
		
		}

		printf("%d\n", ctr);
	}
	return 0;
}
