#include "algorithms.h"

// TREE UTILS
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

// LINEARIZATION = TREE TRAVERSAL ALGORITHMS

// 1. depth-first traversal

// pre-order traversal
void preorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("-");
		return ;
	}
	printf("%d ", root->value);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

// in-order traversal
void inorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("-");
		return ;
	}
	inorder_traversal(root->left);
	printf("%d ", root->value);
	inorder_traversal(root->right);
}

// post-order traversal
void postorder_traversal(treenode *root)
{
	if (root == NULL)
	{
		printf("-");
		return ;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d ", root->value);
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

int main(void)
{
	treenode *n1 = create_node(1); //             1
	treenode *n2 = create_node(2); //         2       3
	treenode *n3 = create_node(3); //       4  x     5  6
	treenode *n4 = create_node(4); // breadth-first: 123456
	treenode *n5 = create_node(5); // depth-first: preorder: 124356, inorder: 421536, postorder: 425631
	treenode *n6 = create_node(6);
	n1->left = n2; //n1 is root because it is not a left nor right child of any node
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	breadth_first_traversal(n1);
}
