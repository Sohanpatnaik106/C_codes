#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node *new_node(int item)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}	
}

struct node *insert(struct node *node, int key)
{
	if(node == NULL)
		return new_node(key);
	else if(key < node->key)
		node->left = insert(node->left, key);
	else if(key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct node *min_value_node(struct node *node)
{
	struct node *current = node;
	while(current && current->left != NULL)
		current = current->left;

	return current;
}

struct node *delete_node(struct node *root, int key)
{
	if(root == NULL)
		return root;
	
	if(key < root->key)
		root->left = delete_node(root->left, key);
	else if(key > root->key)
		root->right = delete_node(root->right, key);
	else
	{
		if(root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
	}

	struct node *temp = min_value_node(root->right);
	root->key = temp->key;
	root->right = delete_node(root->right, temp->key);
} 

int main()
{
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	inorder(root);
	printf("\n");

	root = delete_node(root, 20);
	inorder(root);
	printf("\n");

	return 0;;
}	
