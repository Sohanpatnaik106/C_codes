#include<stdio.h>

int main()
{
	int A[20], n, x;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	printf("Enter the array elements : ");
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	printf("Enter the sum to be checked : ");
	scanf("%d", &x);

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(A[i] + A[j] == x)
				printf("Pair found : %d, %d\n", A[i], A[j]);
		}
	}
	return 0; 
}


/* For checking only one pair, sort the array using quick sort, O(nlogn) and then maintain two indices l and r, if A[l] + A[r] < sum, increment l, else increment r, if equal print A[l] and A[r], then break the loop. 

In the above code it prints all the combinations with complexity O(n^2) */ 	
