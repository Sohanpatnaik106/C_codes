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
	float total_marks;
	char grade;
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
        	if (L[i].total_marks >= R[j].total_marks) 
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

int main()
{
	fp1 = fopen("student.txt", "r");
	int n;
	fscanf(fp1, "%d", &n);
	struct stu *A = (struct stu *)malloc(n * sizeof(struct stu));
	for(int i = 0; i < n; i++)
	{
		fscanf(fp1, "%d", &A[i].roll);
		fscanf(fp1, "%s", A[i].name);
		fscanf(fp1, "%s", A[i].surname);
		fscanf(fp1, "%f", &A[i].phy_marks);
		fscanf(fp1, "%f", &A[i].chem_marks);
		fscanf(fp1, "%f", &A[i].maths_marks);
		A[i].total_marks = A[i].phy_marks + A[i].chem_marks + A[i].maths_marks;

		if(A[i].total_marks/3 <= 100 && A[i].total_marks/3 > 90)
			A[i].grade = 'A';
		else if(A[i].total_marks/3 <= 90 && A[i].total_marks/3 > 80)
			A[i].grade = 'B';
		else if(A[i].total_marks/3 <= 80 && A[i].total_marks/3 > 70)
			A[i].grade = 'C';
		else if(A[i].total_marks/3 <= 70 && A[i].total_marks/3 > 60)
			A[i].grade = 'D';
		else if(A[i].total_marks/3 <= 60 && A[i].total_marks/3 > 50)
			A[i].grade = 'E';
		else if(A[i].total_marks/3 <= 50 && A[i].total_marks/3 > 30)
			A[i].grade = 'P';
		else if(A[i].total_marks/3 <= 30)
			A[i].grade = 'F';
	}
	mergeSort(A, 0, n-1);
	
	fp2 = fopen("grade.txt", "w");
	for(int i = 0; i < n; i++)
	{
		fprintf(fp2, "%s %s %d %4.1f %c\n", A[i].name, A[i].surname, A[i].roll, A[i].total_marks, A[i].grade);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}	
