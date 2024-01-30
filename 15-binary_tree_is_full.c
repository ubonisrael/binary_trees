#include "binary_trees.h"

/**
  * binary_tree_is_full - a function that checks if a binary tree is full
  * @tree: pointer to the root node of the tree
  * Return: 0, If tree is NULL.
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_val, r_val;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if ((tree->left && tree->right))
	{
		l_val = binary_tree_is_full(tree->left);
		if (l_val)
			r_val = binary_tree_is_full(tree->right);
		return (l_val && r_val);
	}
	return (0);
}
