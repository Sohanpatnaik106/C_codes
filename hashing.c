#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp;

struct countryInfo {
	int popRank;
	char countryName[30];
	int population;
	float yearlyChange;
	int netChange;
	int popDensity;
	struct countryInfo *next;
};

struct sortCountry {
	int popRank;
	char countryName[30];
	int population;
	float yearlyChange;
	int netChange;
	int popDensity;
};  

int hash(char* country) {
	int hashValue = 0;
	int i = 0;
	while((country[i] >= 65 && country[i] <= 90) || (country[i] >= 97 && country[i] <= 122) || (country[i] == 32)) {
		hashValue = hashValue + (int)country[i];
		i++;
	}
	hashValue = hashValue % 7;
	return hashValue;
}

struct countryInfo *insertCountryList(struct countryInfo **head, int popRank, char *countryName, int population, float yearlyChange, int netChange, int popDensity) {
	struct countryInfo *node = (struct countryInfo *)malloc(sizeof(struct countryInfo));
	node->next = NULL;
	node->popRank = popRank;
	strcpy(node->countryName, countryName);
	node->population = population;
	node->yearlyChange = yearlyChange;
	node->netChange = netChange;
	node->popDensity = popDensity;
	node->next = *head;
	*head = node;
	return *head;
}

int printList(struct countryInfo *head)
{
	int ctr = 0;
	while(head != NULL) {
		printf("Population rank : %d\n", head->popRank);
		printf("Country name : %s\n", head->countryName);
		printf("Population : %d\n", head->population);
		printf("Yearly change : %4.2f\n", head->yearlyChange);
		printf("Net change : %d\n", head->netChange);
		printf("Population density : %d\n\n", head->popDensity);
		ctr++;
		head = head->next;
	}
	printf("\n");
	return ctr;
}

int countrySearch(struct countryInfo *head, char *countryName) {
	int flag = 0, i;
	while(head != NULL) {
		for(i = 0; i < strlen(countryName); i++) {
			if(countryName[i] != head->countryName[i]) {
				break;
			}

		}
		if(i == strlen(countryName)) {
			printf("\nThe record exists\n");
			printf("Population rank : %d\n", head->popRank);
			printf("Country name : %s\n", head->countryName);
			printf("Population : %d\n", head->population);
			printf("Yearly change : %4.2f\n", head->yearlyChange);
			printf("Net change : %d\n", head->netChange);
			printf("Population density : %d\n\n", head->popDensity);
			flag = 1;
			break;
		}
		head = head->next;
	}
	return flag;
}

