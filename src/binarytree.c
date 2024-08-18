#include "algorithms.h"

// UTILS
treenode *create_node(int value)
{
	treenode *node = malloc(sizeof(treenode));
	if (node)
	{
		node->left = NULL; // set left child initially to NULL
		node->right = NULL; // set right child initially to NULL
		node->value = value; //set value to our node to value passed
	}
	return (node);
}

treenode *fill_tree(void)
{
	treenode *root = create_node(1); //           1
	treenode *n2 = create_node(2); //         2       3
	treenode *n3 = create_node(3); //       4  x     5  6
	treenode *n4 = create_node(4); // breadth-first: 123456
	treenode *n5 = create_node(5); // depth-first: preorder: 124356, inorder: 421536, postorder: 425631
	treenode *n6 = create_node(6);
	root->left = n2; //this is root because it is not a left nor right child of any node
	root->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	return (root);
}

void free_tree(treenode *root)
{
	if (root == NULL)
	{
		free(root);
		return ;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

// LINEARIZATION = TREE TRAVERSAL ALGORITHMS

// 1. depth-first traversal

// pre-order traversal
void preorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("x");
		return ;
	}
	/* 1 */printf("%d ", root->value); // do the action you want to do with each node here in first step
	/* 2 */preorder_traversal(root->left);
	/* 3 */preorder_traversal(root->right);
}

// in-order traversal
void inorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("x");
		return ;
	}
	/* 1 */inorder_traversal(root->left);
	/* 2 */printf("%d ", root->value); // do the action you want to do with each node here in second step
	/* 3 */inorder_traversal(root->right);
}

// post-order traversal
void postorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("x");
		return ;
	}
	/* 1 */postorder_traversal(root->left);
	/* 2 */postorder_traversal(root->right);
	/* 3 */printf("%d ", root->value); // do the action you want to do with each node here in third step
}

// 2. breadth-first traversal
void breadth_first_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("-");
		return ;
	}
	printf("%d ", root->value);
	//TODO:	 BFS - done through a queue
}

// EXAMPLE BASIC PROGRAM

// int main(void)
// {
// 	treenode *root = fill_tree();
// 	inorder_traversal(root);
// 	free_tree(root);
// }
