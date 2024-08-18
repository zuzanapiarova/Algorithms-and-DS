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

// EXAMPLE BASIC PROGRAM

// int main(void)
// {
// 	treenode *root = fill_tree();
// 	inorder_traversal(root);
// 	free_tree(root);
// }