int main() {
	fp = fopen("CountryStat.txt", "r");
	struct countryInfo *hashList[7];
	struct sortCountry A[100];
	int index, bool_value;
	int popRank;
	char countryName[30];
	int population;
	float yearlyChange;
	int netChange;
	int popDensity;
	int Aindex = 0;
	for(int i = 0; i < 7; i++)
		hashList[i] = NULL;
	while(!feof(fp)) {
		fscanf(fp, "%d", &popRank);
		fscanf(fp, " %[^\n]", countryName);
		fscanf(fp, "%d", &population);
		fscanf(fp, "%f", &yearlyChange);
		fscanf(fp, "%d", &netChange);
		fscanf(fp, "%d", &popDensity);
		A[Aindex].popRank = popRank;
		strcpy(A[Aindex].countryName, countryName);
		A[Aindex].population = population;
		A[Aindex].yearlyChange = yearlyChange;
		A[Aindex].netChange = netChange;
		A[Aindex].popDensity = popDensity;
		Aindex++; 
		index = hash(countryName);
		hashList[index] = insertCountryList(&hashList[index], popRank, countryName, population, yearlyChange, netChange, popDensity);
	}
	int lenList = 0;
	for(int i = 0; i < 7; i++) {
		lenList = lenList + printList(hashList[i]);
	}
	printf("Average length of the lists is : %d\n\n", lenList/7);

	int option = 0;
	int minRank = 100;
	int lowestPopulationDensity = hashList[0]->popDensity, highestYearlyChange = hashList[0]->yearlyChange;
	char lowestPopDensCountry[30], highestYearlyChangeCountry[30];
	
	while(option != 9) {
	
		printf("Enter your option : \n1 -> Inserting a record\n2 -> Search a record\n3 -> Country with lowest population density\n");
		printf("4 -> Country with highest yearly change\n");
		printf("5 -> List of countries with decreasing order of population\n");
		printf("6 -> List of countries with descending order of yearly changes\n");
		printf("7 -> List of countries in ascending order of their population densities\n");
		printf("8 -> List of countries in ascending order of their net changes\n");
		printf("9 -> Exit the menu\n\n");
		scanf("%d", &option);

		switch(option) {
			case 1:
				printf("Enter country name : ");
				scanf(" %[^\n]", countryName);
				printf("Enter population : ");
				scanf("%d", &population);
				printf("Enter yearly change : ");
				scanf("%f", &yearlyChange);
				printf("Enter net change : ");
				scanf("%d", &netChange);
				printf("Enter population density : ");
				scanf("%d", &popDensity);
				index = hash(countryName);
				bool_value = countrySearch(hashList[index], countryName);
				struct countryInfo *head = hashList[index];
				if(bool_value == 0) {
					for(int i = 0; i < 7; i++) {
						struct countryInfo *head = hashList[i];
						while(head != NULL) {
							if(head->population < population) {
								if(minRank > head->popRank) {
									minRank = head->popRank;
								}
								head->popRank = head->popRank + 1;
							}
							head = head->next;
						}

					}
					A[Aindex].popRank = minRank;
					strcpy(A[Aindex].countryName, countryName);
					A[Aindex].population = population;
					A[Aindex].yearlyChange = yearlyChange;
					A[Aindex].netChange = netChange;
					A[Aindex].popDensity = popDensity;
					Aindex++;
					for(int i = 0; i < Aindex; i++) {
						for(int j = 0; j < Aindex - i - 1; j++) {
							if(A[j].population < A[j+1].population) {
								struct sortCountry temp = A[j];
								A[j] = A[j+1];
								A[j+1] = temp;
							}
						}
					}
					for(int i = 0; i < Aindex; i++) {
						A[i].popRank = i + 1;
					}
					hashList[index] = insertCountryList(&hashList[index], minRank, countryName, population, yearlyChange, netChange, popDensity);
				} 
				break;

			case 2:
				printf("Enter country name to be searched : ");
				scanf(" %[^\n]", countryName);
				index = hash(countryName);
				printf("%d\n", index);
				bool_value = countrySearch(hashList[index], countryName);
				if(bool_value == 0) {
					printf("\nThe record for %s is not found\n\n", countryName);
				}
				break;
				
			case 3:
				
				strcpy(lowestPopDensCountry, hashList[0]->countryName);
				for(int i = 0; i < 7; i++) {
					struct countryInfo *head = hashList[i];
					while(head != NULL) {
						if(head->popDensity < lowestPopulationDensity) {
							lowestPopulationDensity = head->popDensity;
							strcpy(lowestPopDensCountry, head->countryName);
						}
						head = head->next;
					}
				}
				printf("The country with lowest population density : %s\n\n", lowestPopDensCountry);
				break;
				
			case 4:
				strcpy(highestYearlyChangeCountry, hashList[0]->countryName);
				for(int i = 0; i < 7; i++) {
					struct countryInfo *head = hashList[i];
					while(head != NULL) {
						if(head->yearlyChange > highestYearlyChange) {
							highestYearlyChange = head->yearlyChange;
							strcpy(highestYearlyChangeCountry, head->countryName);
						}
						head = head->next;
					}
				}
				printf("The country with highest yearly change : %s\n\n", highestYearlyChangeCountry);
				break;

			case 5:
				for(int i = 0; i < Aindex; i++) {
					for(int j = 0; j < Aindex - i - 1; j++) {
						if(A[j].population < A[j+1].population) {
							struct sortCountry temp = A[j];
							A[j] = A[j+1];
							A[j+1] = temp;
						}
					}
				}
				printf("The sorted list of countries in descending order of their population : \n\n");
				for(int i = 0; i < Aindex; i++) {
					printf("Population rank : %d\n", A[i].popRank);
					printf("Country name : %s\n", A[i].countryName);
					printf("Population : %d\n", A[i].population);
					printf("Yearly change : %4.2f\n", A[i].yearlyChange);
					printf("Net change : %d\n", A[i].netChange);
					printf("Population density : %d\n\n", A[i].popDensity);
				}
				break;

			case 6:
				for(int i = 0; i < Aindex; i++) {
					for(int j = 0; j < Aindex - i - 1; j++) {
						if(A[j].yearlyChange < A[j+1].yearlyChange) {
							struct sortCountry temp = A[j];
							A[j] = A[j+1];
							A[j+1] = temp;
						}
					}
				}
				printf("The sorted list of countries in descending order of yearly changes : \n\n");
				for(int i = 0; i < Aindex; i++) {
					printf("Population rank : %d\n", A[i].popRank);
					printf("Country name : %s\n", A[i].countryName);
					printf("Population : %d\n", A[i].population);
					printf("Yearly change : %4.2f\n", A[i].yearlyChange);
					printf("Net change : %d\n", A[i].netChange);
					printf("Population density : %d\n\n", A[i].popDensity);
				}
				break;

			case 7:
				for(int i = 0; i < Aindex; i++) {
					for(int j = 0; j < Aindex - i - 1; j++) {
						if(A[j].popDensity > A[j+1].popDensity) {
							struct sortCountry temp = A[j];
							A[j] = A[j+1];
							A[j+1] = temp;
						}
					}
				}
				printf("The sorted list of countries in ascending order of their population densities : \n\n");
				for(int i = 0; i < Aindex; i++) {
					printf("Population rank : %d\n", A[i].popRank);
					printf("Country name : %s\n", A[i].countryName);
					printf("Population : %d\n", A[i].population);
					printf("Yearly change : %4.2f\n", A[i].yearlyChange);
					printf("Net change : %d\n", A[i].netChange);
					printf("Population density : %d\n\n", A[i].popDensity);
				}
				break;

			case 8:
				for(int i = 0; i < Aindex; i++) {
					for(int j = 0; j < Aindex - i - 1; j++) {
						if(A[j].netChange > A[j+1].netChange) {
							struct sortCountry temp = A[j];
							A[j] = A[j+1];
							A[j+1] = temp;
						}
					}
				}
				printf("The sorted list of countries in ascending order of their net changes : \n\n");
				for(int i = 0; i < Aindex; i++) {
					printf("Population rank : %d\n", A[i].popRank);
					printf("Country name : %s\n", A[i].countryName);
					printf("Population : %d\n", A[i].population);
					printf("Yearly change : %4.2f\n", A[i].yearlyChange);
					printf("Net change : %d\n", A[i].netChange);
					printf("Population density : %d\n\n", A[i].popDensity);
				}
				break;

			case 9:
				printf("Thank you\n\n");
				fclose(fp);
				return 0;
		}
	}
}
