#include<stdio.h>

struct element
{
	char symbol;
	int atm_no, atm_wt;
};

struct compound
{
	int n;	
	struct element ele[10];
	int atm_cnt[10];
};

int main()
{
	struct element atom_1, atom_2, atom_3, atom_4;
	struct compound molecule_1, molecule_2, molecule_3, molecule_4;

	printf("\n");

	printf("\n____ Details of first atom ____\n");
	printf("Enter the symbol : ");
	scanf("%c", &atom_1.symbol);
	printf("Enter the atomic number : ");
	scanf("%d", &atom_1.atm_no);
	printf("Enter the atomic weight : ");
	scanf("%d", &atom_1.atm_wt);

	printf("\n____ Details of second atom ____\n");
	printf("Enter the symbol : ");
	scanf("%c", &atom_2.symbol);
	printf("Enter the atomic number : ");
	scanf("%d", &atom_2.atm_no);
	printf("Enter the atomic weight : ");
	scanf("%d", &atom_2.atm_wt);

	printf("\n____ Details of third atom ____\n");
	printf("Enter the symbol : ");
	scanf("%c", &atom_3.symbol);
	printf("Enter the atomic number : ");
	scanf("%d", &atom_3.atm_no);
	printf("Enter the atomic weight : ");
	scanf("%d", &atom_3.atm_wt);

	printf("\n____ Details of fourth atom ____\n");
	printf("Enter the symbol : ");
	scanf("%c", &atom_4.symbol);
	printf("Enter the atomic number : ");
	scanf("%d", &atom_4.atm_no);
	printf("Enter the atomic weight : ");
	scanf("%d", &atom_4.atm_wt);

	printf("\n");

	printf("\n____Details of first molecule____");
	printf("Enter the number of elements in the molecule : ");
	scanf("%d", &molecule_1.n);
	printf("Enter the ")
	for(int i = 0; i < molecule_1.n; i++)
	{
		scanf("")
	}	

	printf("The molecular weight of first molecule is : %d", molecular_wt(molecule_1));
	printf("The molecular weight of second molecule is : %d", molecular_wt(molecule_1));
	printf("The molecular weight of third molecule is : %d", molecular_wt(molecule_1));
	printf("The molecular weight of fourth molecule is : %d", molecular_wt(molecule_1));
	
	printf("Enter the reactant molecules involved in the reaction : ");
	
}
