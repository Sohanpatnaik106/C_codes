#include<stdio.h>

int main()
{
	int t; 
	scanf("%d", &t);

	while(t--)
	{
		int c[4][4], n;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				c[i][j] = 0;

		scanf("%d", &n);
		while(n--)
		{
			char c;
			int time;
			scanf("%c %d", &c, &time);
			a[c - 65][4 - time/3]++;
		}	
		
		int max_ind[4];
		for(int i = 0; i < 4; i++)
		{
			max = a[0][i];
			for(int j = 0; j < 4; j++)
			{
				if(a[j][i] > max)
					max = a[j][i]; 				}
			
		}
	}
}
