#include "algorithms.h"

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
	//TODO:	 BFS - done with a queue DS to store nodes visited but not processed
}
