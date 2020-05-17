#include<stdio.h>
#include<stdlib.h>

typedef struct _node 
{
	int x;
	int y;
	struct _node *nextx;
	struct _node *nexty; 
}node;

FILE *fp;
node *head = NULL, *tail = NULL;

void insert_point(int x, int y, node **head, node **tail) {
	node *point = (node *)malloc(sizeof(node));
	point->nextx = NULL;
	point->nexty = NULL;
	point->x = x;
	point->y = y;

	if((*head) == NULL) {
		(*head) = point;
		(*tail) = point;
	}
	else {
		(*tail)->nextx = point;
		(*tail)->nexty = point;
		(*tail) = point;
	}
}

void printlistX(node *head) {
	int i = 1;
	while(head != NULL) {
		printf("%d ", head->x);
		head = head->nextx;
		i++;
	}
}

void printlistY(node *head) {
	int i = 1;
	while(head != NULL) {
		printf("%d ", head->y);
		head = head->nexty;
		i++;
	}
}

void bubbleSortX(node **head) {
	node *p1, *p2, *p3;
	p1 = *head;
	p2 = *head;
	p3 = (*head)->nextx;

	int n = 50;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(p2->x > p3->x) {
				if(p1 == p2) {
					p2->nextx = p3->nextx;
					p3->nextx = (*head);
					(*head) = p3;
					p3 = p2;
					p2 = p1;
				}
				else {
					p2->nextx = p3->nextx;
					p3->nextx = p1->nextx;
					p1->nextx = p3;
					p3 = p2;
					p2 = p1->nextx;
				}
			}
			if(p1 == p2) {
				p2 = p2->nextx;
				p3 = p3->nextx;
			}
			else {
				p1 = p1->nextx;
				p2 = p2->nextx;
				p3 = p3->nextx;
			}
		}
		p1 = (*head);
		p2 = (*head);
		p3 = (*head)->nextx;
	}
}

void bubbleSortY(node **head) {
	node *p1, *p2, *p3;
	p1 = *head;
	p2 = *head;
	p3 = (*head)->nexty;

	int n = 50;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n-i-1; j++) {
			if(p2->y > p3->y) {
				if(p1 == p2) {
					p2->nexty = p3->nexty;
					p3->nexty = (*head);
					(*head) = p3;
					p3 = p2;
					p2 = p1;
				}
				else {
					p2->nexty = p3->nexty;
					p3->nexty = p1->nexty;
					p1->nexty = p3;
					p3 = p2;
					p2 = p1->nexty;
				}
			}
			if(p1 == p2) {
				p2 = p2->nexty;
				p3 = p3->nexty;
			}
			else {
				p1 = p1->nexty;
				p2 = p2->nexty;
				p3 = p3->nexty;
			}
		}
		p1 = (*head);
		p2 = (*head);
		p3 = (*head)->nexty;
	}
}

int main() {
	fp = fopen("points.txt", "r");
	int x, y;
	node *head = NULL, *tail = NULL;
	while(!feof(fp)) {
		fscanf(fp, "%d %d", &x, &y);
		insert_point(x, y, &head, &tail);
	}
	node *head_temp = head;
	printf("The sorted list according to x coordinates is : ");
	bubbleSortX(&head);
	printlistX(head);

	head = head_temp;
	
	printf("\nThe sorted list according to y coordinates is : ");
	bubbleSortY(&head);
	printlistY(head);
	printf("\n");

}