#include<stdio.h>

void heapify(int *a, int i, int n)
{
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if(largest < n && a[l] > a[largest])
		largest = l;

	if(largest < n && a[r] > a[largest])
		largest = r;

	if(largest != i)
	{
		int temp = a[largest];
		a[largest] = a[i]; 
		a[i] = temp;
		
		heapify(a, largest, n);
	}
}

void heap_sort(int *a, int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
		heapify(a, i, n);

	for(int i = n - 1; i >= 0; i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;

		heapify(a, 0, i);
	}	 
}
	
int main()
{
	int a[30], n;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	
	printf("Enter the elements : ");
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	heap_sort(a, n);
	
	printf("The sorted array is : ");
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}	
