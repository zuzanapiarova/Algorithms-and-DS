#include "algorithms.h"

int main(void)
{
	treenode *root = fill_tree();
	inorder_traversal(root);
	free_tree(root);
}
