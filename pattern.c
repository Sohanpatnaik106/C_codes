#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

	int n;
  	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
    	{	
        	for(int j = 1; j <= 2*n - 1; j++)
        	{
            		if(i == 1)
                		printf("%d ", n);
            		else
            		{
                		if(j < i || j >= 2*n - i + 1)
                		{
                    			printf("%d ", abs(n-j)+1);
                		}
                		else
                		{
                    			printf("%d ", n-i+1);
                		}
            		}
        	}
        	printf("\n");
    	}

    	for(int i = 1; i <= n-1; i++)
    	{
        	for(int j = 1; j <= 2*n - 1; j++)
        	{
            		if(i == n-1)
                		printf("%d ", n);
            		else
            		{
                		if(j < n-i || j > n+i)
                    			printf("%d ", abs(n-j)+1);
                		else
                		{
                    			printf("%d ", i+1);
                		}
            		}
		}
            	printf("\n");
    	}
    	return 0;
}
