#include<stdio.h>
#include<stdlib.h>

int main() {
	int m, b;
	printf("Enter the values of m and b : ");
	scanf("%d %d", &m, &b);

	int **S = (int **)malloc(m * sizeof(int *));
	for(int i = 0; i < m; i++) {
		S[i] = (int *)malloc(b * sizeof(int));
	}

	printf("Enter the data in the Matrix : \n");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < b; j++) {
			scanf("%d", &S[i][j]);
		}
	}

	printf("The array contents are \n");
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < b; j++) {
			printf("%d ", S[i][j]);
		}
		printf("\n");
	}

	printf("#members = %d, #books = %d\n", m, b);
	
	int *favBooks = (int *)malloc(b * sizeof(int));
	for(int i = 0; i < b; i++) {
		favBooks[i] = 0;
	}

	int *goodMembers = (int *)malloc(m * sizeof(int));
	for(int i = 0; i < m; i++) {
		goodMembers[i] = 0;
	}

	int goodReaders = 0;

	int halfbooks = (b%2 == 0) ? b/2 : b/2 + 1;
	for(int i = 0; i < m; i++) {
		int noOfBooksRead = 0;
		for(int j = 0; j < b; j++) {
			if(S[i][j] == 1) {
				noOfBooksRead++;
			}
		}
		if(noOfBooksRead >= halfbooks) {
			goodReaders++;
			goodMembers[i] = 1;
		}
	}

	for(int i = 0; i < b; i++) {
		if(goodMembers[i] == 1) {
			for(int j = 0; j < b; j++) {
				if(S[i][j] == 1) {
					favBooks[j]++;
				}
			}	
		}
	} 

	printf("Members reading at least %d books : ", halfbooks);
	for(int i = 0; i < m; i++) {
		if(goodMembers[i] == 1) {
			printf("%d, ", i+1);
		}
	}
	printf("\n");

	printf("The favorite books are : ");
	for(int i = 0; i < b; i++) {
		if(favBooks[i] == goodReaders) {
			printf("%d, ", i+1);
		}
	}
	printf("\n");
	return 0;
}