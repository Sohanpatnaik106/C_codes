#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct complex {
	float x;
	float y;
	struct complex *next;
};

void insert(struct complex **head, float x, float y) {
	struct complex *node = (struct complex *)malloc(sizeof(struct complex));
	node->x = x;
	node->y = y;
	node->next = NULL;
	float z = pow(x, 2) + pow(y, 2);

	struct complex *traverse = (*head);
	while(traverse != NULL) {
		if(x == traverse->x && y == traverse->y) {
			return;
		}
		traverse = traverse->next;
	}

	if((*head) == NULL) {
		(*head) = node;
	}
	else if((*head)->next == NULL) {
		float z1 = pow((*head)->x, 2) + pow((*head)->y, 2);
		if(z <= z1) {
			node->next = (*head);
			(*head) = node;
		}
		else {
			(*head)->next = node;
		}
	}
	else {
		struct complex *temp = (*head);
		while(temp->next != NULL) {
			float z1 = pow(temp->x,2) + pow(temp->y, 2);
			float z2 = pow(temp->next->x, 2) + pow(temp->next->y, 2);
			if(z >= z1 && z <= z2) {
				node->next = temp->next;
				temp->next = node;
				break;
			}
			else {
				temp = temp->next;
			}	
	    }
	    if(temp->next == NULL) {
	    	temp->next = node;
	    }
	}
}

void display(struct complex *head) {
	printf("The complex numbers with modulus same as the first complex number : \n");
	float z = pow(head->x, 2) + pow(head->y, 2);
	while(head != NULL) {
		float z1 = pow(head->x, 2) + pow(head->y, 2);
		if(z1 == z) {
			printf("%4.2f+%4.2fi, ", head->x, head->y);
		}
		head = head->next;
	}
	printf("\n");
}	

int main() {
	float x, y;
	struct complex *head = NULL;

	printf("Enter the complex numbers (real and imaginary for each) :\n");
	scanf("%f %f", &x, &y);
	float firstX = x;
	float firstY = y;

	while(x != 0 && y != 0) {
		insert(&head, x, y);
		scanf("%f %f", &x, &y);
	}

	if(firstX != 0 && firstY != 0) {
		display(head);
	}
	else {
		printf("No data in the list\n");
	}

	return 0;
}