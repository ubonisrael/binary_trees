#include "binary_trees.h"

/**
  * binary_tree_postorder - goes through binary tree using post-order traversal
  * @tree: pointer to the root node of the tree
  * @func: pointer to a function to call for each node. The value in the node
  * must be passed to this function.
  * Return: void
  */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);
	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);
	func(tree->n);
}
