#include<stdio.h>

int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid]) 
        return mid; 
    if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
    return binarySearch(arr, low, (mid - 1), key); 
} 

int main()
{
	int A[] = {1, 2, 3, 4, 5};
	int n = 5;
	int pos = binarySearch(A, 0, n-1, 3);
	printf("%d", pos);
	return 0;
}
