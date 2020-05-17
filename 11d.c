#include<stdio.h>
#include<stdlib.h>

FILE *fp1, *fp2;
struct stu
{
	int roll;
	char name[15];
	char surname[15];
	float phy_marks;
	float chem_marks;
	float maths_marks;
};

void merge(struct stu A[], int l, int m, int r) 
{ 
    	int i, j, k; 
    	int n1 = m - l + 1; 
    	int n2 =  r - m; 
  
    	struct stu L[n1], R[n2]; 
  
    	for (i = 0; i < n1; i++) 
        	L[i] = A[l+i]; 
    	for (j = 0; j < n2; j++) 
        	R[j] = A[m+1+j]; 
  
    	i = 0;  
    	j = 0;  
    	k = l; 
    	while (i < n1 && j < n2) 
    	{ 
        	if (L[i].roll <= R[j].roll) 
        	{ 
            		A[k] = L[i]; 
            		i++; 
        	} 
        	else
        	{	 
            		A[k] = R[j]; 
            		j++; 
        	} 
        	k++; 
    	} 
    
    	while (i < n1) 
    	{ 
        	A[k] = L[i]; 
        	i++; 
        	k++; 
    	} 
  
    	while (j < n2) 
    	{ 
        	A[k] = R[j]; 
        	j++; 
        	k++; 
    	} 
} 
  
void mergeSort(struct stu A[], int l, int r) 
{ 
    	if (l < r) 
    	{ 
    		int m = l+(r-l)/2; 
  
        	mergeSort(A, l, m); 
        	mergeSort(A, m+1, r); 
  
        	merge(A, l, m, r); 
    	} 
} 

int binarySearch(struct stu A[], int low, int high, int key) 
{ 
    if (high < low) 
        return -1; 
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == A[mid].roll) 
        return mid; 
    if (key > A[mid].roll) 
        return binarySearch(A, (mid + 1), high, key); 
    return binarySearch(A, low, (mid - 1), key); 
}  

int insertSorted(struct stu A[], int n, struct stu key, int capacity) 
{ 
  
    	if (n >= capacity) 
        	return n; 
  
    	int i; 
    	for (i = n - 1; (i >= 0 && (A[i].roll > key.roll)); i--) 
        	A[i + 1] = A[i]; 
  
    	A[i + 1] = key; 
	
  	fprintf(fp2, "%d\n", n+1);
	for(i = 0; i < n+1; i++)
	{
		fprintf(fp2, "%d %s %s %4.1f %4.1f %4.1f\n", A[i].roll, A[i].name, A[i].surname, A[i].phy_marks, A[i].chem_marks, A[i].maths_marks);
	}
    	return (n + 1); 
}

int deleteElement(struct stu A[], int n, int key)  
{  
      
    	int pos = binarySearch(A, 0, n - 1, key); 
  
    	if (pos == -1) 
    	{  
        	printf("Element not found.\n");  
        	return n;  
    	}  
  
   
    	int i;  
    	for (i = pos; i < n - 1; i++)  
        	A[i] = A[i + 1];
	
	fprintf(fp2, "%d\n", n-1);
  	for(int i = 0; i < n-1; i++)
	{
		fprintf(fp2, "%d %s %s %4.1f %4.1f %4.1f\n", A[i].roll, A[i].name, A[i].surname, A[i].phy_marks, A[i].chem_marks, A[i].maths_marks);
	}
  
    	return n - 1;  
} 

int main()
{
	fp1 = fopen("student.txt", "r");
	
	int n;
	fscanf(fp1, "%d", &n);
	struct stu A[100];
	int capacity = 100;
	for(int i = 0; i < n; i++)
	{
		fscanf(fp1, "%d", &A[i].roll);
		fscanf(fp1, "%s", A[i].name);
		fscanf(fp1, "%s", A[i].surname);
		fscanf(fp1, "%f", &A[i].phy_marks);
		fscanf(fp1, "%f", &A[i].chem_marks);
		fscanf(fp1, "%f", &A[i].maths_marks);
		
	}
	//fp2 = fopen("student.txt", "w");
	mergeSort(A, 0, n-1);
	int ch;
 
	printf("Enter:\n1. For insertion\n2. For deletion\n3. Search\n0. Exit\n");
	scanf("%d", &ch);
	while(ch)
	{
		if(ch == 1)
		{
			fp2 = fopen("student.txt", "w");
			struct stu key;
			printf("Enter the details of the student : \n");
			printf("Enter roll : ");
			scanf("%d", &key.roll);
			printf("Enter name : ");
			scanf("%s", key.name);
			printf("Enter surname : ");
			scanf("%s", key.surname);
			printf("Enter physics, chemistry nad maths marks : ");
			scanf("%f %f %f", &key.phy_marks, &key.chem_marks, &key.maths_marks);
			n = insertSorted(A, n, key, capacity);
		}
		else if(ch == 2)
		{
			fp2 = fopen("student.txt", "w");
			int del_roll;
			printf("Enter the roll to be deleted : ");
			scanf("%d", &del_roll);
			n = deleteElement(A, n, del_roll);
		}
		else if(ch == 3)
		{
			int ser_roll;
			printf("Enter the roll to be searched : ");
			scanf("%d", &ser_roll);
			int pos = binarySearch(A, 0, n-1, ser_roll);
			if(pos != -1)
				printf("Element found at %d\n", pos+1);
			else
				printf("Element not found.\n");
		}
		else if(ch == 0)
			break;
		printf("Enter your choice again : ");	
		scanf("%d", &ch);
	}
	fclose(fp1);
	if(fp2!= NULL)
		fclose(fp2);
	return 0;
}
