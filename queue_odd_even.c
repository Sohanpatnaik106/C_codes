#include<stdio.h>
#include<stdlib.h>

struct queue {
	int value;
	struct queue *next;
};

void enqueue(struct queue **front, struct queue **rear, int value) {
	struct queue *node = (struct queue *)malloc(sizeof(struct queue));
	node->value = value;
	node->next = NULL;

	if((*front) == NULL) {
		(*front) = (*rear) = node;
	}
	else {
		(*rear)->next = node;
		(*rear) = (*rear)->next;
	}
}

int dequeue(struct queue **front) {
	int value = (*front)->value;
	struct queue *temp = (*front);
	(*front) = (*front)->next;
	free(temp);
	return value;
}

void printQueue(struct queue **front) {
	while((*front) != NULL) {
		printf("%d ", dequeue(front));
	}
	printf("\n");
}

int main() {
	struct queue *evenFront = NULL, *oddFront = NULL, *evenRear = NULL, *oddRear = NULL; 
	int value;
	printf("Enter the value, 0 to stop insertion : ");
	scanf("%d", &value);
	if(value == 0) {
		printf("Both the queues are empty\n");
		return 0;
	}
	while(value != 0) {
		if(value % 2 == 0) {
			enqueue(&evenFront, &evenRear, value);
		}
		else{
			enqueue(&oddFront, &oddRear, value);
		}
		printf("Enter the value, 0 to stop insertion : ");
		scanf("%d", &value);
	}

	if(oddFront != NULL) {
		printf("The queue containing the odd numbers : ");
		printQueue(&oddFront);
	}
	else {
		printf("The odd queue is empty\n");
	}
	
	if(evenFront != NULL) {
		printf("The queue containing the even numbers : ");
		printQueue(&evenFront);
	}
	else {
		printf("The even queue is empty\n");
	}
	
	return 0;
}