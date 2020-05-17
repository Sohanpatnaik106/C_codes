#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node next;
}

struct node *create_list(struct node **head, int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	if((*head) == NULL)
	{
		(*head) = node;
		node->data = data;
		node->next = NULL;
	}

	return *head;
}

void insert(struct node **head, int data)
{
	if((*head) == NULL)
		(*head) = create_list(&head, data);
	
	else
	{
		struct node *node = (struct node *)malloc(sizeof(struct node));
		node->data = data;
		node->next = (*head);
		(*head) = node;
	}

}

void traverse(struct node *head)
{
	while(head != NULL)
	{
		printf("%d", head->data)
		head = head->next;
	}
}

int main()
{
	
	
}
